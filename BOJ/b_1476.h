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
	for (int i = 1; ; i++) // 정답은 항상있으니 무한for문으로 검사
	{
		if (i % 15 == 0) // 나머지가 0일시 E는 15
			te = 15;
		else
			te = i % 15;
		if (i % 28 == 0) // 나머지가 0일시 S는 28
			ts = 28;
		else
			ts = i % 28;
		if (i % 19 == 0) // 나머지가 0일시 M은 19
			tm = 19;
		else
			tm= i % 19;
		
		if (e == te && s == ts && m == tm) // 모두 기준과 같아지면 정답 출력
		{
			cout << i;
			break;
		}
	}
	return 0;
}
