#include <iostream>

using namespace std;

int n, k;
long long dp[201][201],mod = 1000000000;
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	for (int i = 0; i <= n; i++)
		dp[1][i] = 1 % mod;
	for (int a = 2; a <= k; a++)
	{
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				dp[a][i] += dp[a - 1][j] % mod;
			}
		}
	}
	cout << dp[k][n] % mod;
	return 0;
}
