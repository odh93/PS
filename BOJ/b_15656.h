#include <iostream>
#include <algorithm>
using namespace std;
int n, m, arr[8], sel[8];
/*
 N개의 자연수 중에서 M개를 고른 수열
 같은 수를 여러 번 골라도 된다.

 수열을 한번 정렬해주고 dfs를 활용하여 
 m개 고르는 모든 경우의 수를 출력해줍니다
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
		sel[cnt] = arr[i];
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
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	dfs(0);
	return 0;
}
