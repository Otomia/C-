#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

typedef struct Queue
{
	stack<int> st1;  // »Î’ª
	stack<int> st2;  // ≥ˆ’ª
}Queue;

void Inite(Queue *q,int maxSize) {
	q = (Queue*)malloc(sizeof(Queue));
	
	return q;

}

void add(Queue* q, int key) 
{
	q->st1.push(key);
}

int poll(Queue* q) {
	if (!q->st2.empty())
	{
		while (q->st1.empty() != 0)
		{
			q->st2.push(q->st1.top());
			q->st1.pop();
		}
	}
	int front = q->st2.top();
	q->st2.pop();
	return front;
}

int peek(Queue* q) {
	if (!q->st2.empty())
	{
		while (q->st1.empty() != 0)
		{
			q->st2.push(q->st1.top());
			q->st1.pop();
		}
	}
	return q->st2.top();
}

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> vt(n);
		for (int i = 0; i < n; ++i)
			getline(cin, vt[i]);
		Queue q;
		for (int i = 0; i < n; ++i)
		{
			if (vt[i].find("add") != string::npos)
			{
				string s;
				for (int j = 4; j < vt[i].size(); ++j)
					s += vt[i][j];
				int key = stoi(s);
				add(&q,key);
			}
		}
	}
	return 0;
}

//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		for (int k = 0; k < num; k++)
//		{
//			int n;
//			cin >> n;
//			vector<vector<int>> A(n);
//			vector<vector<int>> B(n);
//			for (int i = 0; i < n; ++i)
//			{
//				A[i].resize(2);
//				B[i].resize(2);
//			}
//			for (int i = 0; i < n; ++i)
//			{
//				for (int j = 0; j < 2; ++j)
//					cin >> A[i][j];
//			}
//			for (int i = 0; i < n; ++i)
//			{
//				for (int j = 0; j < 2; ++j)
//					cin >> B[i][j];
//			}
//			double min = 10000, tmp;
//			for (int i = 0; i < n; ++i)
//			{
//				for (int j = i; j < n; j++)
//				{
//					double a = pow((A[j][0] - B[j][0]), 2) + pow((A[j][1] - B[j][1]), 2);
//					tmp = sqrt(a);
//					if (tmp < min)
//						min = tmp;
//				}
//			}
//			printf("%0.3f\n", min);
//		}
//	}
//
//}

//typedef struct Queue
//{
//	int *base;
//	size_t capacity;
//	size_t front;
//	size_t tail;
//}Queue;
//void add(Queue *q,int key)
//{
//	stack<int> s1, stack<int>s2;
//
//}

//int main()
//{
//	int N;
//	while (cin >> N)
//	{
//		vector<string> vt(N);
//		vector<int> q;
//		for (int i = 0; i < N; ++i)
//			getline(cin, vt[i]);
//	}
//}

//using namespace std;
//typedef struct Queue
//{
//	int *base;
//	size_t capacity;
//	size_t front;
//	size_t tail;
//}Queue;
//
//
//
//
//void PUSH( vector<int> a, int key)
//{
//	a.insert(a.end()+1, key);
//}
//
//int TOP(vector<int> a)
//{
//	if (a.empty())
//		return -1;
//	return a[0];
//}
//bool POP(vector<int> a)
//{
//	if (a.empty())
//		return false;
//	else
//	{
//		a.erase(a.begin());
//		return true;
//	}
//}
//
//size_t SIZE(vector<int> a)
//{
//	return a.size();
//}
//
//void CLEAR(vector<int> a)
//{
//	a.erase(a.begin(), a.end());
//}
//int main()
//{
//	int T, Q;
//	while (cin >> T)
//	{
//		for (int i = 0; i < T; ++i)
//		{
//			cin >> Q;
//			vector<string> vt(Q);
//			vector<int> q;
//			for (int j = 0; j < Q; ++i)
//				getline(cin, vt[j]);
//			for (int j = 0; j < Q; ++i)
//			{
//				if (vt[j].find("PUSH") != string::npos)
//				{
//					string s;
//					for (int k = 5; j < vt[j].size(); ++k)
//						s += vt[j][k];
//					int key = stoi(s);
//					PUSH(q, key);
//				}
//				else if (vt[j].find("POP") != string::npos)
//				{
//					if (!POP(q))
//						cout << "-1" << endl;
//				}
//				else if (vt[j].find("TOP") != string::npos)
//				{
//					int top = TOP(q);
//					cout << top << endl;
//				}
//				else if (vt[j].find("SIZE") != string::npos)
//				{
//					cout << SIZE(q) << endl;
//				}
//				else if (vt[j].find("CLEAR") != string::npos)
//					CLEAR(q);
//			}
//		}
//	}
//	return 0;
//}