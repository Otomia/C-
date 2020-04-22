#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string A, B;
	while (cin >> A >> B)
	{
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		int countA = 0, countB = 0;
		int cnt = 0;
		for (int i = 0; i < B.size(); ++i)
		{
			countA = count(A.begin(), A.end(), B[i]);
			countB = count(B.begin(), B.end(), B[i]);
			if (countB > countA)
			{
				cout << "No" << endl;
				break;
			}
			i += countB - 1;
			cnt = i;
		}
		//if(cnt==B.size())
		cout << "Yes" << endl;
	}
	return 0;
}