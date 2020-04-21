#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 单词倒排
/*
输入
I am a student
*/
/*
输出
student a am I
*/

int main()
{
	string s;
	while (getline(cin, s))
	{
		vector<string> res;
		string tmp;
		for (int i = 0; i <s.size(); ++i)
		{
			if (s[i] != ' ')
			{
				tmp += s[i];
			}
			else
			{
				res.push_back(tmp);
				tmp = "";
			}
		}
		if (tmp.size() > 0)
		{
			res.push_back(tmp);
		}
		for (int i = res.size() - 1; i >= 0; i--)
		{
			cout << res[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//// 骆驼命名法
///*
//输入
//hello_world
//nice_to_meet_you
//*/
///*
//输出
//helloWorld
//niceToMeetYou
//*/
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		string res;
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] == '_')
//			{
//				i++;
//				res.push_back(s[i] - 32);
//			}
//			else
//				res.push_back(s[i]);
//		}
//		cout << res << endl;
//	}
//	return 0;
//}