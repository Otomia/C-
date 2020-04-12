#include<iostream>
#include<string>

using namespace std;


// �ַ���ƥ��  �ݹ�ʵ��
void match(string& s, int sStart, string& p, int pStart, bool& found, bool& flag)
{
	if (s.size() != sStart && p.size() != pStart)  // s,p�ǿ�
	{
		if (p[pStart] == '?' || p[pStart] == s[sStart])
		{
			match(s, sStart + 1, p, pStart + 1, found, flag);
			if (found)
				return;
		}
		else if (p[pStart] == '*') //p�г��� *
		{
			match(s, sStart, p, pStart + 1, found, flag); //ƥ�� ���ַ�
			if (found)
				return;
			match(s, sStart + 1, p, pStart, found, flag); // ƥ��һ�������ַ�������*��ʵ��
			if (found)
				return;
		}
	}
	else if (s.size() == sStart)  //s�ַ���Ϊ�� һ�����ж�ƥ�����
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
	int sStart = 0, pStart = 0; // sStart���ַ�����ʼ��pStart��ģʽ����ʼ
	bool flag = false; // ���
	bool found = false; //�ҵ���ʹ�ݹ鷵��
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