#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, board[501][501],ans;
bool check[501][510];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void dfs(int y, int x, int cnt,int sum)
{
	sum += board[y][x];
	ans = max(ans, sum);
	if (cnt == 4)
		return;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (check[ny][nx])
			continue;
		check[ny][nx] = true;
		dfs(ny, nx, cnt + 1,sum);
		check[ny][nx] = false;
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			check[i][j] = true;
			dfs(i, j, 1,0);
			check[i][j] = false;

			if (i+1 <n && j+2 <m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
				ans = max(ans, temp);
			}

			if (i - 1 >= 0 && j + 2 < m)
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 1];
				ans = max(ans, temp);
			}
			if (i + 2 < n && j + 1 < m)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
				ans = max(ans, temp);
			}

			if (i + 2 < n && j - 1 >= 0)
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1];
				ans = max(ans, temp);
			}
		}
	}
	cout << ans;
	return 0;
}
