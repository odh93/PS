#include <iostream>
using namespace std;
int n;
long long dp[100001][3], mod = 9901;
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	dp[1][0] = 1 % mod, dp[1][1] = 1 % mod, dp[1][2] = 1 % mod;
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i-1][2]) % mod;
	}
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
	return 0;
}
