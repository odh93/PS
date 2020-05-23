#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int l, c;
char arr[16];
void dfs(int cur,int vcnt, int ccnt,string pass)
{
	if (cur == c)
	{
		if (vcnt >= 1 && ccnt >= 2 && vcnt + ccnt == l)
			cout << pass << '\n';
		return;
	}
	char temp = arr[cur];
	int vc = 0;
	int cc = 0;
	if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
		vc += 1;
	else
		cc += 1;
	dfs(cur + 1, vcnt + vc, ccnt + cc, pass + temp);
	dfs(cur + 1, vcnt, ccnt, pass);
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> l >> c;
	for (int i = 0; i < c; i++)
		cin >> arr[i];
	sort(arr, arr + c);
	dfs(0, 0, 0, "");
	return 0;
}
