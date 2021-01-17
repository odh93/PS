#include <iostream>
#include <algorithm>
using namespace std;

int n,arr[10001];
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
	next_permutation 알고리즘과 동일하게 설계
	1) 뒤에서부터 역순이 아닌 숫자 쌍을 찾는다. i, ii라 한다
	2) 이번에는 뒤에서부터 i보다 큰 j를 찾는다.
	3) i와 j를 swap
	4) ii를 포함하여, 그 뒷 부분을 모두 reverse 한다.
	*/
	if (n == 1) // 개수가 하나면 더작은 수가 다음 수열이 없다
	{
		cout << "-1";
		return 0;
	}		
	int p = n - 1;
	while (p > 0 && arr[p - 1] > arr[p]) // 앞의 idx의 수열값이 더큰 idx를 찾는다.
		p -= 1;
	if (p == 0) // 그위치가 맨앞이면 다음수열은 없다
	{
		cout << "-1";
		return 0;
	}
	int q = n - 1;
	while (arr[p - 1] >= arr[q]) // 그수보다 작거나 같은 최초위치를 찾는다.
		q -= 1;
	swap(arr[p - 1], arr[q]); // 바꿔주고 
	q = n - 1; 
	while (p < q) // 뒤에서부터 p까지 reverse해준다. 
	{
		swap(arr[p], arr[q]);
		p += 1;
		q -= 1;
	}
	for (int i = 0; i < n; i++)
		cout << arr[i] << ' ';
	return 0;
}
