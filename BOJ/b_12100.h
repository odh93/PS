#include <iostream>
using namespace std;
int n, ans,map[21][21],maxnum;
/*
 1. dfs를 진행하며 상하좌우로 2048 진행
 2. 2048 진행 시 합친 숫자들의 위치를 표시하며 진행
 3. 5번 진행 후 최고값 검사

*/
void dfs(int cnt)
{
	if (cnt == 5)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j] > ans)
					ans = map[i][j];
			}
		}
		if (maxnum == ans)
		{
			cout << maxnum;
			exit(0);
		}
		return;
	}

	for (int a = 0; a < 4; a++)
	{
		bool check[21][21];
		int copymap[21][21];

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				copymap[i][j] = map[i][j];
				check[i][j] = false;
			}
		}

		if (a == 0)
		{

			for (int i = 0; i < n; i++)
			{
				for (int j = n - 2; j >= 0; j--)
				{
					int idx = j;
					int temp = map[i][j];
					if (temp == 0)
						continue;

					while (1)
					{
						idx += 1;

						if (idx >= n)
							break;
						if (map[i][idx] == temp && !check[i][idx])
						{
							map[i][idx] = temp * 2;
							map[i][idx - 1] = 0;
							check[i][idx] = true;
							break;
						}
						else if (map[i][idx] == 0)
						{
							map[i][idx] = temp;
							map[i][idx - 1] = 0;
						}
						else
							break;
					}
				}
			}
			dfs(cnt + 1);
		}

		if (a == 1)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 1; j < n; j++)
				{
					int idx = j;
					int temp = map[i][j];
					if (temp == 0)
						continue;

					while (1)
					{
						idx -= 1;

						if (idx < 0)
							break;
						if (map[i][idx] == temp && !check[i][idx])
						{
							map[i][idx] = temp * 2;
							map[i][idx + 1] = 0;
							check[i][idx] = true;
							break;
						}
						else if (map[i][idx] == 0)
						{
							map[i][idx] = temp;
							map[i][idx + 1] = 0;
						}
						else
							break;
					}
				}
			}
			dfs(cnt + 1);
		}

		if (a == 2)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 2; j >= 0; j--)
				{
					int idx = j;
					int temp = map[j][i];
					if (temp == 0)
						continue;

					while (1)
					{
						idx += 1;

						if (idx >= n)
							break;
						if (map[idx][i] == temp && !check[idx][i])
						{
							map[idx][i] = temp * 2;
							map[idx - 1][i] = 0;
							check[idx][i] = true;
							break;
						}
						else if (map[idx][i] == 0)
						{
							map[idx][i] = temp;
							map[idx - 1][i] = 0;
						}
						else
							break;
					}
				}
			}
			dfs(cnt + 1);
		}

		if (a == 3)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 1; j < n; j++)
				{
					int idx = j;
					int temp = map[j][i];
					if (temp == 0)
						continue;

					while (1)
					{
						idx -= 1;

						if (idx < 0)
							break;
						if (map[idx][i] == temp && !check[idx][i])
						{
							map[idx][i] = temp * 2;
							map[idx + 1][i] = 0;
							check[idx][i] = true;
							break;
						}
						else if (map[idx][i] == 0)
						{
							map[idx][i] = temp;
							map[idx + 1][i] = 0;
						}
						else
							break;
					}
				}
			}
			dfs(cnt + 1);
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = copymap[i][j];
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
			cin >> map[i][j];
			maxnum += map[i][j];
		}
	}
	dfs(0);
	cout << ans;
	return 0;
}
