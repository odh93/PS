#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m, board[501][501],ans;
bool check[501][510];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void dfs(int y, int x, int cnt,int sum) // dfs를 이용해 ㅗ모양들을 제외한 테트리미노를 검사하는 dfs함수
{
	sum += board[y][x];
	ans = max(ans, sum);
	if (cnt == 4)
		return;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= n || nx >= m)
			continue;
		if (check[ny][nx])
			continue;
		check[ny][nx] = true;
		dfs(ny, nx, cnt + 1,sum);
		check[ny][nx] = false;
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
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	/* 완전탐색으로 모든 좌표에 대해 탐색하여 
	그 좌표에 대해 들어갈 수 있는 테트리미노 도형을 
	모두 넣어보고 최대값을 찾아줘서 해결했다.
	ㅗ 모양을 제외한 테트리미노는 dfs탐색을 통해 뒤로 가는
	탐색 없이 구할 수 있어 dfs함수로 count를 4회 할때까지 탐색해주어
	도형을 만들어주었고 ㅗ모양은 for문을 이용하여 단순구현하였다.
	*/
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			check[i][j] = true;
			dfs(i, j, 1,0); 
			check[i][j] = false;

			if (i+1 <n && j+2 <m) // ㅜ 모양을 넣어보는 코드
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
				ans = max(ans, temp);
			}

			if (i - 1 >= 0 && j + 2 < m) // ㅗ 모양을 넣어보는 코드
			{
				int temp = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 1];
				ans = max(ans, temp);
			}
			if (i + 2 < n && j + 1 < m) // // ㅏ 모양을 넣어보는 코드
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
				ans = max(ans, temp);
			}

			if (i + 2 < n && j - 1 >= 0) // ㅓ 모양을 넣어보는 코드
			{
				int temp = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1];
				ans = max(ans, temp);
			}
		}
	}
	cout << ans;
	return 0;
}
