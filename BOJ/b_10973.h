#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[10001];
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	/*
	prev_permutation 알고리즘과 동일하게 설계
	1) 뒤에서부터 역순인 숫자 쌍을 찾는다. i, ii라 한다
	2) 이번에는 뒤에서부터 i보다 작은 j를 찾는다.
	3) i와 j를 swap
	4) ii를 포함하여, 그 뒷 부분을 모두 reverse 한다.
	*/
	int p = n - 1;
	while (p > 0 && arr[p - 1] <= arr[p]) // 역순인 idx를 찾는다
		p -= 1;
	if (p == 0) // 그 위치가 맨앞이면 이전 수열은 없다
	{
		cout << "-1";
		return 0;
	}
	int q = n - 1;
	while (arr[p - 1] <= arr[q]) // 그 수 보다 작거나 같은 위치를 찾는다.
		q -= 1;
	swap(arr[p - 1], arr[q]); // 그리고 둘을 swap
	q = n - 1;
	while (p < q) // p부터 맨뒤까지 reverse해준다.
	{
		swap(arr[p], arr[q]);
		p += 1;
		q -= 1;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	return 0;
}
