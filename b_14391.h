#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n, m,ans;
string arr[5];
bool check[5][5];
void calc()
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		int sum1 = 0;
		for (int j = 0; j < m; j++)
		{
			if (!check[i][j])
			{
				sum1 *= 10;
				sum1 += arr[i][j] - '0';
			}
			else
			{
				result += sum1;
				sum1 = 0;
			}
		}
		result += sum1;
	}
	for (int i = 0; i < m; i++)
	{
		int sum2 = 0;
		for (int j = 0; j < n; j++)
		{
			if (check[j][i])
			{
				sum2 *= 10;
				sum2 += arr[j][i] - '0';
			}
			else
			{
				result += sum2;
				sum2 = 0;
			}
		}
		result += sum2;
	}
	ans = max(ans, result);
}
void dfs(int cur)
{
	if (cur == (n * m))
	{
		calc();
		return;
	}
	int y = cur / m;
	int x = cur % m;
	dfs(cur + 1);
	check[y][x] = true;
	dfs(cur + 1);
	check[y][x] = false;
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
	dfs(0);
	cout << ans;
	return 0;
}
