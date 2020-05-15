#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[9],sel[9];
bool check[9];
/*
  N개의 자연수 중에서 M개를 고른 수열
  수열을 정렬해준 후 dfs를 이용하여 m개를
  선택하는데 check배열을 이용하여 한번 선택된 수는
  다시 고르지 않게 해준다.
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
	for (int i = 0; i < n; i++)
	{
		if (!check[i]) // check안된 수만 골라준다
		{
			check[i] = true;
			sel[cnt] = arr[i];
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
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	dfs(0);
	return 0;
}
