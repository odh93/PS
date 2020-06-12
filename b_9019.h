#include <iostream>
#include <string>
#include <queue>
#include <string.h>
using namespace std;
int T,A,B;
bool check[10000];
/*
 1. 숫자와 명렁어들을 저장하는 문자열을 pair로 묶어 bfs를 시행한다
 2. D와 S는 숫자에 값을 곱하거나 빼서 체크해준다.
 3. L,R은 자릿수의 있는 숫자별로 변수를 만들어서 저장하지 않고
 계산을 통해 메모리 절약
*/
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> A >> B;
		queue <pair<int, string>> q;
		memset(check, 0, sizeof(check));
		q.push({ A,"" });
		check[A] = true;
		while (!q.empty())
		{
			int curn = q.front().first;
			string s = q.front().second;
			q.pop();
			if (curn == B)
			{
				cout << s <<'\n';
				break;
			}
			int nextn = (2 * curn) % 10000;
			if (!check[nextn])
			{
				check[nextn] = true;
				q.push({ nextn,s + "D" });
			}
			nextn = curn - 1;
			if (nextn == -1)
				nextn = 9999;
			if (!check[nextn])
			{
				check[nextn] = true;
				q.push({ nextn,s + "S" });
			}
			nextn = (curn % 1000) * 10 + (curn / 1000);
			if (!check[nextn])
			{
				check[nextn] = true;
				q.push({ nextn,s + "L" });
			}
			nextn = (curn % 10) * 1000 + (curn / 10);
			if (!check[nextn])
			{
				check[nextn] = true;
				q.push({ nextn,s + "R" });
			}
		}
	}
	return 0;
}
