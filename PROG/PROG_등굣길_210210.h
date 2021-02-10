#include <vector>
using namespace std;
int dp[101][101],MOD = 1000000007;
bool check[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i=0; i<puddles.size(); i++)
        check[puddles[i][1]][puddles[i][0]] = true;
    dp[1][0] = 1 % MOD;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(check[i][j])
                dp[i][j] = 0 % MOD;
            else
                dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    return dp[n][m] % MOD;
}
