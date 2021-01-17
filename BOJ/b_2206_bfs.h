#include <iostream>
#include <queue>
#include <string>
using namespace std;
int n, m;
string board[1001];
bool check[1001][1001][2];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int bfs()
{
	queue <pair<pair<int, int>,pair<bool,int>>> q;
	check[0][0][0] = false;
	q.push({ {0,0},{false,1} });
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		bool can_break = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if (y == n - 1 && x == m - 1)
			return cnt;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (can_break == false)
			{
				if (board[ny][nx] == '0' && !check[ny][nx][0])
				{
					check[ny][nx][0] = true;
					q.push({ {ny,nx},{false,cnt + 1} });
				}
				if (board[ny][nx] == '1' && !check[ny][nx][1])
				{
					check[ny][nx][1] = true;
					q.push({ {ny,nx},{true,cnt + 1} });
				}
			}
			else
			{
				if (board[ny][nx] == '0' && !check[ny][nx][1])
				{
					check[ny][nx][1] = true;
					q.push({ {ny,nx},{true,cnt + 1} });
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
	cin.tie(NULL),cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	cout << bfs();
	return 0;
}
