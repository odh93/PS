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

	/* 홀수의 경우는 항상 0
	   n=2일때 f(2) = 3
	   n>=4 이상일때부터 특수케이스가 2개씩
	   그 전 경우를 f(n)= f(n-2)*f(2) + 그전까지의 dp*(특수케이스 수)
	   로 점화식을 세울수 있다.*/
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 2] * 3; // 바로 이전 경우에 dp[2]의 경우의 수를 곱해준다

		for (int j = 4; j <= i; j += 2) // 그 전까지의 dp들과 특수케이스를 곱해준다.
		{
			dp[i] += dp[i - j] * 2;
		}
	}
	cout << dp[n];
	return 0;
}
