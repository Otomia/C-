// 求和
// 输入两个整数n,m，从数列1，2，3...n中随意取几个数，使其和等于m，
//将所有的可能输出

#include<iostream>
#include<vector>
using namespace std;
void fun(int n, int m, vector<int>& vt, int beg)
{
	if (m == 0)
	{
		for (int i = 0; i < vt.size(); ++i)
		{
			i == 0 ? cout << vt[i] : cout << " " << vt[i];
		}
		cout << endl;
	}
	for (int i = beg; i <= n && i <= m; ++i)
	{
		vt.push_back(i);
		fun(n, m - 1, vt, i + 1);
		vt.pop_back();
	}
}
int main()
{
	int n, m;
	n = 5, m = 5;
	vector<int> vt;
	fun(n, m, vt, 1);

	return 0;
}

//#include<iostream>
//#include<string>
//#include<set>
//
//using namespace std;
//// 电话号码
//int main()
//{
//	int n;
//	string str;
//
//	while (cin >> n)
//	{
//		    
//		set<string> st;
//
//		for (int i = 0; i < n; ++i)
//		{
//			int count = 0;
//			string s;
//			cin >> str;
//			for (int j = 0; j < str.size(); ++j)
//			{
//				if (str[j] >= 'A'&&str[j] <= 'Z') // 是大写字母
//				{
//					if (str[j] >= 'A'&&str[j] <= 'C') //ABC-->2
//						s += "2";
//					else if (str[j] >= 'D'&&str[j] <= 'F') //DEF-->3
//						s += "3";
//					else if (str[j] >= 'G'&&str[j] <= 'I') //GHI-->4
//						s += "4";
//					else if (str[j] >= 'J'&&str[j] <= 'L') //JKL-->5
//						s += "5";
//					else if (str[j] >= 'M'&&str[j] <= 'O') //MNO-->6
//						s += "6";
//					else if (str[j] >= 'P'&&str[j] <= 'S') //PQRS-->7
//						s += "7";
//					else if (str[j] >= 'T'&&str[j] <= 'V') //TUV-->8
//						s += "8";
//					else
//						s += "9";
//					count++;
//					if (count == 3)
//						s += "-";
//				}
//				else if (str[j] >= '0'&&str[j] <= '9')//数字
//				{
//					s += str[j];
//					count++;
//					if (count == 3)
//						s += "-";
//				}
//			}
//			st.insert(s);
//		}
//		for (auto &e : st)
//		{
//			cout << e << endl;
//		}	
//	}
//	return 0;
//}