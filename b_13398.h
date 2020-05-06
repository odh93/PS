#include <iostream>
#include <algorithm>
using namespace std;
int ans,n, arr[100001],a[100001],b[100001];
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	a[0] = arr[0];
	for (int i = 1; i < n; i++)
	{
		a[i] = arr[i];
		a[i] = max(a[i], a[i - 1] + arr[i]);
	}
	b[n - 1] = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		b[i] = arr[i];
		b[i] = max(b[i], b[i + 1] + arr[i]);
	}
	ans = a[0];
	for (int i = 1; i < n; i++)
		ans = max(ans, a[i]);
	for (int i = 1; i < n - 1; i++)
		ans = max(ans, a[i - 1] + b[i + 1]);
	cout << ans;
	return 0;
}
