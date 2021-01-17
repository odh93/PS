#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ans = 987654321, n, arr[21][21];
vector <int> f, s;
bool check[21];
void dfs(int cur, int cnt)
{
	if (cnt == n / 2)
	{
		for (int i = 0; i < n; i++)
		{
			if (!check[i])
				s.push_back(i);
		}
		int fsum = 0, ssum = 0;
		for (int i = 0; i < f.size() - 1; i++)
			for (int j = i + 1; j < f.size(); j++)
				fsum += arr[f[i]][f[j]] + arr[f[j]][f[i]];
		for (int i = 0; i < s.size() - 1; i++)
			for (int j = i + 1; j < s.size(); j++)
				ssum += arr[s[i]][s[j]] + arr[s[j]][s[i]];
		ans = min(ans, abs(fsum - ssum));
		if (ans == 0)
		{
			cout << 0;
			exit(0);
		}
		s.clear();
		return;
	}
	for (int i = cur; i < n; i++)
	{
		check[i] = true;
		f.push_back(i);
		dfs(i + 1, cnt + 1);
		f.pop_back();
		check[i] = false;
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
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << ans;
	return 0;
}
