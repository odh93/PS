#include <iostream>
#include <algorithm>
using namespace std;
int n, m,arr[9],sel[9];
/*
 N개의 자연수 중에서 M개를 고른 수열
 고른 수열은 오름차순이어야 한다.

 수열을 한번 정렬해준 후 오름차순으로 출력하기 위해
 현재 수열의 idx를 cur에 저장하여 다음 수를 고를때엔 현재고른 idx+1부터
 골라주어 오름차순을 해결해준다.
*/
void dfs(int cur, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
			cout << sel[i] << ' ';
		cout << '\n';
		return;
	}
	if (cur >= n)
		return;
	for (int i = cur; i < n; i++)
	{
		sel[cnt] = arr[i];
		dfs(i + 1, cnt + 1); // i+1부터 다음수를 선택
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
	dfs(0, 0);
	return 0;
}
