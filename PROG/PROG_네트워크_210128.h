#include <string>
#include <vector>
using namespace std;
vector <bool> check;
void dfs(int n,int cur,vector<vector<int>> computers){
    check[cur] = true;
    for(int i=0; i<n; i++){
        if(!check[i] && computers[cur][i]){
            dfs(n,i,computers);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    check.resize(n);
    for(int i=0; i<computers.size(); i++){
        if(!check[i]){
            answer+=1;
            dfs(n,i,computers);
        }
    }
    return answer;
}
