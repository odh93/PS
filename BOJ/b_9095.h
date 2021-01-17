#include <iostream>
#include <algorithm>

using namespace std;

int T,dp[12],n;
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	/* 1,2,3의 합으로 나타내는 방법의 수를 배열에 저장하여
	1,2,3을 만드는 방법의 수를 초기값으로 선언하고 bottom-up방식으로
	i의 값에서 1을 뺏을때 2를 뺏을때 3을 뺏을때의 방법의 수를 더해주어 해결*/
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	for (int t =1; t <= T; t++)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}
