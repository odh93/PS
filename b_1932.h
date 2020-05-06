#include <iostream>
#include <algorithm>
using namespace std;

int n,arr[501][501],dp[501][501];
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	
	dp[0][0] = arr[0][0];
	int ans = dp[0][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			if (j == 0)
				dp[i][j] = dp[i - 1][j] + arr[i][j];
			else if (j == i)
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}
