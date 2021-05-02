#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<string> v[11];
map <string,int> m;
int max_num[11];
void dfs(vector<string> orders,string menu,int num,int cnt,int cur,int goal){
    if(cnt == goal){
        if(m[menu]==0)
            v[menu.size()].push_back(menu);
        m[menu]+=1;
        if(m[menu]>max_num[menu.size()])
            max_num[menu.size()]=m[menu];
        return;
    }
    for(int i=cur; i<orders[num].size(); i++){
        menu.push_back(orders[num][i]);
        dfs(orders,menu,num,cnt+1,i+1,goal);
        menu.pop_back();
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int i=0; i<orders.size(); i++){
        sort(orders[i].begin(),orders[i].end());
        for(int j=0; j<course.size(); j++){
            dfs(orders,"",i,0,0,course[j]);
        }
    }
    for(int i=0; i<course.size(); i++){
        int cur = course[i];
        for(int j=0; j<v[cur].size(); j++){
            if(m[v[cur][j]]==max_num[cur] && max_num[cur]>=2)
                answer.push_back(v[cur][j]);
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}
