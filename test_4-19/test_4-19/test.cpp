// 走迷宫
// 输入  10x10的迷宫矩阵
/*
#.########
#........#
#........#
#........#
#........#
#........#
#........#
#........#
#........#
########.#

//

#.########
#........#
########.#
#........#
#.########
#........#
########.#
#........#
#.######.#
########.#
*/
// 输出从入口到出口的最短步数
// 16
// 30
// BFS 解法，利用队列(先进先出)

#define _CRT_SECURE_NO_WARNINGS -1
#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

struct pos { int x, y, level; };

int bfs(vector<vector<char>> &map)
{
	const int dir[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
	queue<pos> q;
	int m = map.size(), n = map[0].size();
	vector<vector<bool>> visit(m, vector<bool>(n, false));
	pos start{ 0,1,0 }, end{ 9,8,0 };
	q.push(start);
	visit[start.x][start.y] = true;
	while (!q.empty())
	{
		pos cur = q.front(), next;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			next.x = cur.x + dir[i][0];
			next.y = cur.y + dir[i][1];
			next.level = cur.level + 1;
			if (next.x == end.x&&next.y == end.y)
				return next.level;
			if (next.x >= 0 && next.x < m && next.y >= 0 && next.y < n
				&& !visit[next.x][next.y] && map[next.x][next.y] == '.')
			{
				q.push(next);
				visit[next.x][next.y] = true;
			}
		}
	}
	return 0;
}
int main()
{
	vector<vector<char>> map(10, vector<char>(10));
	while (cin >> map[0][0])
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{
				if (i == 0 && j == 0)
					continue;
				cin >> map[i][j];
			}
		}
		cout << bfs(map) << endl;
	}
	return 0;
}
// 解读密码
// 输入 $Ts!47&*s456  a23* +B9k
// 输出 47456239

//#include<iostream>
//#include<string>
//#include<queue>
//using namespace std;
//int main()
//{
//	string s;
//	while (getline(cin, s))
//	{
//		queue<int> Q;
//		for (int i = 0; i < s.size(); ++i)
//		{
//			if (s[i] >= '0'&&s[i] <= '9')
//			{
//				Q.push(s[i] - '0');
//			}
//		}	
//		while(!Q.empty())
//		{
//			cout << Q.front();
//			Q.pop();
//		}
//		cout << endl;
//	}
//	return 0;
//}