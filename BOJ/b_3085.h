#include <iostream>
#include <algorithm>
using namespace std;

char board[51][51];
int n,ans;

void check()
{
	for (int i = 0; i < n; i++)
	{
		char tc = board[i][0];
		int cnt = 1;
		//가로 방향의 연속하는 최대 사탕수를 행별로 계산하는 for문
		for (int j = 1; j < n; j++)
		{
			if (tc == board[i][j])
			{ // 색이 같으면 cnt를 추가하고 ans와 비교해준다.
				cnt += 1;
				ans = max(ans, cnt);
			}
			else 
			{ // 색이 다르면 현재 색으로 기준을 바꾸고 수를 1로 초기화
				tc = board[i][j];
				cnt = 1;
			}
		}

		tc = board[0][i];
		cnt = 1;
		// 마찬가지인데 세로방향을 검사
		for (int j = 1; j < n; j++)
		{
			if (tc == board[j][i])
			{
				cnt += 1;
				ans = max(ans, cnt);
			}
			else
			{
				tc = board[j][i];
				cnt = 1;
			}
		}
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);

	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j + 1 < n) // 좌우 사탕의 위치를 바꾸고 검사하고 다시 바꿔준다 
			{
				if (board[i][j] != board[i][j + 1])
				{
					swap(board[i][j], board[i][j + 1]);
					check();
					swap(board[i][j], board[i][j + 1]);
				}
				
			}

			if (i + 1 < n)
			{
				if (board[i][j] != board[i+1][j]) // 상하 사탕의 위치를 바꾸고 검사하고 다시 바꿔준다.
				{
					swap(board[i][j], board[i+1][j]);
					check();
					swap(board[i][j], board[i + 1][j]);
				}
			}
		}
	}
	cout << ans;
	return 0;
}
