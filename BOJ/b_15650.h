#include <iostream>
using namespace std;
int n, m,arr[9],sel[9];
/*
  1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
  고른 수열은 오름차순이어야 한다.
  위 두가지를 만족하는 수열을 모두 출력하는 문제
  dfs를 이용하여 m개를 골라주어 해결하였는데 
  오름차순을 구현하기 위해 dfs함수 변수로 cur현재 idx위치를
  넘겨서 고른 수 +1의 idx부터 수를 골라주어 중복과 오름차순을 해결
*/
void dfs(int cur, int cnt)
{
	if (cnt == m) // m개를 모두 고름
	{
		for (int i = 0; i < m; i++)
			cout << sel[i] << ' ';
		cout << '\n';
		return;
	}
	if (cur > n)
		return;
	for (int i = cur; i <= n; i++) 
	{
		sel[cnt] = i;
		dfs(i + 1, cnt + 1); // 고른 수의 다음위치부터 시작
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
	dfs(1, 0);
	return 0;
}
