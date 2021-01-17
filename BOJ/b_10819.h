#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int n, arr[8],sel[8],ans=-987654321;
bool check[8];
void dfs(int cnt)
{
	if (cnt == n)
	{
		int result = 0;
		for (int i = 0; i < n - 1; i++)
			result += abs(sel[i] - sel[i + 1]);
		ans = max(ans, result);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			sel[cnt] = arr[i];
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
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dfs(0);
	cout << ans;
	return 0;
}
