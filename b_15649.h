#include <iostream>
using namespace std;
int n, m,arr[9],sel[9];
bool check[9];
/* 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 전부 출력하는 문제
  dfs를 활용하여 m개의 수를 고를때가지 완전탐색하는데 check배열을 사용하여
  check된 수는 다시 사용하지 않게하여 중복을 피함
*/
void dfs(int cnt)
{
	if (cnt == m) // m개가 골라지면 출력
	{
		for (int i = 0; i < m; i++)
			cout << sel[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!check[i]) // 한번 사용한 수는 다시 사용하지 않는다.
		{
			check[i] = true;
			sel[cnt] = i;
			dfs(cnt + 1);
			check[i] = false;
		}
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dfs(0);
	return 0;
}
