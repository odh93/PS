#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char board[8][8];
int mintime = 8,ans;
bool wall_time[8][8][8], check_time[8][8][8];
vector <pair<int, int>> wall;
int dy[9] = { -1,-1,-1,0,0,0,1,1,1 };
int dx[9] = { -1,0,1,-1,0,1,-1,0,1 };
int bfs()
{
	queue <pair<pair<int, int>, int>> q;
	check_time[7][0][0] = true;
	q.push({ {7,0},0 });
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cur_time = q.front().second;
		q.pop();
		if (cur_time > mintime)
			return 1;
		if (y == 0)
			return 1;
		for (int i = 0; i < 9; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < 8 && nx < 8)
			{
				if (!wall_time[ny][nx][cur_time] && !wall_time[ny][nx][cur_time + 1] && !check_time[ny][nx][cur_time + 1])
				{
					check_time[ny][nx][cur_time + 1] = true;
					q.push({ {ny,nx},cur_time + 1 });
				}
			}
		}
	}
	return 0;
}
void wallmove()
{
	for (int i = 0; i < wall.size(); i++)
	{
		int y = wall[i].first;
		int x = wall[i].second;
		int cur_time = 0;
		while (1)
		{
			if (y == 7)
				break;
			y += 1;
			cur_time += 1;
			wall_time[y][x][cur_time] = true;
		}
	}
}
int function()
{
	freopen("input.txt", "r", stdin);
	setbuf(stdout, NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> board[i][j];

			if (board[i][j] == '#')
			{
				if (i < mintime)
					mintime = i;
				wall.push_back({ i,j });
				wall_time[i][j][0] = true;
			}
		}
	}
	mintime = 8 - mintime;
	wallmove();
	cout << bfs();
	return 0;
}
