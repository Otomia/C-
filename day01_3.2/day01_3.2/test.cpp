#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

// 连续子数组最大和
int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> vt(n);
		for (int i = 0; i < n; ++i)
			cin >> vt[i];
		int max = vt[0];
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			sum += vt[i];
			if (sum > max) 
				max = sum;
			if (sum < 0)
				sum = 0;
		}
		cout << max << endl;
	}
}


// 淘宝网店
//bool isSushu(int n)
//{
//
//	for (int i = 2; i < n / 2; ++i)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}
//bool LeapYear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
//		return true;
//	else return false;
//}
//
//int main()
//{
//	vector<int> from(3);
//	vector<int> to(3);
//	//int Leap[] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
//	int month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int ar[] = { 0,2,1,1,2,1,2,1,2,2,2,1,2 };
//	while (1)
//	{
//		int count = 0;
//		for (int i = 0; i < 3; ++i)
//			cin >> from[i];
//		for (int i = 0; i < 3; ++i)
//			cin >> to[i];
//		if (from[0] > to[0])  // 年份不同
//		{
//			int tmp = 0;
//			for (int i = from[0] + 1; i < to[0]; ++i)
//			{
//				if (LeapYear(i))
//					tmp += 580;
//				else
//					tmp += 579;
//			}
//			for (int i = from[1] + 1; i <= 12; ++i)
//			{
//				if (LeapYear(from[0]) && i == 2)
//					tmp += 1;
//				tmp += (ar[i] * month[i]);
//			}
//			if (isSushu(from[1]))
//				tmp += (month[from[1]] - from[2] + 1);
//			else
//				tmp += (2 * (month[from[1]] - from[2] + 1));
//			for (int i = 1; i < to[1]; ++i)
//			{
//				if (LeapYear(to[1]) && i == 2)
//					tmp += 1;
//				tmp += (ar[i] * month[i]);
//			}
//			if (isSushu(to[1]))
//				tmp += to[2];
//			else
//				tmp += 2 * to[2];
//			count = tmp;
//		}
//		else if (from[0] == to[0]) // 年份相等
//		{
//			int tmp = 0;
//			if (from[1] == to[1]) // 月份相等
//			{
//				if (isSushu(from[1]))
//					tmp += (to[2] - from[2] + 1);
//				else
//					tmp += (2 * (to[2] - from[2] + 1));
//				count = tmp;
//			}
//			else if (from[0] != to[0]) // 月份不相等
//			{
//				if (LeapYear(from[0])) // 判断闰年
//				{
//					if (from[1] < 2 && to[1]>2)
//						tmp += 1;
//				}
//				else
//				{
//					for (int i = from[1] + 1; i < to[1]; ++i)
//					{
//						tmp += (ar[i] * month[i]);
//					}
//					if (isSushu(from[1]) && isSushu(to[1]))
//					{
//						tmp += (month[from[1]] - from[2] + 1 + month[to[1]] - to[2] + 1);
//					}
//					else if (isSushu(from[1]) && !isSushu(to[1]))
//						tmp += (month[from[1]] - from[2] + 1 + 2 * (month[to[1]] - to[2] + 1));
//					else if (!isSushu(from[1]) && isSushu(to[1]))
//						tmp += (2 * (month[from[1]] - from[2] + 1) + month[to[1]] - to[2] + 1);
//					else
//						tmp += (2 * (month[from[1]] - from[2] + 1 + month[to[1]] - to[2] + 1));
//				}
//				count = tmp;
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}
// 美国节日


// 因子分解
//bool isSushu(int n)
//{
//
//	for (int i = 2; i < n / 2; ++i)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}

//int main()
//{
//	int a;
//	while (cin >> a)
//	{
//		int count = 0;
//		
//		vector<int> vt;
//		int tmp = a;
//		cout << a << " = ";
//		for (int i = 2; i <= a/2; i++)
//		{
//			
//			while (tmp%i == 0)
//			{
//				if (tmp%i == 0)//isSushu(i) &&
//				{
//					count++;
//					if (count == 1)
//						cout << i;
//					else
//						cout << " * " << i;
//					tmp = tmp / i;
//				}
//			
//			}
//			
//		}
//		cout << endl;
//		/*cout << a << " = ";
//		for (int i = 0; i < vt.size(); ++i)
//		{
//			if (i != vt.size()-1)
//				cout << vt[i] << " * ";
//			else
//				cout << vt[i];
//		}
//		cout << endl;*/
//	}
//	return 0;
// }

//int getNum(int n)
//{
//	for (int i = 2; i <= n/2; ++i)
//	{
//		if (n%i == 0)
//		{
//			return getNum(i)
//		}
//	}
//}
//
//// 因子个数
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int count = 0;
//		for (int i = 1; i <= n/2; ++i)
//		{
//			if (n%i == 0)
//			{
//				
//			}
//		}
//	}
//	return 0;
//}

