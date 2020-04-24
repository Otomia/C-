#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


class Solution {
public:
	//int removeElement(vector<int>& nums, int val) 
	//{
	//	if (nums.size() == 0)
	//		return 0;
	//	int j = 0;
	//	for (int i = 0; i < nums.size(); ++i)
	//	{
	//		if (nums[i] != val)
	//		{
	//			nums[j] = nums[i];
	//			j++;
	//		}
	//	}
	//	return j;
	//}

	////
	//int searchInsert(vector<int>& nums, int target) {
	//	if (nums.size() == 0)
	//		return 0;
	//	for (int i = 0; i < nums.size(); ++i)
	//	{
	//		if (nums[i] >= target)
	//			return i;
	//	}
	//	return nums.size();
	//	int left = 0, right = nums.size() - 1;
	//	while (left <= right)
	//	{
	//		int mid = (left + right) / 2;
	//		if (nums[mid] == target)
	//			return mid;
	//		else if (nums[mid] < target)
	//			left = mid + 1;
	//		else
	//			right = mid - 1;
	//	}
	//	return left;
	//}
 //
	////赎金信
	//bool canConstruct(string ransomNote, string magazine) {
	//	int hash[26] = { 0 }; //利用一个大小为26的整型数组来存储每个字母的数量
	//	for (int i = 0; i < magazine.length(); ++i)
	//		hash[magazine[i] - 'a']++; //遍历“杂志”字符串，将每个字母对应在数组中的元素值+1；
	//	for (int i = 0; i < ransomNote.length(); ++i)
	//	{
	//		hash[ransomNote[i] - 'a']--;//遍历“赎金信”字符串，将每个字母对应在数组中的元素值-1；
	//		if (hash[ransomNote[i] - 'a'] < 0)
	//			return false; //无法构成赎金信
	//	}
	//	return true;
	//}

	//bool isPalindrome(int x) {  //验证回文数字
	//	if (x < 0)
	//		return false;
	//	int div = 1;
	//	while (x / div >= 10)
	//		div *= 10;
	//	while (x > 0)
	//	{
	//		int left = x / div;  //得到首位数字
	//		int right = x % 10;  //得到末尾数字
	//		if (left != right)   //进行比较
	//			return false;
	//		x = (x%div) / 10;    //去掉首末两位数字
	//		div /= 100;
	//	}
	//	return true;
	//}

	//int lengthOfLastWord(string s) {
	//	int res = 0;
	//	if (s.size() == 0)
	//		return 0;
	//	for (int i = s.size() - 1; i>=0;--i)
	//	{
	//		if (s[i] != ' ')
	//			res++;
	//		else
	//		{
	//			if (res)
	//				break;
	//		}
	//	}
	//	return res;
	//}


	//void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	//	if (nums1.size() < m + n)
	//		return;
	//	for (int i = 0; i < n; ++i)
	//	{
	//		nums1[m + i] = nums2[i];
	//	}
	//	sort(nums1.begin(), nums1.end());
	//}

	//bool containsDuplicate(vector<int>& nums) {
	//	if (nums.size() == 0)
	//		return false;
	//	sort(nums.begin(), nums.end());
	//	for (int i = 0; i < nums.size(); ++i)
	//	{
	//		if (nums[i] == nums[i + 1])
	//			return true;
	//	}
	//	return false;
	//}

	//bool isLongPressedName(string name, string typed) {
	//	int pname = 0;
	//	int ptyped = 0;
	//	while (pname < name.length() && ptyped < typed.length())
	//	{
	//		if (name[pname] == typed[ptyped])
	//		{
	//			pname++;
	//			ptyped++;
	//		}
	//		else
	//			ptyped++;
	//	}
	//	return pname == name.length();
	//}
	//vector<int> sortedSquares(vector<int>& A) {
	//	for (int i = 0; i < A.size(); ++i)
	//	{
	//		A[i] *= A[i];
	//	}
	//	sort(A.begin(), A.end());
	//	return A;
	//}

	//string reverseOnlyLetters(string S) {
	//	int first = 0, int last = S.length() - 1;
	//	while (first < last)
	//	{
	//		if (isalpha(S[first]) && isalpha(S[last]))
	//		{
	//			swap(S[first], S[last]);
	//			first++;
	//			last--;
	//		}
	//		else if (!isalpha(S[first]))
	//		{
	//			first++;
	//		}
	//		else if (!isalpha(S[last]))
	//			last--;
	//	}
	//	return S;
	//}
	//
	//vector<int> sortArrayByParity(vector<int>& A)
	//{
	//	int left = 0, right = A.size() - 1;
	//	while (left < right)
	//	{
	//		if (A[left] % 2 != 0 && A[right] % 2 == 0)
	//		{
	//			swap(A[left], A[right]);
	//			left++;
	//			right--;
	//		}
	//		else if (A[left] % 2 == 0 && A[right] % 2 != 0)
	//		{
	//			left++;
	//			right--;
	//		}
	//		else if (A[left] % 2 != 0 && A[right] % 2 != 0)
	//			right--;
	//		else if (A[left] % 2 == 0 && A[right] % 2 == 0)
	//			left++;
	//	}
	//	return A;
	//}

