#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1001;
int n, m, k, can_break[MAX][MAX];
char board[MAX][MAX];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int bfs()
{
	queue <pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {0,0},{1,0} });
	bool day = false;
	while (!q.empty())
	{
		day = !day;
		int qsize = q.size();
		for (int i = 0; i < qsize; i++)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int curdist = q.front().second.first;
			int curk = q.front().second.second;
			q.pop();
			if (y == n - 1 && x == m - 1)
				return curdist;
			if (!day)
				q.push({ {y,x},{curdist + 1,curk} });
			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 0 && nx >= 0 && ny < n && nx < m)
				{
					if (can_break[ny][nx] <= curk)
						continue;
					if (board[ny][nx] == '0')
					{
						can_break[ny][nx] = curk;
						q.push({ {ny,nx},{curdist + 1,curk} });
					}
					else
					{
						if (curk >= k || !day)
							continue;
						can_break[ny][nx] = curk;
						q.push({ {ny,nx},{curdist + 1,curk + 1} });
					}
				}

			}
		}
	}
	return -1;
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			can_break[i][j] = k + 1;
		}
	}
	cout << bfs();
	return 0;
}
