#include <iostream>
using namespace std;
long long ans;
int n;
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	/* 자리수에 해당하는 수를 1부터 차례대로 더해주는
	단순구현으로 해결*/
	for (int i = 1; i <= n; i++)
	{
		if (i < 10)
			ans += 1;
		else if (i < 100)
			ans += 2;
		else if (i < 1000)
			ans += 3;
		else if (i < 10000)
			ans += 4;
		else if (i < 100000)
			ans += 5;
		else if (i < 1000000)
			ans += 6;
		else if (i < 10000000)
			ans += 7;
		else if (i < 100000000)
			ans += 8;
		else if (i < 1000000000)
			ans += 9;
		else if (i == 1000000000)
			ans += 10;
	}
	cout << ans;
	return 0;
}
