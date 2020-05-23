#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector <int> v[2001];
bool check[2001];
void dfs(int idx,int cnt)
{
	if (cnt == 5)
	{
		cout << 1;
		exit(0);
		return;
	}
	check[idx] = true;
	for (int i = 0; i < v[idx].size(); i++)
	{
		if (!check[v[idx][i]])
			dfs(v[idx][i], cnt + 1);
	}
	check[idx] = false;
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
	{
		memset(check, 0, sizeof(check));
		dfs(i, 1);
	}
	cout << 0;
	return 0;
}
