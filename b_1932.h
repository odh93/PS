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
	
	dp[0][0] = arr[0][0]; // 가장 위의 값
	int ans = dp[0][0];  // botoom - up 방식
	
	/* 경로의 있는 수의 합을 구하는 문제이니 각 위치의 dp배열에
	  지금 까지의 위에서 올 수 있는 합의 최대치를 메모이제이션 해준다.
	  왼쪽끝과 오른쪽끝을 예외case로 하여 계산한다. 
	  (삼각형의 특성상 오른쪽끝과 왼쪽끝은 경로가 하나다.)
	   */
	for (int i = 1; i < n; i++) // 행
	{
		for (int j = 0; j <= i; j++) // 열
		{
			if (j == 0)  // 삼각형의 왼쪽부분, 바로 위칸의 왼쪽경로에서 올 수 있는 최대값을 더해준다.
				dp[i][j] = dp[i - 1][j] + arr[i][j]; 
			else if (j == i) // 삼각형의 오른쪽부분, 바로 위칸의 오른쪽경로에서 올 수 있는 최대값을 더해준다.
				dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else // 나머지 칸, 위쪽칸의 왼쪽과 오른쪽 중 더 큰 합을 가지는 경로의 값을 더해준다.
				dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
			ans = max(ans, dp[i][j]); // 매 진행시 최대의 합을 정답에 갱신
		}
	}
	cout << ans;
	return 0;
}
