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
	/* 1번집과 n번집의 색깔이 달라야 하는 것에 초점을 둬서
	첫번째집의 색을 정하고 그것을 기준으로 dp를 따로 세워준다*/
	for (int i = 0; i < 3; i++) // 첫번째집의 색을 정하는 for문
	{
		for (int j = 0; j < 3; j++) // 그 색이 일치하면 값을 주고 아니면 선택할 수 없게 최대값이상의 값을준다.
		{
			if (i == j)
				dp[1][j] = arr[1][j];
			else
				dp[1][j] = 987654321;
		}

		for (int j = 2; j <= n; j++) // 순서대로 빨강,초록,파랑을 0,1,2배열에
		{
			dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + arr[j][0];
			dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + arr[j][1];
			dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + arr[j][2];
		}

		for (int j = 0; j < 3; j++)
		{
			if (i == j) // 마지막배열은 첫번째집의 색과 다른색들만 갱신해준다.
				continue;
			ans = min(ans, dp[n][j]);
		}
	}
	cout << ans;
	return 0;
}