//最难的问题
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		for (int i = 0; i < s.size(); ++i)
//		{
//			if (s[i]>=65 && s[i] < 70) //ABCDE
//				s[i] = s[i] + 21;
//			else if (s[i] == ' ')  // 空格
//				continue;
//			else  // F ~Z
//				s[i] = s[i] - 5;
//		}
//		cout << s << endl;
//	}
//	return 0;
//}

//int findfake(double num)
//{
//	static int count = 0;
//	if (num == 1)
//		return 0;
//	else if (num <= 3)
//		return 1;
//	else
//		return findfake(num / 2) + 1;
//	
//}
//int main()
//{
//	double n;
//	while (cin >> n && n != 0)
//	{
//		cout << findfake(n) << endl;
//	}
//	return 0;
//}

//
//class Solution {
//public:
//	/**
//	 *	正数数组中的最小不可组成和
//	 *	输入：正数数组arr
//	 *	返回：正数数组中的最小不可组成和
//	 */
//	int getFirstUnFormedNum(vector<int> arr, int len) {
//		sort(arr.begin(), arr.end());
//		int min = arr[0];
//		int max = 0;
//		for (int i = 0; i < len; i++)
//		{
//			max += arr[i];
//		}
//
//	}
//};

//int main()
//{
//	int n;
//	while (cin >> n && n != 0)
//	{
// 		int old = 0;
//		int sum = 0;
//		for (int i = 0; i < n; ++i)
//			sum *= 5;
//		sum = sum / pow(4, n - 1) + 1;
//		old = sum;
//		for (int i = 0; i < n; ++i)
//		{
//			old = 
//		}
//	}
//	return 0;
//}

//class Solution {
//public:
//	/**
//	 *  奇数位上都是奇数或者偶数位上都是偶数
//	 *  输入：数组arr，长度大于2
//	 *  len：arr的长度
//	 *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
//	 */
//	void oddInOddEvenInEven(vector<int>& arr, int len) {
//		for (int i = 0; i < len; ++i)
//		{
//			if (i == 0 && arr[0] % 2 != 0)
//			{
//				 
//			}
//		}
//		
//	}
//};
//
//int main()
//{
//	Solution s;
//	
//	return 0;
//}
//int main()
//{
//	Solution s;
//	vector<int> arr(4);
//	for (int i = 1; i < 5; ++i)
//	{
//		arr[i] = i;
//	}
//	s.oddInOddEvenInEven(arr, 4);
//	for (auto &e : arr)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}
// day 27 判断三角形
//int main()
//{
//	double a, b, c;
//	while (cin >> a >> b >> c)
//	{
//		if (a + b > c && a + c > b && b + c > a)
//		{
//			cout << "Yes" << endl;
//			
//		}
//		else
//		{
//			cout << "No" << endl;
//			
//		}
//	}
//	return 0;
//}


// day26
// 1、变态青蛙 -- 一个青蛙跳上一个n级的台阶总共有多少种跳法
//class Solution {
//public:
//	int jumpFloorII(int number) {
//		if (number == 1)
//			return 1;
//		else
//			return 2 * jumpFloorII(number - 1);
//	}
//};
//int main()
//{
//	Solution s;
//	int res = s.jumpFloorII(4);
//	cout << res << endl;
//	return 0;
//}
//
//2 、快到碗里来 输入两个整数（1<= n <= 2^128)
//int main()
//{
//	double length, r;
//	while (cin >> length >> r)
//	{
//		double PI = 3.14;
//		double C = 2 * r * PI;
//		if (length <= C)
//			cout << "Yes" << endl;
//		else
//			cout << "No" << endl;
//	}
//	return 0;
//}

// day 25

//数根
//int ShuGen(int x)
//{
//	int sum = 0;
//	while (x)
//	{
//		sum += x % 10;
//		x = x / 10;
//	}
//	while (sum > 9)
//	{
//		sum = ShuGen(sum);
//	}
//	return sum;
//}
//int main()
//{
//	string n;
//	while (getline(cin,n))
//	{
//		int sum = 0;
//		for (int i = 0; i < n.size(); ++i)
//			sum += n[i] - '0';
//		cout<<ShuGen(sum)<<endl;
//	}
//	return 0;
//}
//
// 星际密码
//vector<int> PWD(int x)
//{
//	vector<int> vt(4);
//	int ar[2][2] = { 1,1,1,0 };
//	vector<vector<int>> res(4);
//	for (int i = 0; i < 2; ++i)
//	{
//		for (int j = 0; j < 2; ++j)
//		{
//			res[i][j] = ar[i][j];
//		}
//	}
//	for (int i = 1; i < x; ++i)
//	{
//		res[0][0] = res[0][0] * ar[0][0] + res[0][1] * ar[1][0];
//		res[0][1] = res[0][0] * ar[0][1] + res[0][1] * ar[1][1];
//		res[1][0] = res[1][0] * ar[0][0] + res[1][1] * ar[1][0];
//		res[1][1] = res[1][0] * ar[0][1] + res[1][1] * ar[1][1];
//	}
//	if (res[0][0] > 9999)
//	{
//		for (int i = 0;i < 4; ++i)
//		{
//			while (res[0][0])
//			{
//				vt.push_back(res[0][0] % 10);
//				res[0][0] = res[0][0] / 10;
//			}
//		}
//		return vt;
//	}
//	else
//	{
//		for (int i = 0; i < 4; ++i)
//		{
//			while (res[0][0])
//			{
//				vt.push_back(res[0][0] % 10);
//				res[0][0] = res[0][0] / 10;
//			}
//			vt.push_back(0);
//		}
//		return vt;
//	}
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> ar(n);
//	for (int i = 0; i < n; ++i)
//	{
//		cin >> ar[i];
//	}
//	vector<int> vt;
//	vt.resize(4);
//	for (int i = 0; i < n; ++i)
//	{
//		vt = PWD(ar[i]);
//		for (int i = 0; i < 4; ++i)
//		{
//			cout << vt[i];
//		}
//	}
//	cout << endl;
//	return 0;
//}

