#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

// Emacs ¼ÆËãÆ÷
int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> vt(n);
		for (int i = 0; i < n; ++i)
			cin >> vt[i];
		stack<int> num;
		for (int i = 0; i < n; ++i)
		{
			if (vt[i][0] >= '0' && vt[i][0] <= '9')
				num.push(vt[i][0] - '0');
			else
			{
				int a = num.top();
				num.pop();
				int b = num.top();
				num.pop();
				if (vt[i][0] == '+')
				{
					num.push(a+b);
				}
				else if (vt[i][0] == '-')
				{
					num.push(a - b);
				}
				else if (vt[i][0] == '*')
				{
					num.push(a * b);
				}
				else if (vt[i][0] == '/')
				{
					if (a / b == 0)
						num.push(1);
					else
						num.push(a / b);
				}
			}

		}
		cout << num.top() << endl;
	}
	return 0;
}