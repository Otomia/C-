#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 数组中出现次数超过一半的数字
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int len = numbers.size();
		sort(numbers.begin(), numbers.end());
		int count = 1;
		int res = numbers[0];
		for (int i = 0; i < len; ++i)
		{
			if (count == 0)
			{
				res = numbers[i];
				count = 1;
			}
			else if (numbers[i] == res)
				++count;
			else
				--count;
		}
		count = 0;
		for (int i = 0; i < len; ++i)
		{
			if (numbers[i] == res)
				count++;
		}
		if (count > len / 2)
			return res;
		return 0;
	}
};


int main()
{
	int ar[] = { 1,2,3,2,2,2,4,2 };
	vector<int> num;
	for (int i = 0; i < 7; ++i)
		num.push_back(ar[i]);
	int ret = num[0];
	int times = 1;
	for (int i = 1; i < num.size(); ++i)
	{
		
	}
	//if (times > num.size() / 2)
	
}
int main()
{
	Solution s;
	int ar[] = { 1,2,3,2,2,2,5,4,2 };
	vector<int> vt(ar,ar+9);
	int ret = s.MoreThanHalfNum_Solution(vt);
	cout << ret << endl;
	return 0;
}