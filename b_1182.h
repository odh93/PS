#include <iostream>
using namespace std;
int n, s, arr[21], ans;
void dfs(int cur, int sum)
{
	if (cur == n)
	{
		if (sum == s)
			ans += 1;
		return;
	}
	dfs(cur + 1, sum);
	dfs(cur + 1, sum + arr[cur]);
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dfs(0, 0);
	if (s == 0)
		ans -= 1;
	cout << ans;
	return 0;
}
