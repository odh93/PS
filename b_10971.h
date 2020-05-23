#include <iostream>
#include <algorithm>
using namespace std;
int n,dist[11][11],ans=987654321;
bool check[11];
void dfs(int cur, int cnt,int sum,int start)
{
	if (cnt == n - 1)
	{
		if (dist[cur][start] != 0)
			ans = min(ans, sum + dist[cur][start]);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!check[i] && dist[cur][i] != 0)
		{
			check[i] = true;
			dfs(i, cnt + 1, sum + dist[cur][i],start);
			check[i] = false;
		}
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> dist[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		check[i] = true;
		dfs(i, 0, 0,i);
		check[i] = false;
	}
	cout << ans;
	return 0;
}
