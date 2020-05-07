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
	/* 문제에서 답으로 요구하는 값은 가장 큰 증가 부분 수열의 합의 값이다.
	   따라서 dp배열에는 왼쪽에서 시작해서 오른쪽으로 진행하는 bottom-up방식을 통해
	   각 위치에서 나올 수 있는 가장 큰 값을 비교해서 저장해주는 메모이제이션 방식을 사용한다.
	*/
	for (int i = 1; i <= N; i++)
	{
		dp[i] = A[i]; // 각 dp배열의 초기값은 그 위치의 배열값으로 해준다.

		for (int j = 1; j < i; j++) // 그 배열보다 왼쪽에 위치한 index들을 다 비교해준다.
		{
			/* 오른쪽값이 더커야 하고, 현재의 dp값보다 지금 검사하는 index의 dp값 + 현재위치의 배열값이 더크면 갱신해준다 . */
			if (A[j] < A[i] && dp[i] < dp[j] + A[i]) 
				dp[i] = dp[j] + A[i];
		}
		if (ans < dp[i]) // 그 위치의 최대값이 갱신된 후 정답과 비교해서 정답 갱신
			ans = dp[i];
	}
	cout << ans;
	return 0;
}
