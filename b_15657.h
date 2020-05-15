#include <iostream>
#include <algorithm>
using namespace std;
int n, m,arr[9],sel[9];
void dfs(int cur, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << sel[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = cur; i < n; i++)
	{
		sel[cnt] = arr[i];
		dfs(i, cnt + 1);
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
		cin >> arr[i];
	sort(arr, arr + n);
	dfs(0, 0);
	return 0;
}
