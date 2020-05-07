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

	/* dp[k][n] =k가 선택해서 합이 n이 되는 경우의수로 botoom-up방식으로 진행할
	dp배열을 만들어 준다.
	dp를 갱신하는 방법은 선택한 수의 숫자로 bottom-up을 진행해주는데 
	 dp[a][i] , a가 선택해서 i를 만들 수 있는 경우의수는 a-1개 선택한 0부터 i까지의 dp배열을 더해주는 것이다.
	 i이하의 수는 어떤 수이든 하나의 수를 더해서 i를 만들 수 있기 때문이다.*/
	for (int a = 2; a <= k; a++)
	{
		for (int i = 0; i <= n; i++) // 만들고 싶은 수
		{
			for (int j = 0; j <= i; j++) // 그 수이하의 수의 dp를 다 더해준다.
			{
				dp[a][i] += dp[a - 1][j] % mod;
			}
		}
	}
	cout << dp[k][n] % mod;
	return 0;
}
