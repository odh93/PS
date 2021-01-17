#include <iostream>
#include <map>
#include <string>
#include <queue>
using namespace std;
const long long MAX = 1000000000LL;
long long s, t;
string bfs()
{
	queue <pair<long long, string>> q;
	map <long long, bool> mcheck;
	q.push({ s,"" });
	mcheck[s] = true;
	while (!q.empty())
	{
		long long num = q.front().first;
		string cur_s = q.front().second;
		q.pop();
		if (num == t)
			return cur_s;
		long long next_num = num * num;
		if (next_num <= MAX && !mcheck[next_num])
		{
			mcheck[next_num] = true;
			q.push({ next_num,cur_s + "*" });
		}
		next_num = num * 2;
		if (next_num <= MAX && !mcheck[next_num])
		{
			mcheck[next_num] = true;
			q.push({ next_num,cur_s + "+" });
		}
		next_num = 0;
		if (!mcheck[next_num])
		{
			mcheck[next_num] = true;
			q.push({ next_num,cur_s + "-" });
		}
		if (num != 0)
		{
			next_num = 1;
			if (!mcheck[next_num])
			{
				mcheck[next_num] = true;
				q.push({ next_num,cur_s + "/" });
			}
		}
	}
	return "-1";
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> s >> t;
	if (s == t)
		cout << 0;
	else
		cout << bfs();
	return 0;
}