// day 23
//bool judgeZic(string s1, string s2)
//{
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		int j = 0;
//		for ( j = 0; j < s2.size(); ++j)
//		{
//			if (s1[i + j] != s2[j])  // 不相等
//				break;
//		}
//		if (j == s2.size()) 
//			return true;
//	}
//	return false;
//}
//
//int calStringDistance(string charA, string charB)
//{
//	// A是较长的字符串
//	if (charA.size() < charB.size())
//		swap(charA, charB);
//	if (charA.size() == charB.size() && !judgeZic(charA, charB))
//		return -1;
//	if (judgeZic(charA, charB))
//		return charA.size() - charB.size();
//	else
//		return charA.size() + charB.size();
//
//}
//
//int main()
//{
//	string charA, charB;
//	while (getline(cin, charA) && getline(cin, charB))
//	{
//		cout << calStringDistance(charA, charB) << endl;
//	}
//	return 0;
//}
// 微信红包
// 返回 元素 数组里某个元素出现的次数超过数组大小的一半
//class Gift {
//public:
//	int getValue(vector<int> gifts, int n) {
//		// write code here
//		int count = 0;
//		sort(gifts.begin(), gifts.end());
//		int index = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			
//			if (gifts[i] == gifts[n/2])
//			{
//				count++;
//				index = i;
//			}
//		}
//		if (count > n / 2)
//			return gifts[index];
//		else
//			return 0;
//	}
//};

//int main()
//{
//	Gift g;
//	vector<int> vt{ 1,2,3,2,2 };
//	int n = 5;
//	int num = g.getValue(vt,n);
//	cout << num << endl;
//	return 0;
//}
//int first(string s1)
//{
//	int hash[256] = { 0 };
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		hash[s1[i]] += 1;
//	}
//	for (int i = 0; i < s1.size(); ++i)
//	{
//		if (hash[s1[i]] == 1)
//			return i;
//	}
//	return -1;
//}
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		int ret = first(str);
//		if (ret != -1)
//			cout << str[ret] << endl;
//		else
//			cout << ret << endl;
//	}
//	return 0;
//}


//
//int gcd(int a, int b)
//{
//	int tmp = 0;
//	if (b < a)
//	{
//		tmp = b;
//		b = a;
//		a = tmp;
//	}
//	while (a != 0)
//	{
//		tmp = b % a;
//		b = a;
//		a = tmp;
//	}
//	return b;
//}
//
//int main()
//{
//	int n, a;
//	while (cin >> n >> a)
//	{
//		vector<int> b;
//		b.resize(n);
//		for (int i = 0; i < n; ++i)
//		{
//			cin >> b[i];
//		}
//		int c = a;
//		for (int i = 0; i < n; ++i)
//		{
//			if (b[i] <= c)
//				c += b[i];
//			else
//			{
//				c += gcd(c, b[i]);
//			}
//		}
//		cout << c << endl;
//	}
//	
//	return 0;
//}

//
//int main()
//{
//	int T;
//	cin >> T;
//	for (int i = 0; i < T; ++i)
//	{
//		int n, k;
//		cin >> n >> k;
//		int vt[] = {0};
//		//vt.resize(2 * n);
//		for (int j = 0; j < 2 * n; ++i)
//		{
//			cin >> vt[i];
//		}
//		int res[] = { 0 };
//		//res.resize(2 * n);
//		for (int j = 0; j < k; ++i)
//		{
//			for (int l = 0; l < n; ++l)
//			{
//				res[2*l] = (vt[l]);
//				res[2*l+1] = (vt[n + l]);
//			}
//		}
//		cout << res[0];
//		for (int j = 1; j < 2 * n; ++j)
//			cout  << " " << res[i];
//		cout << endl;
//	}
//}

