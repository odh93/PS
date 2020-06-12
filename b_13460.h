#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n, m,Ry,Rx,By,Bx,ans;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
string arr[11];
/*
  1. 큐에 빨간공 y,x좌표 파란공 y,x좌표와 cnt를 넣고 bfs진행
  2. 빨간공 파란공 이동 후 다음 파란공의 위치가 0이면 스킵
  3. 0이 아니고 파란공과 빨간공의 위치가 같으면 그 전의 위치에 기반하여 이동
  4. 최소값을 출력

*/
struct ball
{
	int ry, rx, by, bx, cnt;
};
bool check[11][11][11][11];
queue <ball> q;
void move(int dir,int &ry,int &rx,int &by,int &bx)
{
	int fry = ry;
	int frx = rx;
	int fby = by;
	int fbx = bx;
	while(1)
	{
		ry += dy[dir];
		rx += dx[dir];
		if (arr[ry][rx] == '#')
		{
			ry -= dy[dir];
			rx -= dx[dir];
			break;
		}
		if (arr[ry][rx] == 'O')
			break;
	}
	
	while (1)
	{
		by += dy[dir];
		bx += dx[dir];
		if (arr[by][bx] == '#')
		{
			by -= dy[dir];
			bx -= dx[dir];
			break;
		}
		if (arr[by][bx] == 'O')
			break;
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'B')
			{
				By = i;
				Bx = j;
				arr[i][j] = '.';
			}
			if (arr[i][j] == 'R')
			{
				Ry = i;
				Rx = j;
				arr[i][j] = '.';
			}
		}
	}
	q.push({ Ry,Rx,By,Bx,0 });
	check[Ry][Rx][By][Bx] = true;
	ans = -1;
	while (!q.empty())
	{
		int ry = q.front().ry;
		int rx = q.front().rx;
		int by = q.front().by;
		int bx = q.front().bx;
		int cnt = q.front().cnt;
		q.pop();
		if (cnt > 10)
		{
			ans = -1;
			break;
		}
		if (arr[ry][rx] == 'O')
		{
			ans = cnt;
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nry = ry;
			int nrx = rx;
			int nby = by;
			int nbx = bx;
			move(i, nry, nrx, nby, nbx);
			if (arr[nby][nbx] == 'O')
				continue;
			if (nby == nry && nbx == nrx)
			{
				if (i == 0)
				{
					if (bx > rx)
						nrx -= 1;
					else
						nbx -= 1;
				}
				if (i == 1)
				{
					if (bx > rx)
						nbx += 1;
					else
						nrx += 1;
				}
				if (i == 2)
				{
					if (by > ry)
						nry -= 1;
					else
						nby -= 1;
				}
				if (i == 3)
				{
					if (by > ry)
						nby += 1;
					else
						nry += 1;
				}
			}
			if (!check[nry][nrx][nby][nbx])
			{
				check[nry][nrx][nby][nbx] = true;
				q.push({ nry,nrx,nby,nbx,cnt + 1 });
			}
		}
	}
	cout << ans;
	return 0;
}
