#include<iostream>
#include<vector>
using namespace std;

//最长上升子序列
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> Hei(n);
		for (int i = 0; i < n; ++i)
			cin >> Hei[i];
		int count = 0, max = 0;
		int tmp = Hei[0], tmp1 = 0;
		int index = 0;
		for (int i = 0; i < n; i++)
		{
			if (i < n - 1 && tmp < Hei[i])
			{
				count++;
				tmp = Hei[i];
				index = i;
			}
			else
			{
				count --;
				tmp = Hei[0];
				//tmp1=Hei[]
			}
			if (count > max)
				max = count;
		}
		cout << max+1  << endl;
	}
	return 0;
}