//int getCommonStrLength(const char* pFirstStr, const char* pSecond)
//{
//	int max = 0, count = 0;
//	int len1 = sizeof(pFirstStr) / sizeof(char);
//	int len2 = sizeof(pSecond) / sizeof(char);
//	int first = 0, second = 0;
//	for (int i = 0; i < len1; ++i)
//	{
//		for (int j = 0; j < len2; ++j)
//		{
//			first = i;
//			second = j;
//			while (pFirstStr[first] == pSecond[second])
//			{
//				first++;
//				second++;
//				count++;
//			}
//			if (count > max)
//			{
//				max = count;
//			}
//			count = 0;
//		}
//	}
//	return max;
//}
//int main()
//{
//	char* p1 ;
//	char* p2 ;
//	
//	cout << getCommonStrLength(p1, p2) << endl;
//
//}
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		string::reverse_iterator rit = str.rbegin();
//		while (rit != str.rend())
//		{
//			cout << *rit;
//			++rit;
//		}
//	}
//}
//day 19
//int main()
//{
//	string s1, s2;
//	while (getline(cin, s1), getline(cin, s2))
//	{
//		string res;
//		int l1 = s1.size();
//		int l2 = s2.size();
//		int max = 0, count = 0;
//		if (l1 > l2)
//			swap(s1, s2);
//		for(int i=0;i<s1.size();++i)
//		{ 
//
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	vector<int> ret;
//	while (cin >> n )
//	{
//		int count = 0;
//		if (n == 0)
//			break;
//		if (n < 2)
//			cout << "0" << endl;
//		while (n > 2)
//		{
//			count += n / 3;
//			n = (n / 3) + (n % 3);
//		}
//		if (n == 2)
//			count += 1;
//		cout << count << endl;
//	}
//	
//	return 0;
//}

// day 18
//int main()
//{
//	string s1, s2;
//	while (getline(cin, s1) && getline(cin, s2))
//	{
//	
//		for (int i = 0; i < s2.size(); ++i)
//		{
//			if (s1[i] == '?'&&i < s1.size()-1)
//			{
//				i++;
//				if (s1[i] != s2[i])
//				{
//					cout << "false" << endl;
//					break;
//				}
//			}
//			else if (s1[i] == '*' )
//			{
//				if (i != s1.size() - 1)
//				{
//					int j = i;
//					while (s1[i + 1] != s2[j])
//					{
//						j++;
//					}
//					i = j;
//				}
//				else
//					i = s2.size() - 1;
//			}
//			else if (s1[i] != s2[i])
//			{
//				cout << "false" << endl;
//				break;
//			}
//			else if (s1[i] == s2[i])
//				continue;
//			if (s1[i] == '\n'&&s2[i] == '\n')
//				cout << "true" << endl;
//		}
//	}
//	return 0;
//}
//int getTotalCount(int monthCount)
//{
//	//int count = 0;
//	if (monthCount < 3)
//		return 1;
//	if (monthCount >= 3)
//		return getTotalCount(monthCount - 1)+getTotalCount(monthCount-2);
//}
//
//int main()
//{
//	int month;
//	while (cin >> month)
//	{
//		cout << getTotalCount(month) << endl;
//	}
//	return 0;
//}

//day 17
//string AddLongInteger(string addend, string audend)
//{
//	// addend:加数
//	// audend: 被加数
//	string s;
//	reverse(addend.begin(), addend.end());
//	reverse(audend.begin(), audend.end());
//	int ret;
//	int flag = 0;// 进位
//	for (int i = 0; i < addend.size(); ++i)
//	{
//		ret = (addend[i] - '0') + (audend[i] - '0') + flag;
//		flag = ret / 10;
//	}
//}
//
//int main()
//{
//	string addend, audend;
//	while (getline(cin, addend) && getline(cin, audend))
//	{
//		string res = AddLongInteger(addend, audend);
//		cout << res << endl;
//	}
//	return 0;
//}

//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		if (str.find("joker JOKER") != string::npos)
//			cout << "joker JOKER" << endl;
//		else
//		{
//			string s1, s2;
//			for (int i = 0; i < str.size(); i++)
//			{
//				int j = str.find('-');
//				if (i < j)
//				{
//					s1.push_back(str[i]);
//				}
//				if (i > j)
//				{
//					s2.push_back(str[i]);
//				}
//			}
//			if(s1.size()==s2.size())
//			{
//				if (s1.size() == 1  ||
//					s1.size() == 3  ||
//					s1.size() == 5  ||
//					s1.size() == 7  ||
//					s1.size() == 9 )
//				{
//					if (s1[1] > s2[1])
//						cout << s1 << endl;
//					else
//						cout << s2 << endl;
//				}
//			}
//			else
//			{
//				if (s1.size() == 7)
//					cout << s1 << endl;
//				else if (s2.size() == 7)
//					cout << s2 << endl;
//				else
//					cout << "EEROR" << endl;
//			}		
//		}
//	}
//	return 0;
//}

// day 16
//bool perfectNum(int x)
//{
//	int sum = 0;
//	for (int i = 1; i <= x / 2; ++i)
//	{
//		if (x%i == 0)
//			sum += i;
//	}
//	if (sum == x)
//		return true;
//	else
//		return false;
//}
//
//int count(int n)
//{
//	int count = 0;
//	for (int i = 2; i <= n; ++i)
//	{
//		if (perfectNum(i))
//			count++;
//	}
//	return count;
//}
//int main()
//{
//	int n;
//	/*while (cin >> n)
//	{
//		
//	}*/
//	bool flag = perfectNum(28);
//	//cout << count(n) << endl;
//	cout << flag;
//	return 0;
//}

