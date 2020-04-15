#include<iostream>
#include<string>
#include<set>

using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int count = 0;
		//去重
		set<char> st1(s1.begin(), s1.end());
		set<char> st2(s2.begin(), s2.end());
		// 赋值给string
		s1.assign(st1.begin(), st1.end());
		s2.assign(st2.begin(), st2.end());
		if (s1.size() < s2.size())
			swap(s1, s2);
		for (size_t i = 0; i < s2.size(); ++i)
		{
			if (s1.find(s2[i]) != string::npos)
				count++;
		}
		cout << count << endl;
	}
	return 0;
}