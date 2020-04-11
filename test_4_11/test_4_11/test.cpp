#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
using namespace std;
/*
  给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，
  那么整个数组都会变为升序排序。

  你找到的子数组应是最短的，请输出它的长度。

  输入: [2, 6, 4, 8, 10, 9, 15]
  输出: 5
  解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

*/

// 思路 对数组进行排序，设置双指针，一个从头 一个从尾，
int findUnsortedSubarray(vector<int>& nums) {
	vector<int> vt(nums.begin(), nums.end());
	sort(vt.begin(), vt.end());
	int start = 0, end = nums.size() - 1; //设置双指针
	while (start < end)
	{
		int flag = 1;
		if (vt[start] == nums[start])
		{
			start++;
			flag = 0;
		}
		if (vt[end] == nums[end])
		{
			end--;
			flag = 0;
		}
		if (flag == 1)  // 不相等
			break;
	}
	return end - start > 0 ? end - start + 1 : 0;
}

/*
  根据逆波兰表示法，求表达式的值。

  有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

  说明：
	 整数除法只保留整数部分。
	 给定逆波兰表达式总是有效的。
	 换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。
*/
int evalRPN(vector<string>& tokens) {
	stack<int>  temp;
	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i].size() == 1 && (tokens[i][0] == '+' || tokens[i][0] == '-' || tokens[i][0] == '*' || tokens[i][0] == '/'))
		{
			int temp1 = temp.top();
			temp.pop();
			int temp2 = temp.top();
			temp.pop();
			//cout<<"temp1:"<<temp1<<'.'<<"temp2:"<<temp2<<endl;
			if (tokens[i][0] == '+')
				temp.push(temp1 + temp2);
			else if (tokens[i][0] == '-')
				temp.push(temp2 - temp1);
			else if (tokens[i][0] == '*')
				temp.push(temp1*temp2);
			else
				temp.push(temp2 / temp1);
		}
		else
		{
			temp.push(atoi(tokens[i].c_str()));
		}

	}
	return temp.top();
}

/*
   给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

   回溯
*/
vector<vector<int>> res;
int len;
void dfs(vector<int>& nums, int flag, vector<int> nums_1) {
	if (flag == len) return;
	nums_1.push_back(nums[flag]);
	res.push_back(nums_1);
	dfs(nums, flag + 1, nums_1);
	nums_1.pop_back();
	dfs(nums, flag + 1, nums_1);
}
vector<vector<int>> subsets(vector<int>& nums) {
	vector<int> null_1;
	len = nums.size();
	vector<int> nums_1;
	dfs(nums, 0, nums_1);
	res.push_back(null_1);
	return res;
}
/*给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，
返回从右侧所能看到的节点值。

//层序遍历
*/
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;
vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	if (root == nullptr)
		return res;

	queue<TreeNode* > qu;
	qu.push(root);
	int counter = 1;
	while (!qu.empty())
	{
		int tmp = 0;
		while (counter != 0)
		{
			TreeNode* top = qu.front();
			qu.pop();
			counter--;
			if (counter == 0)
				res.push_back(top->val);
			if (top->left != nullptr)
			{
				qu.push(top->left);
				tmp++;
			}
			if (top->right != nullptr)
			{
				qu.push(top->right);
				tmp++;
			}
		}
		counter = tmp;
	}
	return res;
}
int main()
{
	/*int ar[] = { 1,2,3,};
	vector<int> nums(ar,ar+3);
	vector<vector<int>> ret = subsets(nums);
	for (int i = 0; i < ret.size(); ++i)
	{
		for (int j = 0; j < ret[i].size(); ++j)
			cout << ret[i][j];
		cout << endl;
	}*/
	int a[] = { 2, 4, 6, 8, 10 }, *p, **k; 
	p = a; k = &p;
	printf(" % d", *(p++)); 
	printf(" % d\n", **k);
	return 0;
}