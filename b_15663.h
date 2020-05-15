#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n, m, arr[9];
bool check[9];
vector <int> v;
map <vector <int> ,bool> vm;
/*
  N개의 자연수 중에서 M개를 고른 수열
  중복되는 수열을 여러 번 출력하면 안된다

  중복되는 수가 여러번 출력되는 것을 막기위해 map을 사용
  dfs로 수를 하나씩 고를대마다 vector에 수를 넣어주고
  최종적으로 넣은 벡터가 false라면 출력해주고 true이면 skip한다

*/
void dfs(int cnt)
{
	if (cnt == m)
	{
		if (!vm[v]) // 벡터가 한번 나온 벡터인지 아닌지 검사
		{
			vm[v] = true; // 한번 나왔다고 체크
			for (int i = 0; i < m; i++)
				cout << v[i] << ' ';
			cout << "\n";
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			v.push_back(arr[i]);
			dfs(cnt + 1);
			v.pop_back();
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
