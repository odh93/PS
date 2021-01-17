#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int n, m, ans = 987654321;
bool button[10];
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	int temp;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		button[temp] = true;
	}
	/* 고장난 버튼을 bool 배열을 이용해서 체크해주고,
	0~100만까지 채널로 이동하는데 누르면 수 + (+,-로 이동하는 수)를 모두 구해 완전탐색해서 비교해준다.
	100만까지 위로가는 이유는 위에서 내려가는게 빠를 경우도 있기 때문이다.*/
	for (int i = 0; i <= 1000000; i++)
	{
		string cur = to_string(i);
		int curlen = cur.size();
		bool flag = false;
		if (i == 100) // 100에서 시작하기에 이동하는 수는 없다.
		{
			curlen = 0;
		}
		else
		{
			for (int j = 0; j < cur.size(); j++)
			{
				temp = cur[j] - '0';
				if (button[temp] == true) // 고장난 버튼이 있으면 이 수는 검사하지않는다
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
			continue;

		int result = abs(n - i); // (+,-) 이동하는 횟수
		result += curlen;
		ans = min(result, ans); // 최소 이동횟수가 정답
	}
	cout << ans;
	return 0;
}
