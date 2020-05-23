#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string bu;
int k;
bool check[10];
vector <string> ans;
void dfs(int cnt,string num)
{
	if (cnt == k+1)
	{
		ans.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (!check[i] && cnt == 0)
		{
			check[i] = true;
			dfs(cnt + 1, num + to_string(i));
			check[i] = false;
		}
		else if (!check[i])
		{
			if (bu[cnt-1] == '<')
			{
				int tempnum = num[cnt - 1] - '0';
				if (tempnum < i)
				{
					check[i] = true;
					dfs(cnt + 1, num + to_string(i));
					check[i] = false;
				}
			}
			else if (bu[cnt-1] == '>')
			{
				int tempnum = num[cnt - 1] - '0';
				if (tempnum > i)
				{
					check[i] = true;
					dfs(cnt + 1, num + to_string(i));
					check[i] = false;
				}
			}
		}
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> k;
	char temp;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		bu += temp;
	}
	dfs(0,"");
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << '\n' << ans[0];
	return 0;
}
