#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<string>
#include<queue>
using namespace std;
/*
  ����һ���������飬����ҪѰ��һ�������������飬�������������������������
  ��ô�������鶼���Ϊ��������

  ���ҵ���������Ӧ����̵ģ���������ĳ��ȡ�

  ����: [2, 6, 4, 8, 10, 9, 15]
  ���: 5
  ����: ��ֻ��Ҫ�� [6, 4, 8, 10, 9] ��������������ô���������Ϊ��������

*/

// ˼· �����������������˫ָ�룬һ����ͷ һ����β��
int findUnsortedSubarray(vector<int>& nums) {
	vector<int> vt(nums.begin(), nums.end());
	sort(vt.begin(), vt.end());
	int start = 0, end = nums.size() - 1; //����˫ָ��
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
		if (flag == 1)  // �����
			break;
	}
	return end - start > 0 ? end - start + 1 : 0;
}

/*
  �����沨����ʾ��������ʽ��ֵ��

  ��Ч����������� +, -, *, / ��ÿ��������������������Ҳ��������һ���沨�����ʽ��

  ˵����
	 ��������ֻ�����������֡�
	 �����沨�����ʽ������Ч�ġ�
	 ���仰˵�����ʽ�ܻ�ó���Ч��ֵ�Ҳ����ڳ���Ϊ 0 �������
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
   ����һ�鲻���ظ�Ԫ�ص��������� nums�����ظ��������п��ܵ��Ӽ����ݼ�����

   ����
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
/*����һ�ö������������Լ�վ�������Ҳ࣬���մӶ������ײ���˳��
���ش��Ҳ����ܿ����Ľڵ�ֵ��

//�������
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