//class Gloves {
//public:
//	int findMinimum(int n, vector<int> left, vector<int> right) 
//	{
//		// write code here
//		int ret = 0;
//		int Lsum = 0, Rsum = 0, Lmin = 0, Rmin = 0;
//		
//		for (int i = 0; i < n; ++i)
//		{
//			Lsum += left[i];
//			Rsum += right[i];
//			Lmin = min(Lmin, left[i]);
//			Rmin = min(Rmin, right[i]);
//		}
//		ret = min(Lsum - Lmin + 1, Rsum - Rmin + 1);
//		return ret;
//	}
//};
//

//int findNumberOf1(int num)
//{
//	int count = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//			count++;
//		num = num / 2;
//	}
//	return count;
//}
//
//int main()
//{
//	int n;
//	
//	while (cin >> n)
//	{
//		cout << findNumberOf1(n) << endl;
//	}
//	return 0;
//}


//#define SQR(A) A*A 
//void main()
//{
//	int x = 6, y = 3, z = 2, c = 6;
//	int A = SQR(y + z);
//	x /= SQR(y + z) / SQR(y + z);
//	int d = SQR(y + z) / SQR(y + z);
//
//	cout << x << endl;
//}


//vector<int> ys(int n)
//{
//	vector<int> ret;
//	for (int i = 1; i <= n / 2; ++i)
//	{
//		if (n%i == 0)
//			ret.push_back(i);
//	}
//	return ret;
//}
//
//int count(int N, int M)
//{
//	vector<int> vt(M+1,0);
//
//	
//	vt[N] = 1;
//
//	for (int i = N; i < M; ++i)
//	{
//		if (vt[i] == 0)
//			continue;
//		vector<int> Yueshu=ys(i); // 可以走的步数集合
//		for (int j = 0; j < Yueshu.size(); ++i)
//		{
//			if (i + Yueshu[j] <= M) // 位置+1
//			{
//				vt[i + Yueshu[j]] = vt[i] + 1;
//			}
//			else if (i + Yueshu[j] <= M && vt[i + Yueshu[j]] != 0) //说明来过
//			{
//				vt[i + Yueshu[j]] = min(vt[i + Yueshu[j]], vt[i] + 1);
//			}
//
//		}
//	}
//	if (vt[M] == 0)
//		return -1;
//	return vt[M] - 1;
//}
//
//int main()
//{
//	int N, M;
//	while (cin >> N >> M)
//	{
//		
//		cout << count(N,M) << endl;
//	}
//	return 0;
//}

//bool isSushu(int n)
//{
//
//	for (int i = 2; i < n / 2; ++i)
//	{
//		if (n%i == 0)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int n;
//	vector<int> vt;
//	while (cin >> n)
//	{
//		for (int i = 1; i < n/2; ++i)
//		{
//			if (isSushu(i) && isSushu(n - i))
//			{
//				vt.push_back(i);
//				vt.push_back(n - i);
//			}
//				
//		}
//		cout << vt[vt.size() - 2] << endl;
//		cout << vt[vt.size() - 1] << endl;
//
//	}
//	return 0;
//}

//
//int main()
//{
//	int n;
//	int ret = 0, max = 0;
//	while (cin >> n)
//	{
//		while (n)
//		{
//			if (n % 2 == 1)
//				ret++;
//			else
//				ret = 0;
//			if (ret > max)
//				max = ret;
//			n = n / 2;
//		}
//		cout << max << endl;
//	}
//	return 0;
//}

//class LCA {
//public:
//	int getLCA(int a, int b) {
//		// write code here
//		if (a == b / 2)
//			return a;
//		if (b == a / 2)
//			return b;
//		while (a != b)
//		{
//			if (a == 1)
//				return a;
//			if (b == 1)
//				return b;
//			a = a / 2;
//			b = b / 2;
//		}
//		return a;
//	}
//};
//
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
//	LCA l;
//	int res = l.getLCA(8 ,10);
//	cout << res << endl;
//	return 0;
//}

//class Parent
//{
//public:
//	Parent()
//	{
//		cout << "Parent::Parent()\n";
//	}
//	~Parent()
//	{
//		cout << "Parent::~Parent()\n";
//	}
//	static void fun()
//	{
//		cout << "Parent::fun()\n";
//	}
//	virtual void test()
//	{
//		cout << "Parent::test()\n";
//	}
//};
//
//class Son : public Parent
//{
//public:
//	Son()
//	{
//		cout << "Son::Son()\n";
//	}
//	~Son()
//	{
//		cout << "Son::~Son()\n";
//	}
//public:
//	void fun1()
//	{
//		cout << "Son::fun1()\n";
//	}
//	virtual void test()
//	{
//		cout << "Son::test()\n";
//	}
//};
//
//int main()
//{
//	Parent *p = new Parent;
//	delete p;
//	Parent::fun();
//	return 0;
//}

