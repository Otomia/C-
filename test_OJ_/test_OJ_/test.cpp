#include<iostream>
#include<string>
using namespace std;

int find(int ar[], int n, int x)
{
	int low = 0;
	int high = n - 1;
	int mid;
	while (low <= high)
	{
		mid = low + high;
		if (x == ar[mid])
		{
			return mid;
		}
		else if (x > ar[mid])
		{
			if (x > ar[high])
				high = mid - 1;
			else
				low = mid + 1;
		}
		else if (x < ar[mid])
		{
			if (x < ar[low])
				low = mid + 1;
			else
				high = mid - 1;
		}
	}
}

int main()
{
	/*string str;

	while (cin >> str)
	{
		size_t sz = str.size();
		int count[256] = { 0 };
		for (int i = 0; i < sz; ++i)
		{
			if (count[str[i]] == 0)
				cout << str[i];
			count[str[i]]++;
		}
		cout << endl;
	}*/
	int ar[12] = {4,5,6,7,8,9,10,11,12,1,2,3 };
	int index = find(ar, 12, 3);
	cout << index << endl;;

	system("pause");
	return 0;
}