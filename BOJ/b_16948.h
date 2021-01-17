#include <iostream>
#include <queue>
using namespace std;
bool check[201][201];
int n,r1,c1,r2,c2;
queue <pair<pair<int, int>, int>> q;
int dy[6] = { -2,-2,0,0,2,2 };
int dx[6] = { -1,1,-2,2,-1,1 };

/*
 문제에서 표기된 데스나이트의 움직임대로 bfs를 시행하면 된다

*/
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	check[r1][c1] = true;
	q.push({ {r1,c1},0 });
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second;
		if (y == r2 && x == c2)
		{
			cout << cnt;
			exit(0);
		}
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n)
				continue;
			if (check[ny][nx])
				continue;
			check[ny][nx] = true;
			q.push({ { ny,nx },cnt + 1 });
		}
	}
	cout << -1;
	return 0;
}
