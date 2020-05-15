#include <iostream>
using namespace std;
int n, m,sel[9];

/*
  1부터 N까지 자연수 중에서 M개를 고른 수열
  같은 수를 여러 번 골라도 된다.
  고른 수열은 비내림차순이어야 한다.
  길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
  
  위 조건을 만족하는 수열을 모두 출력하는 문제
  dfs를 활용하여 현재 idx위치를 cur에 담고 다음 숫자를 고를때
  그 idx위치 이상부터 for문을 돌려 수를 골라주어 비내림차순을 해결

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

	for (int i = cur; i <= n; i++)
	{
		sel[cnt] = i;
		dfs(i, cnt + 1); // 현재 idx부터 다음 수를 선택할때 사용
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	dfs(1, 0);
	return 0;
}
