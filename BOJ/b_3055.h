#include <iostream>
#include <queue>

using namespace std;
int r, c,sy,sx,ans;
char board[51][51];
bool check[51][51];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue < pair<pair<int, int>, int>> q;
queue <pair<int, int>> wq;
int bfs()
{
	while (!q.empty())
	{
		int wqsize = wq.size();
		int qsize = q.size();
		for (int i = 0; i < wqsize; i++)
		{
			int y = wq.front().first;
			int x = wq.front().second;
			wq.pop();
			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 0 && nx >= 0 && ny < r && nx < c && board[ny][nx] == '.')
				{
					board[ny][nx] = '*';
					wq.push({ ny,nx });
				}
			}
		}
		for (int i = 0; i < qsize; i++)
		{
			int y = q.front().first.first;
			int x = q.front().first.second;
			int cnt = q.front().second;
			q.pop();
			if (board[y][x] == 'D')
				return cnt;
			for (int j = 0; j < 4; j++)
			{
				int ny = y + dy[j];
				int nx = x + dx[j];
				if (ny >= 0 && nx >= 0 && ny < r && nx < c && board[ny][nx]!= '*' && board[ny][nx]!='X' && check[ny][nx]==0)
				{
					check[ny][nx] = true;
					q.push({ {ny,nx},cnt + 1 });
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
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		cin >> board[i];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == 'S')
			{
				q.push({ { i,j },0 });
				board[i][j] = '.';
				check[i][j] = true;
			}
			if (board[i][j] == '*')
			{
				wq.push({ i,j });
			}
		}
	}
	ans = bfs();
	if (ans == -1)
		cout << "KAKTUS";
	else
		cout << ans;
	return 0;
}
