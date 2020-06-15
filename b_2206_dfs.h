#include <iostream>
using namespace std;
int n, m, ans=987654321;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char board[1001][1001];
bool check[1001][1001], can_break;
void dfs(int y, int x, int cnt)
{
	if (ans < cnt + (n - y) + (m - x))
		return;
	if (y == n - 1 && x == m - 1)
	{
		if (ans > cnt)
			ans = cnt;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && ny < n && nx >= 0 && nx < m && check[ny][nx]==0)
			{
				if (board[ny][nx] == '0')
				{
					check[ny][nx] = 1;
					dfs(ny, nx, cnt + 1);
					check[ny][nx] =0;
				}
				else if (can_break==0)
				{
					check[ny][nx] =1;
					can_break =1;
					dfs(ny, nx, cnt + 1);
					can_break =0;
					check[ny][nx] =0;
				}
			}
		}
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	check[0][0] = 1;
	dfs(0, 0, 1);
	if (ans == 987654321)
		cout << -1;
	else
		cout << ans;
	return 0;
}