//int GetPwdSecurity(string pPasswordStr)
//{
//	int res = 0;
//	int le = 0, LE = 0;
//	int num = 0, fh = 0;
//	int length = pPasswordStr.size();
//	// 长度
//	if (length >= 8)
//		res = 25;
//	else if (length >= 5 && length <= 7)
//		res = 10;
//	else if (res <= 4)
//		num = 5;
//	
//	for (int i = 0; i < length; ++i)
//	{
//		// 小写字母
//		if (pPasswordStr[i] >= 'a'&&pPasswordStr[i] <= 'z')
//			le++;
//		// 大写字母
//		else if (pPasswordStr[i] >= 'A'&&pPasswordStr[i] <= 'Z')
//			LE++;
//		// 数字
//		else if (pPasswordStr[i] >= '0' && pPasswordStr[i] <= '9')
//			num++ ;
//		// !"#$%&'  符号
//		else if ((pPasswordStr[i] >= 0x21 && pPasswordStr[i] <= 0x2F) ||
//			(pPasswordStr[i] >= 0x3A && pPasswordStr[i] <= 0x40) ||
//			(pPasswordStr[i] >= 0x5B && pPasswordStr[i] <= 0x60) ||
//			(pPasswordStr[i] >= 0x7B && pPasswordStr[i] <= 0x7E))
//			fh++;
//	}
//	if (le == length || LE == length)
//	{
//		res += 10;
//		return res;
//	}
//	if (le >= 1 && LE >= 1 )
//	{
//		res += 20;
//	}
//	if (num == 1)
//		res += 10;
//	if (num > 1)
//		res += 20;
//	if (fh == 1)
//		res += 10;
//	if (fh > 1)
//		res += 25;
//	if (le+num== length || LE + num == length)
//	{
//		res += 2;
//		return res;
//	}
//	if (le + num + fh == length || LE + num + fh == length)
//	{
//		res += 3;
//		return res;
//	}
//	if (le + LE + num + fh == length)
//	{
//		res += 5;
//		return res;
//	}
//}

//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		int res = GetPwdSecurity(str);
//		if (res >= 90)
//			cout << "VERY_SECURE\n";
//		if (res >= 80 && res < 90)
//			cout << "SECURE\n";
//		if (res >= 70 && res < 80)
//			cout << "VERY_STRONG\n";
//		if (res >= 60 && res < 70)
//			cout << "STRONG\n";
//		if (res >= 50 && res < 60)
//			cout << "AVERAGE\n";
//		if (res >= 25 && res < 50)
//			cout << "WEAK\n";
//		if (res >= 0 && res < 25)
//			cout << "VERY_WEAK\n";
//	}
//	return 0;
//}

//class Board {
//public:
//	bool checkWon(vector<vector<int> > board) {
//		// write code here
//		// 横向判断
//		for (int i = 0; i < 3; i++)
//		{
//			if (board[i][0] == board[i][1] && board[i][1] == 1)
//			{
//				if (board[i][1] == board[i][2])
//					return true;
//			}
//		}
//		//纵向判断
//		for (int j = 0; j < 3; ++j)
//		{
//			if (board[0][j] == board[1][j] && board[1][j] == 1)
//				if (board[1][j] == board[2][j])
//					return true;
//		}
//		// 右斜线
//		if (board[0][0] == board[1][1] && board[1][1] == 1)
//		{
//			if (board[1][1] == board[2][2])
//				return true;
//		}
//		// 左斜线
//		if (board[0][2] == board[1][1] && board[1][1] == 1)
//		{
//			if (board[1][1] == board[2][0])
//				return true;
//		}
//		return false;
//	}
//};

//using namespace std;
//
//int pathnum(int n, int m)
//{
//	if (n == 0 || m == 0)
//		return 0;
//	else if (n == 1 || m == 1)
//		return n + m;
//	else 
//		return pathnum(n - 1, m);
//}
//
//int main()
//{
//	int n, m;
//	while (cin >> n >> m)
//	{
//		int ret = pathnum(n,m);
//		cout << ret << endl;
//		/*if (n == 0 || m == 0)
//			cout << 0 << endl;
//		else
//			cout << n * (1 + m)<<endl;*/
//	}
//	
//	return 0;
//}
//bool sortBylength(string s1, string s2)
//{
//	if (s1.size < s2.size())
//		return true;
//	return false;
//}
//bool sortBylex(string s1, string s2)
//{
//}
//
//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		int len = 1, lex = 0;
//		vector<vector<string>> s;
//		s.resize(n);
//		for (auto &e : s)
//			e.resize(1);
//		for (int i = 0; i < n; ++i)
//		{
//			string str;
//			getline(cin, str);
//			s[i][0] = str;
//		}
//		for (int i = 0; i <= n * 1; ++i)
//		{
//			if (!sortBylength(s[i][0], s[i + 1][0]))
//			{
//				--len;
//				break;
//			}
//		}
//
//
//	}
//	return 0;
//}

