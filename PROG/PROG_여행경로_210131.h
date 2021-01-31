#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector <bool> check;
int n,ans=987654321;
vector<vector<string>> answer_v;
void dfs(int cnt,string cur,vector <string> answer,vector<vector<string>> tickets){
    if(cnt == n){
        answer_v.push_back(answer);
        return;
    }
    for(int i=0; i<n; i++){
        if(!check[i] && tickets[i][0]==cur){
            check[i] = true;
            answer.push_back(tickets[i][1]);
            dfs(cnt+1,tickets[i][1],answer,tickets);
            answer.pop_back();
            check[i] = false;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    n = tickets.size();
    check.resize(n);
    answer.push_back("ICN");
    dfs(0,"ICN",answer,tickets);
    sort(answer_v.begin(),answer_v.end());
    return answer_v[0];
}
