#include <iostream>
#include <queue>
using namespace std;
int ans,n,board[21][21];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
struct shark
{
	int y,x,sz,cnt;
};
shark sh;
bool bfs()
{
	bool check[21][21] = { 0, };
	queue <pair<pair<int, int>, int>> q;
	check[sh.y][sh.x] = true;
	q.push({ {sh.y,sh.x},0 });
	int ey=21, ex=21,ecnt=987654321;
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (cnt > ecnt)
			break;
		if (board[y][x]!=0 && board[y][x] < sh.sz)
		{
			if (cnt <ecnt)
			{
				ey = y;
				ex = x;
				ecnt = cnt;
			}
			else if (ecnt == cnt)
			{
				if (y < ey)
				{
					ey = y;
					ex = x;
				}
				else if (y == ey)
				{
					if (x < ex)
					{
						ex = x;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n && check[ny][nx]==0)
			{
				if(board[ny][nx] <= sh.sz)
				{
					check[ny][nx] = true;
					q.push({ {ny,nx},cnt + 1 });
				}
			}
		}
	}
	if (ecnt == 987654321)
		return false;
	else
	{
		ans += ecnt;
		sh.cnt += 1;
		sh.y = ey;
		sh.x = ex;
		if (sh.cnt == sh.sz)
		{
			sh.sz += 1;
			sh.cnt = 0;
		}
		board[ey][ex] = 0;
		return true;
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 9)
			{
				sh.y = i;
				sh.x = j;
				sh.sz = 2;
				sh.cnt = 0;
				board[i][j] = 0;
			}
		}
	}
	while (1)
	{
		if (!bfs())
			break;
	}
	cout << ans;
	return 0;
}
