#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<int> dq;
	deque<int> dq1(10, 4);

	int ar[] = { 1,2,3,4,5,6,7,8 };
	int n = sizeof(ar) / sizeof(int);
	deque<int> dq2(ar, ar + n);

	deque<int> dq3(dq1);

	deque<int>::iterator it = dq3.begin();
	while (it != dq3.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	deque<int>::reverse_iterator rit = dq2.rbegin();
	while (rit != dq2.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	cout << "dq1 size:" << dq1.size() << endl;
	cout << "dq empty:" << dq.empty() << endl;

	dq.resize(7, 3);
	cout << "dq size:" << dq.size() << endl;

	for (int i = 0; i < dq2.size(); ++i)
	{
		cout << dq2[i]<<" ";
	}
	cout << endl;
	system("pause");
	return 0;
}

