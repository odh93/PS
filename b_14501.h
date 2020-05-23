#include <iostream>
#include <algorithm>
using namespace std;
int n, t[16], p[16],ans;
void dfs(int cur, int psum)
{
	if (cur == n + 1)
	{
		ans = max(ans, psum);
		return;
	}
	if (cur + t[cur] <= n + 1)
		dfs(cur + t[cur], psum + p[cur]);
	dfs(cur + 1, psum);
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	dfs(1, 0);
	cout << ans;
	return 0;
}
