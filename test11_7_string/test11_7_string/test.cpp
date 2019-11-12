#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>

using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(const String& s)  //�������캯��
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s) //���� = �����
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}
	~String() //��������
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:
	char* _str;
};


int main()
{
	String str1("hello");
	String str2("ddd");
	str1 = str2;

	system("pause");
	return 0;

}

/*
class String
{
public:
	String(const char* str = "")  //���캯��
	{
		//����string����ʱ���������nullptrָ�룬��Ϊ����Ƿ����˴�������
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
	}

	String(const String& s)  //�������캯��
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s) //���� = �����
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}

	~String() //��������
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}
private:
	char* _str;
};


/*
int main()
{
	string str;
	str.push_back(' ');//��str�������һ���ո�
	str.append("hello"); // ��str����׷��һ���ַ���hello��
	str += 'b';   // ��str��׷��һ���ַ���b��
	str += "it";  // ��str׷��һ���ַ���"it"

	cout << str << endl;
	cout << str.c_str() << endl; //��c���Է�ʽ��ӡ�ַ���

	//��ȡfile�ĺ�׺
	string file1("test.cpp");
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;


	//npos ��string�����һ����̬��Ա����
	//static const size_t npos = 1;
	
	//ȡ��url�е�����
	string url("http://www.cplusplus.com/reference/string/string/find");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;
		return -1;
	}
	start += 3;
	size_t finish = url.find('/', start);
	string address = url.substr(start, finish - start);
	cout << address << endl;
	

	//ɾ��url��Э��ǰ׺
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
	system("pause");
	return 0;
}


/*
// ������ʼ�����
int main()
{
	string s1("Hello world");
	const string s2("Hello Bit");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'h';
	cout << s1 << endl;

	string s("hello bit");
	// 3�ֱ�����ʽ
	// ��Ҫע����������ַ�ʽ���˱���string����
	// �����Ա������޸�string�е��ַ���
	// �����������ַ�ʽ����string���ԣ���һ��ʹ�����
	// 1.for+operator[]
	for (size_t i = 0; i < s.size(); ++i)
		cout << s[i];
	cout << endl;
	
	// 2.iterator
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit;
		++rit;
	}
	cout << endl;

	// 3.��Χfor
	for (auto e : s)
	{
		cout << e ;
	}
	cout << endl;

	system("pause");
	return 0;
}


/*
// ��������
int main()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('a');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << endl;
		}
	}
	cout << "================" << endl;
	string s1;
	s1.reserve(100);
	size_t sz1 = s1.capacity();
	cout << "making s1 grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz1 != s1.capacity())
		{
			sz1 = s1.capacity();
			cout << "capacity changed: " << sz1 << endl;
		}
	}

	system("pause");
	return 0;
}

/*
void main()
{
	string s;
	//���reserve�Ƿ��Ӱ����Ч�ַ�����
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//����reserve����С��string�ĵײ�ռ��Сʱ���Ƿ��Ӱ��ռ���С
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//��������reserve��߲������ݵ�Ч�ʣ��������ݴ����Ŀ���

	system("pause");
}

/*
int main()
{
	string s("Hello");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

	s.clear();
	cout << "after clear size is :" << s.size()
		<< "\ncapacity is: " << s.capacity() << endl;

	s.resize(10, 'c');
	cout << "after resize "<<endl;
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.resize(15);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	//����Ч�ַ�������С��5
	s.resize(5);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;



	system("pause");
	return 0;
}
*/