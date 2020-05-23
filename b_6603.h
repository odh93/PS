#include <iostream>
using namespace std;
int n,arr[13],sel[6];
void dfs(int cur,int cnt)
{
	if (cnt == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << sel[i] << ' ';
		cout << '\n';
		return;
	}
	if (cur >= n)
		return;
	for (int i = cur; i < n; i++)
	{
		sel[cnt] = arr[i];
		dfs(i + 1, cnt + 1);
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		dfs(0, 0);
		cout << '\n';
	}
	return 0;
}
