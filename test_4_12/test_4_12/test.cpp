#include<iostream>
#include<string>

using namespace std;


// 字符串匹配  递归实现
void match(string& s, int sStart, string& p, int pStart, bool& found, bool& flag)
{
	if (s.size() != sStart && p.size() != pStart)  // s,p非空
	{
		if (p[pStart] == '?' || p[pStart] == s[sStart])
		{
			match(s, sStart + 1, p, pStart + 1, found, flag);
			if (found)
				return;
		}
		else if (p[pStart] == '*') //p中出现 *
		{
			match(s, sStart, p, pStart + 1, found, flag); //匹配 空字符
			if (found)
				return;
			match(s, sStart + 1, p, pStart, found, flag); // 匹配一个或多个字符，保留*来实现
			if (found)
				return;
		}
	}
	else if (s.size() == sStart)  //s字符串为空 一定能判断匹配与否
	{
		while (pStart < p.size() && p[pStart] == '*')
			++pStart;
		if (pStart == p.size())
		{
			found = true;
			flag = true;
		}
		else
		{
			found = true;
			flag = false;
		}
	}
}
bool isMatch(string s, string p)
{
	int sStart = 0, pStart = 0; // sStart是字符串起始，pStart是模式串起始
	bool flag = false; // 结果
	bool found = false; //找到后使递归返回
	match(s, sStart, p, pStart, found, flag);
	return flag;
}



int main()
{
	string a, b;
	while (cin >> a >> b)
	{

	}
	return 0;
}