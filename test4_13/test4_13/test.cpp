#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
// mkdir

bool isZiChuan(string s1, string s2)
{
	if (s2.find(s1) != string::npos)
		return true;
	else
		return false;
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> vt(n);
		for (int i = 0; i < n; ++i)
			cin >> vt[i];
		sort(vt.begin(), vt.end());
		vector<string> s(n);
		s = vt;
		for (int i = 0; i < n; ++i)
		{
			if (i < n -1 && isZiChuan(vt[i], vt[i + 1]))
			{
				vector<string>::iterator it = find(s.begin(), s.end(), vt[i]);
				s.erase(it);
			}
		}
		for (auto &e : s)
			cout << "mkdir -p " << e << endl;
		cout << endl;
	}
	return 0;
}

//  数据库连接池
/*int main()
{
	int n;
	while (cin >> n)
	{
		vector <vector<string>> vt(n);
		for (int i = 0; i < n; i++)
			vt[i].resize(2);
		for (int i = 0; i < n; ++i)
		{
			cin >> vt[i][0] >> vt[i][1];
		}
		queue<string> Q;
		int count = 0;
		for (int i = 0; i < n; ++i)
		{
			if (vt[i][1] == "connect")
			{
				Q.push(vt[i][1]);
			}
			else if(vt[i][1]=="disconnect")
			{
				int tmp = Q.size();
				if (tmp > count)
					count = tmp;
				Q.pop();
			}
		}
		cout << count << endl;
	}
	return 0;
}   */            