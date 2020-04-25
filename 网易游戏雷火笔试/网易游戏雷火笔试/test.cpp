//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	int N, M;
//	while (cin >> N >> M)
//	{
//
//	}
//	return 0;
//}


//钱老板放广告牌
#include<iostream>
#include<vector> 
using namespace std;

int main()
{
	short N;
	while (cin >> N)
	{
		vector<short> vt(N);
		for (int i = 0; i < N; ++i)
			cin >> vt[i];
		long S = 0, S1 = 0;
	
		for (int i = 0; i < N; ++i)
		{
			int H = 100000;
			for (int j = i; j < N; ++j)
			{
				if (H > vt[j]) // 判断最小高度
					H = vt[j];
				S1 = H * (j - i + 1);// 面积
				if (S1 > S)
					S = S1; //最大面积
			}
		}
		cout << S << endl;
	}
	return 0;
}


// 钱老板搭积木
//#include<iostream>
//#include<vector>
//
//using namespace std;
//int main()
//{
//	int N;
//	while (cin >> N)
//	{
//		vector<vector<int>> vt(N);
//		for (int i = 0; i < N; ++i)
//			vt[i].resize(3);
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < 3; ++j)
//			{
//				cin >> vt[i][j];
//			}
//		}
//		int S = 0, S1 = N * 6;
//		int count = 0;// 紧贴的面的个数
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = i; j < N; ++j)
//			{
//				if (j == N - 1)
//					break;
//				else if (j < N - 1 && (vt[i][0] - vt[j + 1][0] == 1 && vt[i][1] == vt[j + 1][1] && vt[i][2] == vt[j + 1][2])
//					|| (vt[i][0] == vt[j + 1][0] && vt[i][1] - vt[j + 1][1] == 1 && vt[i][2] == vt[j + 1][2])
//					|| (vt[i][0] == vt[j + 1][0] && vt[i][1] == vt[j + 1][1] && vt[i][2] - vt[j + 1][2] == 1))
//				{
//					count++;
//				}
//				else if (j < N - 1 && (vt[i][0] - vt[j + 1][0] == -1 && vt[i][1] == vt[j + 1][1] && vt[i][2] == vt[j + 1][2])
//					|| (vt[i][0] == vt[j + 1][0] && vt[i][1] - vt[j + 1][1] == -1 && vt[i][2] == vt[j + 1][2])
//					|| (vt[i][0] == vt[j + 1][0] && vt[i][1] == vt[j + 1][1] && vt[i][2] - vt[j + 1][2] == -1))
//				{
//					count++;
//				}
//			}
//			
//		}
//		S = S1 - (2 * count);
//		cout << S << endl;
//	}
//	return 0;
//}