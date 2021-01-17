#include <iostream>
#include <queue>
using namespace std;
int w, h,sy,sx,ey,ex,dist[101][101];
char board[101][101];
bool flag;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int bfs()
{
	queue <pair<int, int>> q;
	q.push({ sy,sx });
	dist[sy][sx] = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x+dx[i];
			while (ny >= 0 && nx >= 0 && ny < h && nx < w)
			{
				if (board[ny][nx] == '*')
					break;
				if (dist[ny][nx] == -1)
				{
					dist[ny][nx] = dist[y][x] + 1;
					q.push({ ny,nx });
				}
				ny += dy[i];
				nx += dx[i];
			}
		}
	}
	return dist[ey][ex] - 1;
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			dist[i][j] = -1;
			cin >> board[i][j];
			if (board[i][j] == 'C')
			{
				if (!flag)
				{
					sy = i;
					sx = j;
					board[i][j] = '.';
					flag = true;
				}
				else
				{
					ey = i;
					ex = j;
					board[i][j] = '.';
				}
			}
		}
	}
	cout << bfs();
	return 0;
}
