#include <iostream>
using namespace std;
int n, m,sel[8];
/*
  1부터 N까지 자연수 중에서 M개를 고른 수열
  같은 수를 여러 번 골라도 된다.
  dfs로 m개를 선택할때까지 1~n까지의 수를 모두 골라주어 해결
*/
void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << sel[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		sel[cnt] = i;
		dfs(cnt + 1);
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	dfs(0);
	return 0;
}
