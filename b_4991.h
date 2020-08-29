#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
struct pt
{
	int y;
	int x;
};
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int w, h, ans;
char map[21][21];
int pdist[11][11];
int sy, sx;
bool check[21][21];
bool usept[11];
vector <pt> v;
void dfs(int cnt, int cur, int sum)
{
	if (sum > ans)
		return;
	if (cnt == v.size())
	{
		if (sum < ans)
		{
			ans = sum;
		}
		return;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (usept[i])
			continue;
		usept[i] = true;
		dfs(cnt + 1, i, sum + pdist[cur][i]);
		usept[i] = false;
	}
}
int dist(int y1, int x1, int y2, int x2)
{
	memset(check, 0, sizeof(check));
	queue <pair<pt, int>> q;
	q.push({ { y1,x1 },0 });
	check[y1][x1] = true;
	int res = -1;
	while (!q.empty())
	{
		int cy = q.front().first.y;
		int cx = q.front().first.x;
		int cnt = q.front().second;
		q.pop();
		if (cy == y2 && cx == x2)
		{
			res = cnt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || nx < 0 || ny >= h || nx >= w)
				continue;
			if (map[ny][nx] == 'x')
				continue;
			if (check[ny][nx])
				continue;
			check[ny][nx] = true;
			q.push({ {ny,nx},cnt + 1 });
		}
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while (1)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
			return 0;

		ans = 999999999;
		v.clear();
		memset(usept, 0, sizeof(usept));
		memset(pdist, 0, sizeof(pdist));
		v.push_back({ 0,0 });
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];

				if (map[i][j] == '*')
					v.push_back({ i,j });
				if (map[i][j] == 'o')
				{
					sy = i;
					sx = j;
					map[i][j] = '.';
					v[0].y = sy;
					v[0].x = sx;
				}
			}
		}

		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = 1; j < v.size(); j++)
			{
				if (i == j)
					continue;
				int temp = dist(v[i].y, v[i].x, v[j].y, v[j].x);
				if (temp == -1)
					ans = -1;
				pdist[i][j] = temp;
				pdist[j][i] = temp;
			}
		}
		if (ans != -1)
		{
			usept[0] = true;
			dfs(1, 0, 0);
		}
		cout << ans;
	}
}
