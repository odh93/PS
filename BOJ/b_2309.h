#include <iostream>
#include <algorithm>
using namespace std;
int arr[9],sum;
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr, arr + 9);
	// 오름차순으로 출력하기에 정렬해준다.

	/* 해결방법은 7명중 합이 100되는 5명을 찾는 과정이니 포함안되는 2명을 찾는것이 빠르다.
	재귀형식을 짤 필요 없이 for문으로 빠르게 구해주었다.*/
	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - arr[i] - arr[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j)
						continue;
					cout << arr[k] << '\n';
				}
				exit(0);
			}
		}
	}
	return 0;
}
