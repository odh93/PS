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

		for (int j = 1; j < n; j++)
		{
			if (tc == board[i][j])
			{
				cnt += 1;
				ans = max(ans, cnt);
			}
			else
			{
				tc = board[i][j];
				cnt = 1;
			}
		}

		tc = board[0][i];
		cnt = 1;

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
			if (j + 1 < n)
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
				if (board[i][j] != board[i+1][j])
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