//int gcd(int a, int b)
//{
//	int tmp = 0;
//	if (b < a)
//	{
//		tmp = b;
//		b = a;
//		a = tmp;
//	}
//	while (a != 0)
//	{
//		tmp = b % a;
//		b = a;
//		a = tmp;
//	}
//	return b;
//}
//
//int main()
//{
//	int A, B;
//	while (cin >> A >> B)
//	{
//		int res = A * B / (gcd(A, B));
//		cout << res << endl;
//	}
//	return 0;
//}

//class Parenthesis {
//public:
//	bool chkParenthesis(string A, int n) {
//		// write code here
//		int count = 0;
//		for (int i = 0; i < n; ++i)
//		{
//			if (A[i] != '('&&A[i] != ')')
//				return false;
//			if (A[i] == '(')
//				count++;
//			if (A[i] == ')')
//				count--;
//		}
//		if (count != 0)
//			return false;
//		return true;
//	}
//};

//int main()
//{
//	Parenthesis p;
//	bool ret = p.chkParenthesis("()(()())", 8);
//	cout << ret;
//	return 0;
//}

//int Fibonacci(int n)
//{
//
//	if (n == 0)
//		return 0;
//	else if (n == 1)
//		return 1;
//	else return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//
//int main()
//{
//	int N;
//	while (cin >> N)
//	{
//		int num = 0;
//		int x = 0;
//		while (num >= 0)
//		{
//			if (Fibonacci(num) >= N)
//			{
//				x = Fibonacci(num);
//				break;
//			}
//			else
//				num++;
//		}
//		int y = Fibonacci(num - 1);
//		int min = (x - N) < (N - y) ? (x - N) : (N - y);;
//		cout << min << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int n, m;
//	cin >> n >> m;
//	int c = 0, k = 0;
//	
//	int vt[200];
//	if (n < 0) //负数
//	{
//		n = -n;
//		cout << "-";
//	}
//	while (n != 0)
//	{
//		c = n % m;
//		n = n/ m;
//		k++;
//		vt[k] = c;
//	}
//	//reverse(vt.begin(), vt.end());
//	for (int i = k; i >= 1; --i)  // 从后到前输出
//	{
//		if (vt[i] >= 10)  // 如果16进制中有大于10的数 转为字母abcdef
//			cout << (char)(vt[i] + 55);
//		else
//			cout << vt[i];
//	}
//	return 0;
//}

//class Solution {
//public:
//	int StrToInt(string str) {
//		int ret = 0;  
//		int flag = 1; 
//		if(str.size()==0 || (str.size()==1&&str[0]<'0'||str[0]>'9'))
//			return 0;
//		if (str[0] == '-')  // 判断是否为负数
//		{
//			flag = -1;
//			//str;
//		}
//		/*if (str[0] == '+')
//			str.erase(0);*/
//			
//		for (int i = 0; i < str.size(); i++) // 从第二个元素开始遍历
//		{
//			if (str[0] == '-' || str[0] == '+')
//				continue;
//			else if (str[i] < '0' || str[i] > '9') //遇到不是数字的返回 0
//			{
//				return 0;
//			}
//			else
//			{
//				str[i] = str[i] - '0';
//				ret = ret * 10 + str[i];
//			}
//				
//		}
//		return ret * flag;
//		
//	}
//};
//
//int main()
//{
//	string str = "123456789";
//	Solution S;
//	int ret = S.StrToInt(str);
//	cout << ret;
//	return 0;
//}
//int main()
//{
//	vector<vector<int>> vt;
//	int W, H, count = 0;
//	while (cin >> W >> H)
//	{
//		vt.resize(H);
//		for (auto &e : vt)
//			e.resize(W, 1);
//		for (int i = 0 ; i < H; ++i)
//		{
//			for (int j = 0; j < W; ++j)
//			{
//				if (vt[i][j] == 1)
//				{
//					count++;
//					if (i + 2 < H)
//						vt[i + 2][j] = 0;
//					if (j + 2 < W)
//						vt[i][j + 2] = 0;
//				}
//			}
//		}
//		cout << count << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int ar[] = { 1,2,3,2,2,2,4,2 };
//	vector<int> num;
//	for (int i = 0; i < 7; ++i)
//		num.push_back(ar[i]);
//	int ret = num[0];
//	int times = 1;
//	for (int i = 1; i < num.size(); ++i)
//	{
//		if (times == 0)
//		{
//			ret = num[i];
//			times = 1;
//		}
//		else if (num[i] == ret)
//			++times;
//		else
//			--times;
//	}
//	//if (times > num.size() / 2)
//	times = 0;
//	for (int i = 0; i < num.size(); ++i)
//	{
//		if (num[i] == ret)
//			times++;
//	}
//	if (times > num.size() / 2)
//		cout << ret;
//	return 0;
//}
//int main()
//{
//	int n;
//	vector<int> ar;
//	while (cin >> n)
//	{
//		ar.resize(n);
//		for (int i = 0; i < n; ++i)
//			cin >> ar[i];
//		int maxSum = 0;
//		int sum = 0;
//		for (int i = 0; i < ar.size(); ++i)
//		{
//			if (sum <= 0)
//				sum = ar[i];
//			else
//				sum += ar[i];
//			if (sum > maxSum)
//				maxSum = sum;
//		}
//		cout << maxSum << endl;
//	}
//	return 0;
//}

