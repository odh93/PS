#include <iostream>

using namespace std;

int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int T;
	cin >> T;

	/*
	boj_1476 날짜계산과 비슷한 문제이지만 다른 점은 
	입력값의 범위가 크다. M,N이 둘다 40000이하의 값이라 
	모든 수를 완전 탐색하게 되면 O(MN+a)로 16억이상의 값이 나와
	최소 16초이상의 실행시간을 가지게 되어 시간초과를 낼 수 있는 문제이다
	이 문제에서 사용한 방법은 두 수중 하나의 배수를 계속해서 더해서 하나의
	for문을 없애줌과 동시에 4만/MorN의 복잡도로 해결할 수 있다.
	*/
	for (int t = 1; t <= T; t++)
	{
		int m, n, x, y,ty,ans;
		bool flag = false;
		cin >> m >> n >> x >> y;

		for (int i = x; i <= m * n; i += m)
		{
			if (i % n == 0)
				ty = n;
			else
				ty = i % n;
			if (ty == y)
			{
				flag = true;
				ans = i;
				break;
			}
		}
		if (!flag)
			ans = -1;
		cout << ans << '\n';
	}
	return 0;
}
