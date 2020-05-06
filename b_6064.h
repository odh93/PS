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