	//int pivotIndex(vector<int>& nums) {
	//	int sum = 0, leftsum = 0;
	//	for (int i = 0; i < nums.size(); ++i)
	//		sum += nums[i]; //计算出总和
	//	for (int i = 0; i < nums.size(); ++i)
	//	{
	//		if (leftsum * 2 + nums[i] == sum)  //判断左边元素之和的两倍加上当前值是否与总和相等
	//			return i;
	//		leftsum += nums[i];
	//	}
	//	return -1;
	//}

	//vector<int> plusOne(vector<int>& digits) {
	//	for (int i = digits.size() - 1; i >= 0; --i)
	//	{
	//		if (digits[i] == 9)
	//		{
	//			digits[i] = 0;
	//			if (i == 0) //都是9的情况下
	//				digits.insert(digits.begin(), 1);
	//		}
	//		else
	//		{
	//			digits[i]++;  //最后一位小于9，++ 后结束循环返回
	//			break;
	//		}
	//	}
	//	return digits;
	//}

	//int thirdMax(vector<int>& nums) {
	//	sort(nums.begin(), nums.end());
	//	vector<int> num(1);
	//	num[0] = nums[0];
	//	for (int i = 0; i < nums.size(); ++i)
	//	{
	//		if (num.back()!=nums[i])
	//		{
	//			num.push_back(nums[i]);
	//		}
	//	}
	//	if (num.size() == 1)
	//		return num[0];
	//	else if (num.size() == 2)
	//		return num[1];
	//	return num[num.size() - 3];
	//}

	//vector<int> twoSum(vector<int>& nums, int target) 
	//{
	//	vector<int> Newnums(2);
	//	for (int i = 0; i < nums.size(); ++i)
	//	{
	//		for (int j = i + 1; j < nums.size(); ++j)
	//		{
	//			if (nums[i] + nums[j] == target)
	//			{
	//				Newnums[0] = i;
	//				Newnums[1] = j;
	//				return Newnums;
	//			}
	//		}
	//	}
	//	return Newnums;
	//}
	//string addBinary(string a, string b) {
	//	if (a.size() < b.size())  swap(a, b); //保证a最长
	//	reverse(a.begin(), a.end());  //倒序是为了保证两个字符串能够按照正确顺序将对应位相加
	//	reverse(b.begin(), b.end());
	//	int jinwei = 0;
	//	string ans;
	//	for (int i = 0; i < b.size(); i++) {
	//		if (a[i] - '0' + b[i] - '0' + jinwei >= 2) {
	//			ans += to_string((a[i] - '0' + b[i] - '0' + jinwei) % 2);
	//			jinwei = 1;
	//		}
	//		else {
	//			ans += to_string((a[i] - '0' + b[i] - '0' + jinwei) % 2);
	//			jinwei = 0;
	//		}
	//	}
	//	for (int i = b.size(); i < a.size(); i++) {
	//		if (a[i] - '0' + jinwei >= 2) {
	//			ans += to_string((a[i] - '0' + jinwei) % 2);
	//			jinwei = 1;
	//		}
	//		else {
	//			ans += to_string((a[i] - '0' + jinwei) % 2);
	//			jinwei = 0;
	//		}
	//	}
	//	if (jinwei == 1) ans += to_string(1);
	//	reverse(ans.begin(), ans.end());
	//	return ans;
	//}

	//int myAtoi(string str) {
	//	int res = 0;
	//	int i = 0;
	//	int flag = 1;
	//	// 1. 检查空格
	//	while (str[i] == ' ') { i++; }
	//	// 2. 检查符号
	//	if (str[i] == '-') { flag = -1; }

	//	if (str[i] == '+' || str[i] == '-') { i++; }
	//	// 3. 计算数字
	//	while (i < str.size() && isdigit(str[i])) {
	//		int r = str[i] - '0';
	//		// 4. 处理溢出
	//		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7)) {
	//			return flag > 0 ? INT_MAX : INT_MIN;
	//		}
	//		res = res * 10 + r;
	//		i++;
	//	}
	//	return flag > 0 ? res : -res;
	//}

	//vector<int> searchRange(vector<int>& nums, int target) {
	//	////二分法
	//	//int left = 0, right = nums.size() - 1;
	//	//int mid;
	//	//vector<int> res;
	//	//while (left <= right)  //找到目标数的位置
	//	//{
	//	//	mid = (left + right) / 2;
	//	//	if (nums[mid] > target)
	//	//		right = mid - 1;
	//	//	else if (nums[mid] < target)
	//	//		left = mid + 1;
	//	//	else break;
	//	//}
	//	//if (left > right)
	//	//{
	//	//	res.push_back(-1);
	//	//	res.push_back(-1);
	//	//	return res;
	//	//}
	//	////找左边界
	//	//left = 0, right = mid;
	//	//while (left < right)
	//	//{
	//	//	mid = (left + mid) / 2;
	//	//	if (nums[mid] != target)
	//	//		left = mid +1;
	//	//	else
	//	//		right = mid;
	//	//}
	//	//res.push_back(left);
	//	////找右边界
	//	//left = mid, right = nums.size() - 1;
	//	//while (left < right)
	//	//{
	//	//	mid = (left + right) / 2;
	//	//	if (nums[mid] != target)
	//	//		right = mid - 1;
	//	//	else
	//	//		left = mid;
	//	//}
	//	//res.push_back(left);
	//	//return res;
	//	//
	//	for (int i = 0; i < nums.size(); ++i)
	//	{
	//	int left = -1, right = -1;
	//	vector<int> res;
	//		if (left == -1 && nums[i] == target)
	//			left = i;
	//		if (nums[i] == target)
	//			right = i;
	//	}
	//	res.push_back(left);
	//	res.push_back(right);
	//	return res;

