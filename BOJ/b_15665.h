#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n, m, arr[8];
vector <int> v;
map <vector <int>, bool> vm;
/*
 n과 m(9)와 동일한 조건인데 중복을 허용
*/
void dfs(int cnt)
{
	if (cnt == m)
	{
		if (!vm[v])
		{
			vm[v] = true;
			for (int i = 0; i < m; i++)
				cout << v[i] << ' ';
			cout << '\n';
		}
		return;
	}
	for (int i = 0; i < n; i++)
	{
		v.push_back(arr[i]);
		dfs(cnt + 1);
		v.pop_back();
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
