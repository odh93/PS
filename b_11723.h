#include <iostream>
#include <string>
#include <string.h>
using namespace std;
bool check[21];
int function()
{
    freopen("input.txt", "r", stdin);
    setbuf(stdout, NULL);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        string s;
        cin >> s;
        if (s == "add")
        {
            cin >> x;
            check[x] = true;
        }
        else if (s == "remove")
        {
            cin >> x;
            check[x] = false;
        }
        else if (s == "check")
        {
            cin >> x;
            if (check[x])
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (s == "toggle")
        {
            cin >> x;
            if (check[x])
                check[x] = false;
            else
                check[x] = true;
        }
        else if (s == "all")
            memset(check, true, sizeof(check));
        else
            memset(check, false, sizeof(check));
    }
    return 0;
}
