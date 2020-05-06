#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001],dp[1001],ans;
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	ans = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
