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

	String(const String& s)  //拷贝构造函数
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s) //重载 = 运算符
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
	~String() //析构函数
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
	String(const char* str = "")  //构造函数
	{
		//构造string对象时，如果传递nullptr指针，认为程序非法，此处断言下
		if (nullptr == str)
		{
			assert(false);
			return;
		}

		_str = new char[strlen(str) + 1];
	}

	String(const String& s)  //拷贝构造函数
		:_str(new char[strlen(s._str)+1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s) //重载 = 运算符
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

	~String() //析构函数
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
	str.push_back(' ');//在str后面插入一个空格
	str.append("hello"); // 在str后面追加一个字符“hello”
	str += 'b';   // 在str后追加一个字符‘b’
	str += "it";  // 在str追加一个字符串"it"

	cout << str << endl;
	cout << str.c_str() << endl; //以c语言方式打印字符串

	//获取file的后缀
	string file1("test.cpp");
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;


	//npos 是string里面的一个静态成员变量
	//static const size_t npos = 1;
	
	//取出url中的域名
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
	

	//删除url的协议前缀
	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
	system("pause");
	return 0;
}


/*
// 对象访问及遍历
int main()
{
	string s1("Hello world");
	const string s2("Hello Bit");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'h';
	cout << s1 << endl;

	string s("hello bit");
	// 3种遍历方式
	// 需要注意的以下三种方式除了遍历string对象，
	// 还可以遍历是修改string中的字符，
	// 另外以下三种方式对于string而言，第一种使用最多
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

	// 3.范围for
	for (auto e : s)
	{
		cout << e ;
	}
	cout << endl;

	system("pause");
	return 0;
}


/*
// 容量操作
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
	//检测reserve是否会影响有效字符个数
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//测试reserve参数小于string的底层空间大小时，是否会影响空间缩小
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	//可以利用reserve提高插入数据的效率，避免增容带来的开销

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
	//将有效字符个数缩小到5
	s.resize(5);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl;



	system("pause");
	return 0;
}
*/