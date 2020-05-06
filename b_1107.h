#include <iostream>

using namespace std;

int e, s, m;

int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> e >> s >> m;

	int te, ts, tm;
	for (int i = 1; ; i++)
	{
		if (i % 15 == 0)
			te = 15;
		else
			te = i % 15;
		if (i % 28 == 0)
			ts = 28;
		else
			ts = i % 28;
		if (i % 19 == 0)
			tm = 19;
		else
			tm= i % 19;
		
		if (e == te && s == ts && m == tm)
		{
			cout << i;
			break;
		}
	}
	return 0;
}
