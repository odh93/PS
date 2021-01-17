#include <iostream>
#include <queue>
using namespace std;
int T;
bool prime[10001];
void find_prime()
{
	for (int i = 2; i <= 100; i++)
	{
		if (!prime[i])
		{
			for (int j = i * 2; j <= 10000; j += i)
				prime[j] = true;
		}
	}
}
int bfs(int start_num, int end_num)
{
	queue <pair<int, int>> q;
	bool check[10000] = { 0, };
	q.push({ start_num,0 });
	check[start_num] = true;
	while (!q.empty())
	{
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (num == end_num)
			return cnt;
		for (int i = 1; i <= 9; i++)
		{
			int next_num = num % 1000 + i * 1000;
			if (!check[next_num] && !prime[next_num])
			{
				check[next_num] = true;
				q.push({ next_num,cnt+1 });
			}
		}

		for (int i = 0; i <= 9; i++)
		{
			int next_num = (num / 1000) * 1000 + i * 100 + num % 100;
			if (!check[next_num] && !prime[next_num])
			{
				check[next_num] = true;
				q.push({ next_num,cnt + 1 });
			}
		}
		for (int i = 0; i <= 9; i++)
		{
			int next_num = (num / 100) * 100 + i * 10 + num % 10;
			if (!check[next_num] && !prime[next_num])
			{
				check[next_num] = true;
				q.push({ next_num,cnt + 1 });
			}
		}
		for (int i = 0; i <= 9; i++)
		{
			int next_num = (num / 10) * 10 + i;
			if (!check[next_num] && !prime[next_num])
			{
				check[next_num] = true;
				q.push({ next_num,cnt + 1 });
			}
		}
	}
	return -1;
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	find_prime();
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		int start_num, end_num,ans;
		cin >> start_num >> end_num;
		ans = bfs(start_num, end_num);
		if (ans == -1)
			cout << "Impossible\n";
		else
			cout << ans << '\n';
	}
	return 0;
}
