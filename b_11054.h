#include <iostream>
#include <algorithm>
using namespace std;
int ans,n, arr[1001], a[1001], b[1001];
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
	{
		a[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && a[i] < a[j] + 1)
				a[i] = a[j] + 1;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		b[i] = 1;
		for (int j = n - 1; j > i; j--)
		{
			if(arr[i] > arr[j] && b[i] < b[j] +1)
				b[i] = b[j] + 1;
		}
	}
	ans = a[0] + b[0] - 1;
	for (int i = 1; i < n; i++)
	{
		ans = max(ans, a[i] + b[i] - 1);
	}
	cout << ans;
	return 0;
}