	//}

	bool isLetterOrNumber(char ch)
	{
		return (ch >= '0' && ch <= '9')
			|| (ch >= 'a' && ch <= 'z')
			|| (ch >= 'A' && ch <= 'Z');
	}
	bool isPalindrome(string s) {
		// 先小写字母转换成大写，再进行判断
		for (auto& ch : s)
		{
			if (ch >= 'a' && ch <= 'z')
				ch -= 32;
		}

		int begin = 0, end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end && !isLetterOrNumber(s[begin]))
				++begin;

			while (begin < end && !isLetterOrNumber(s[end]))
				--end;

			if (s[begin] != s[end])
			{
				return false;
			}
			else
			{

				++begin;
				--end;
			}
		}
		return true;
	}

};


struct HAR
{
	int x, y;
	struct HAR *p;
} h[2];
int main()
{
	/*h[0].x = 1;
	h[0].y = 2;
	h[1].x = 3;
	h[1].y = 4;
	h[0].p = &h[1];
	h[1].p = h;
	printf("%d,%d \n", (h[0].p)->x, (h[1].p)->y);*/

	char s[] = "abcdefgh", *p = s;
	p += 3;
	printf("%d\n", strlen(strcpy(p, "ABCD")));
	return 0;
}



//int a, b;
//void fun()
//{
//	a = 100; b = 200;
//}
//int main()
//{
//	int a = 5, b = 7; fun();
//	printf("% d % d / n", a, b);
//	return 0;
//}

//int f(int n)
//{
//	if (n)
//		return f(n - 1) + n;
//	else return n;
//}
//
//int fun(int x, int y)
//{
//	if (x == y)
//		return (x);
//	else
//		return((x + y) / 2);
//}
//int main()
//{
//	int a = 4, b = 5, c = 6;
//	printf("%d\n", fun(2 * a, fun(b, c)));
//}

//int main()
//{
//	/*const char *p = "abcdefgh", *r;
//	long *q; q = (long*)p;
//	q++;
//	r = (char*)q;
//	printf("%s\n", r);*/
//	/*char str[] = "ABCD", *p = str;
//	printf("%d\n", *(p + 4));*/
//	
//	cout << f(4) << endl;
//
//	return 0;
//}


//int main()
//{
//	/*Solution v;
//	vector<int> nums = { 1,2,3,3,1 };
//	int length = v.removeElement(nums, 3);
//	cout << length << endl;;*/
//
//	/*Solution str;
//	string s = "hello world";
//	int length1 = str.lengthOfLastWord(s);
//	cout << s.length()<<endl;
//	cout << length1 << endl;*/
//	
//	Solution a;
//	vector<int>nums1 = { 1,2,3,0,0,0 };
//	vector<int>nums2 = { 2,5,6 };
//	int m = 3, n = 3;
//	//a.merge(nums1, m, nums2, n);
//	/*for (auto x : nums1)
//		cout << x << " ";
//	cout << endl;*/
//	//cout << a.containsDuplicate(nums1) << endl;
//	vector<int> A = { -4,-1,0,3,10 };
//
//	vector<int> B = a.sortedSquares(A);
//	for(auto x : B)
//		cout << x << " ";
//	cout << endl;
//	return 0;
//}

/*
class Solution {
public:
	string ToLowerCase(string str)
	{
		for (auto& ch : str)
		{
			if (ch >= 'A'&&ch <= 'Z')
				ch += 32;
		}
		return str;
	}
};
class Solution {
public:
	void reverse(vector<int>& nums, int start, int end)
	{
		//反转函数
		while (start < end)
		{
			int tmp = nums[start];
			nums[start++] = nums[end];
			nums[end--] = tmp;
		}
	}
	void rotate(vector<int>& nums, int k) {
		if (k <= 0)
			return;
		int size = nums.size();
		if (k > size)
			k = k % size;
		reverse(nums, 0, size - k - 1); //对前size-k个元素反转
		reverse(nums, size - k, size - 1);//对后k个元素反转
		reverse(nums, 0, size - 1);//整体进行反转
	}
};

int main()
{
	Solution s;
	vector<int> nums = { 1,2,3,4,5,6,7,8,9 };
	s.rotate(nums, 4);
	vector<int>::const_iterator it = nums.begin();
	while (it != nums.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}
*/