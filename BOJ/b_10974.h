#include <iostream>

using namespace std;

int n, sel[9];
bool check[9];
void dfs(int cnt)
{
	if (cnt == n)
	{
		for (int i = 0; i < n; i++)
			cout << sel[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			sel[cnt] = i;
			dfs(cnt + 1);
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
	dfs(0);
	return 0;
}
