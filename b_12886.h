#include <iostream>
#include <queue>
using namespace std;
int A, B, C,sum;
bool check[1501][1501];
queue <pair<int, int>> q;
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> A >> B >> C;
	check[A][B] = true;
	sum = A + B + C;
	q.push({ A,B });
	int cnt = 0;
	/* bfs로 돌을 이동시키며 해결
	c의 개수를 체크하는 배열을 따로 만들지 않고
	전체돌의 개수에서 a와 b의 개수를 뺀 형태로 진행
	*/
	while (!q.empty() && cnt <=2000)
	{
		int a = q.front().first;
		int b = q.front().second;
		int c = sum - (a + b);
		q.pop();
		if (a == b && b == c)
		{
			cout << 1;
			exit(0);
		}
		if (a > b)
		{
			int na = a - b;
			int nb = 2 * b;
			if (!check[na][nb])
			{
				check[na][nb] = true;
				q.push({ na,nb });
			}
		}
		if (b > a)
		{
			int na = 2*a;
			int nb = b-a;
			if (!check[na][nb])
			{
				check[na][nb] = true;
				q.push({ na,nb });
			}
		}
		if (b > c)
		{
			int na = a;
			int nb = b-c;
			if (!check[na][nb])
			{
				check[na][nb] = true;
				q.push({ na,nb });
			}
		}
		if (c > b)
		{
			int na = a;
			int nb = 2*b;
			if (!check[na][nb])
			{
				check[na][nb] = true;
				q.push({ na,nb });
			}
		}
		if (c > a)
		{
			int na = 2 * a;
			int nb = b;
			if (!check[na][nb])
			{
				check[na][nb] = true;
				q.push({ na,nb });
			}
		}
		if (a > c)
		{
			int na = a-c;
			int nb = b;
			if (!check[na][nb])
			{
				check[na][nb] = true;
				q.push({ na,nb });
			}
		}
		cnt += 1;
	}
	cout << 0;
	return 0;
}
