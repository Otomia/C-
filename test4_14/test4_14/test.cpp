#include<iostream>
#include<string>
#include<vector>

using namespace std;

void Find(int &col, int &row,vector<vector<string>> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (v[i][j] == "@")
			{
				col = i;
				row = j;
			}
		}
	}
}

void Count(int &count,int col,int row,vector<vector<string>> v)
{
	if (col<0 || col>v.size() - 1 || row<0 || row>v[0].size() - 1 || v[col][row] == "#")
		return;
	count++;
	v[col][row] == "#";
	Count(count, col - 1, row, v); //ио
	Count(count, col + 1, row, v); // об
	Count(count, col, row - 1, v); //вС
	Count(count, col, row + 1, v); // ср
}
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		vector<vector<string>> vt(m);
		for (int i = 0; i < m; ++i)
			vt[i].resize(n);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
				cin >> vt[i][j];
		}
		int count = 0;
		int col = 0, row = 0;
		Find(col, row, vt);
		Count(count, col, row, vt);
		
		cout << count << endl;
	}
	return 0;
}