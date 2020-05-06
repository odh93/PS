#include <iostream>
using namespace std;
int N, A[1001],dp[1001],ans;
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	for (int i = 1; i <= N; i++)
	{
		dp[i] = A[i];

		for (int j = 1; j < i; j++)
		{
			if (A[j] < A[i] && dp[i] < dp[j] + A[i])
				dp[i] = dp[j] + A[i];
		}
		if (ans < dp[i])
			ans = dp[i];
	}
	cout << ans;
	return 0;
}