//bool isHW(string s)
//{
//	if (s.size() == 1)
//		return true;
//	int first = 0;
//	int end = s.size() - 1;
//	while (first < end)
//	{
//		if (s[first++] == s[end--])
//			return true;
//	}
//	return false;
//}
//int main()
//{
//	string A, B;
//	int count = 0;
//
//	while (getline(cin, A) && getline(cin, B))
//	{
//		for (int i = 0; i <= A.size(); ++i)
//		{
//			string tmp = A;
//			tmp.insert(i, B);
//			if (isHW(tmp))
//				count++;
//		}
//		cout << count << endl;
//	}
//	return 0;
//}

//int main()
//{
//	string s1, s2;
//	cin >> s2;
//	while (cin >> s1)
//	{
//		s2 = s1 + " " + s2;
//	}
//	cout << s2 << endl;
//	return 0;
//}

//int main()
//{
//	int n, count = 0;
//	vector<int> a;
//	cin >> n;
//	a.resize(n + 1);
//	for (int i = 0; i < n; i++)
//		cin >> a[i];
//	int i = 0;
//	while (i < n)
//	{
//		// 非递减序列
//		if (a[i] < a[i + 1])
//		{
//			while (i < n&&a[i] <= a[i + 1])
//				i++;
//			count++;
//			i++;
//		}
//		else if (a[i] == a[i + 1])
//			i++;
//		// 非递增序列
//		else
//		{
//			while (i < n&&a[i] >= a[i + 1])
//				i++;
//			count++;
//			i++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

//int main()
//{
//	int M, N;
//	string ret;
//	string s = "0123456789abcdef";
//	while (cin >> M >> N)
//	{
//		if (M == 0)
//		{
//			cout << M << endl;
//		}
//		if (M < 0)
//			M = -M;
//		while (M)
//		{
//			ret += s[M % N];
//			M /= N;
//		}
//		reverse(ret.begin(), ret.end());
//		cout << ret << endl;;
//	}
//	return 0;
//}

//int main()
//{
//	
//	int x, y, z, q;
//	while (cin >> x >> y >> z >> q)
//	{
//		int A = (x + z)/2;
//		int B1 = (y + q) / 2;
//		int C = (q - y) / 2;
//		int B2 = (z - x) / 2;
//		if (B1 != B2)
//			cout << "No";
//		else
//			cout << A << " " << B1 << " " << C;
//	}
//	return 0;
//}

//int main()
//{
//	string str;
//	int Mcount = 0, Ncount = 0;
//	int i = 0;
//	string ret;
//	while (getline(cin, str))
//	{
//		while (i < str.size())
//		{
//			string s;
//			while (isdigit(str[i]))
//			{
//				s += str[i];
//				Ncount++;
//				i++;
//			}
//			if (Ncount > Mcount)
//			{
//				ret = s;
//				Mcount = Ncount;
//			}
//			i++;
//		}
//		cout << ret;
//	}
//	
//	return 0;
//}

//int main()
//{
//	int n, num;
//	int ar[] = { 0 };
//	while (cin >> n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cin >> num;
//			ar[i] = num;
//		}
//		
//	}
//	return 0;
//}

//int main()
//{
//	string str;
//	stack<string> ret;
//	
//	while (cin>>str)
//	{
//		ret.push(str);
//		string s1 = str;
//		if (*(str.rbegin()) == '.')
//			break;
//	}
//	cout << ret.top();
//	ret.pop();
//	while (!ret.empty())
//	{
//		cout << " " << ret.top();
//
//		ret.pop();
//	}
//	return 0;
//}

//int main()
//{
//	int n;
//	int num, sum = 0;
//	vector<int> ar;
//	cin >> n;
//	for (int i = 0; i < 3 * n; i++)
//	{
//		scanf_s("&d", &num);
//		ar[i] = num;
//	}
//	sort(ar.begin(), ar.end());
//	for (int i = 0; i < n; i++)
//	{
//		sum += ar[i * 2 + 1];
//	}
//	cout << sum << endl;;
//	return 0;
//}

//int main()
//{
//	string str1, str2;
//	while (getline(cin, str1)&& getline(cin, str2))
//	{
//		int hash[256] = { 0 };
//		for (int i = 0; i < str2.size(); i++)
//		{
//			hash[str2[i]]++;
//		}
//		string str;
//		for (int i = 0; i < str1.size(); i++)
//		{
//			if (hash[str1[i]] == 0)
//			{
//				str += str1[i];
//			}
//		}
//		cout << str << endl;
//	}
//	return 0;
//}