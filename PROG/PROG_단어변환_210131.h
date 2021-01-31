#include <string>
#include <vector>
using namespace std;
vector <bool> check;
int n,ans=987654321;
void dfs(int cnt,string cur,string target,vector<string> words){
    for(int i=0; i<n; i++){
        if(check[i])
            continue;
        int count = 0;
        for(int j=0; j<words[i].size(); j++){
            if(words[i][j]!=cur[j])
                count += 1;
        }
        if(count==1){
            if(words[i] == target && cnt+1 < ans){
                ans = cnt+1;
                return;
            }
            check[i] = true;
            dfs(cnt+1,words[i],target,words);
            check[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    n = words.size();
    check.resize(n);
    dfs(0,begin,target,words);
    if(ans==987654321)
        ans = 0;
    return ans;
}
