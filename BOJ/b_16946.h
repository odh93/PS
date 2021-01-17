#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
const int MAX = 1001;
int n, m,zerocnt,group[MAX][MAX];
bool check[MAX][MAX];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
char board[MAX][MAX];
vector <int> group_size;
void bfs(int sy, int sx)
{
	int g = group_size.size();
	queue <pair<int, int>> q;
	q.push({ sy,sx });
	check[sy][sx] = true;
	group[sy][sx] = g;
	int cnt = 1;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m)
			{
				if (board[ny][nx] == '0' && check[ny][nx] == 0)
				{
					q.push({ ny,nx });
					check[ny][nx] = true;
					group[ny][nx] = g;
					cnt += 1;
				}
			}
		}
	}
	group_size.push_back(cnt);
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '0' && check[i][j] == 0)
				bfs(i, j);
		}	
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '0')
				cout << 0;
			else
			{
				set<int> near;
				for (int k = 0; k < 4; k++)
				{
					int y = i + dy[k];
					int x = j + dx[k];
					if (y >= 0 && x >= 0 && y < n && x < m)
					{
						if (board[y][x] == '0')
							near.insert(group[y][x]);
					}
				}
				int ans = 1;
				for (int k : near)
					ans += group_size[k];
				cout << ans % 10;
			}
		}
		cout << '\n';
	}
	return 0;
}
