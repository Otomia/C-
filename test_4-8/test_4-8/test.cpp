#include<iostream>
#include<algorithm> 
using namespace std;

// 养兔子

int main()
{
	int n;
	while (cin >> n)
	{
		int sum = 0;
		int ar[91] = { 1,2 };
		for (int i = 2; i < 92; i++)
			ar[i] = ar[i - 1] + ar[i - 2];
		sum = ar[n-1];
		cout << sum << endl;
	}
	return 0;
}

// 收件人列表
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		vector<string> vt(n+1);
//		
//		for (int i = 0; i <= n; ++i)
//		{
//			getline(cin, vt[i]);
//		}
//		for (int i = 1; i <= n; ++i)
//		{
//			if (vt[i].find(' ')!=string::npos || vt[i].find(',')!=string::npos)
//			{
//				cout << "\"" << vt[i] << "\"";
//			}
//			else
//				cout << vt[i];
//			if (i < n)
//				cout << ",";
//			
//		}
//		cout << endl;
//	}
//	return 0;
//}

// 客似云来
//int main()
//{
//	int from, to;
//	while (cin >> from >> to)
//	{
//		float sum = 0;
//		double ar[82];
//		ar[0] = 1;
//		ar[1] = 1;
//		for (int i = 2; i < 82; ++i)
//			ar[i] = ar[i - 1] + ar[i - 2];
//		sum = ar[to + 1] - ar[from];
//		cout << sum << endl;
//	}
//	return 0;
//}

// 剪花布条
//int main()
//{
//	string s, t;
//	while (cin>>s>>t)
//	{
//		int count = 0;
//		for (size_t i = 0; i < s.size(); i += t.size())  // 跳过t串大小
//		{
//			size_t pos = s.find(t, i);
//			if (pos != string::npos)  // 在s串中查找t串
//			{
//				count++;
//				i = pos;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}
//int main()
//{
//	string str;
//	
//	while (cin>>str)
//	{
//		map<string, int> count;
//		if (str[str.size() - 1] == '.' || str[str.size() - 1] == ',')
//		{
//			str.erase(str.end() - 1);
//		}
//		if (str[0] >= 'A'&&str[0] <= 'Z')
//			str[0] += 32;	
//		count[str]++;
//		for (auto it = count.begin(); it != count.end(); ++it)
//		{
//			cout << it->first << ":" << it->second << endl;
//		}
//	}	
//	return 0;
//}