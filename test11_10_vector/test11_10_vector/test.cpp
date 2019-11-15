#include<iostream>
#include<vector>
using namespace std;


void print( vector<int>& v)
{
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}


//迭代器失效问题
int main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);

	vector<int>::iterator it = v.begin();
	while(it != v.end())
	{
		if (*it % 2 == 0)
			it = v.erase(it);
		else
			++it;
	}
	system("pause");
	return 0;
}

/*
int main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);

	v[0] = 10;
	cout << v[0] << endl;

	vector<int> swapv;
	swapv.swap(v);
	cout << "v date:";
	print(v);
	cout << "swapv date:";
	for (int i = 0; i < swapv.size(); ++i)
		cout << swapv[i] << ' ';
	cout << endl;

	for (auto e : swapv)
		cout << e << ' ';
	cout << endl;

	system("pause");
	return 0;
}

/*
//find /insert / erase
int main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(ar) / sizeof(int);
	vector<int> v(ar, ar + n);

	vector<int>::iterator pos = find(v.begin(), v.end(), 4);

	//在pos位置前插入值
	v.insert(pos, 3);
	print(v);
	pos = find(v.begin(), v.end(), 4);
	//删除pos位置的值；
	v.erase(pos);
	print(v);

	system("pause");
	return 0;
}


/*
//resize
int main()
{
	vector<int> myvector;
	for (int i = 1; i < 10; ++i)
	{
		myvector.push_back(i);
	}
	//myvector.resize(5);
	//myvector.resize(8, 100);
	myvector.resize(12, 3);
	cout << "myvector contains:";
	for (int i = 0; i < myvector.size(); ++i)
		cout << ' ' << myvector[i];
	cout << endl;


	system("pause");
	return 0;
}


/*
//reserve
int main()
{
	size_t sz;
	vector<int> foo;
	sz = foo.capacity();
	cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100);
	cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}
	system("pause");
	return 0;
}

/*
int main()
{
	int ar[] = { 1,2,3,4,5,6,7,8,9 };

	//构造方法
	vector<int> v1;
	vector<int> v2(9, 3);
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(ar, ar + 9);

	for (auto e : v3)
		cout << e << " ";
	cout << endl;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	print(v1);
	
	//使用迭代器进行修改
	vector<int>::iterator it = v2.begin();
	while (it != v2.end())
	{
		*it *= 2;
		++it;
	}
	print(v2);
	//反向打印
	vector<int>::reverse_iterator rit = v4.rbegin();
	while (rit != v4.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
	system("pause");
	return 0;
}*/