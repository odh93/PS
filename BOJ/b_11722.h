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
	/* 문제에서 답으로 요구하는 것은 가장 긴 감소하는 부분 수열의 길이이다.
	 따라서 dp배열에 index가 왼쪽부터 시작해서 오른쪽으로 가는 방향으로 
	 각 index위치에서의 나올 수 있는 부분 수열의 가장 긴 감소하는 길이 값을 저장해주는 
	 메모이제이션 방식을 이용해서 문제를 해결하면 된다.*/
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1; // 각 위치의 시작 길이는 1로 한다.
		for (int j = 0; j < i; j++) // 현재 index보다 왼쪽의 index들을 차례로 비교
		{
			if (arr[j] > arr[i] && dp[i] < dp[j] + 1) // 현재보다 배열값이 작고 비교하는 위치의 길이+1보다 현재 위치가 작으면 갱신
				dp[i] = dp[j] + 1;
		}
		ans = max(ans, dp[i]); //  매위치 계산이 끝난 최대길이와 정답 값을 비교해서 갱신
	}
	cout << ans;
	return 0;
}
