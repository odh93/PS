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

	/* 첫번째 행부터 차례로 각 구역에 배치하는 경우의수를 
	bottom-up방식으로 갱신하며 경우의수를 dp배열에 메모이제이션 해준다.
	dp[n][0]은 n번째 행에 왼쪽에 사자를 배치할 때, dp[n][1]은 오른쪽에 배치할때,
	dp[n][2]은 배치하지 않을때로 저장해준다.*/
	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % mod; 
		// n번째의 왼쪽의 사자를 넣을대의 경우의수는 그전index까지의 오른쪽에 배치할때 배치하지 않을때를 더한 값이다.
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
		// n번째의 오른쪽의 사자를 넣을대의 경우의수는 그전index까지의 왼쪽에 배치할때 배치하지 않을때를 더한 값이다.
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i-1][2]) % mod;
		// n번째의 사자를 배치하지 않을때는 그전까지의 모든 경우의수를 더해준 경우의수다.
	}
	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod;
	return 0;
}
