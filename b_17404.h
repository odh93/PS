#include <iostream>
#include <algorithm>
using namespace std;
int ans = 987654321,n,arr[1001][3],dp[1001][3];
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				dp[1][j] = arr[1][j];
			else
				dp[1][j] = 987654321;
		}

		for (int j = 2; j <= n; j++)
		{
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + arr[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + arr[j][2];
		}

		for (int j = 0; j < 3; j++)
		{
			if (i == j)
				continue;
			ans = min(ans, dp[n][j]);
		}
	}
	cout << ans;
	return 0;
}
