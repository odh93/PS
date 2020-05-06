#include <iostream>
using namespace std;
int n;
long long dp[31];
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	dp[0] = 1, dp[2] = 3;
	cin >> n;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 2] * 3;

		for (int j = 4; j <= i; j += 2)
		{
			dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[n];
	return 0;
}
