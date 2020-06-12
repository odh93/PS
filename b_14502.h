#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m,arr[9][9],zcnt,ans;
vector <pair<int, int>> v,z;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
/* 1. 0인 위치와 2(바이러스)의 위치를 벡터에 저장
   2. 조합형태의 dfs로 3개의 벽을 설치 후 bfs
   3. 0의 개수를 세어놓고 bfs로 체크하고 최댓값을 찾아준다.
*/
void bfs()
{
	queue <pair<int, int>> q;
	bool check[9][9] = { 0, };
	int tzcnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		check[v[i].first][v[i].second] = true;
		q.push({ v[i].first,v[i].second });
	}
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m)
				continue;
			if (check[ny][nx] || arr[ny][nx] != 0)
				continue;
			check[ny][nx] = true;
			tzcnt += 1;
			q.push({ ny,nx });
		}
	}
	ans = max(ans, zcnt - tzcnt);
}
void dfs(int cur, int cnt)
{
	if (cnt == 3) // 벽을 3개 세웠을때 bfs
	{
		bfs();
		return;
	}
	if (cur >= z.size())
		return;
	for (int i = cur; i < z.size(); i++)
	{
		zcnt -= 1;
		arr[z[i].first][z[i].second] = 1; 
		dfs(i + 1, cnt + 1);
		zcnt += 1;
		arr[z[i].first][z[i].second] = 0;
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
			cin >> arr[i][j];
			if (arr[i][j] == 0)
			{
				z.push_back({ i,j });
				zcnt += 1;
			}
			if (arr[i][j] == 2)
				v.push_back({ i,j });
		}
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}
