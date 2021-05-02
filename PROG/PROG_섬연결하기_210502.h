#include <string>
#include <vector>
#include <queue>
using namespace std;
bool check[101];
vector<pair<int,int>> v[101];
priority_queue<pair<int,int>> pq;
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(int i=0; i<costs.size(); i++){
        v[costs[i][0]].push_back({costs[i][1],costs[i][2]});
        v[costs[i][1]].push_back({costs[i][0],costs[i][2]});
    }
    for(int i=0; i<v[0].size(); i++)
        pq.push({-v[0][i].second,v[0][i].first});
    check[0]=true;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if(!check[cur]){
            check[cur] = true;
            answer += dist;
            
            for(int i=0; i<v[cur].size(); i++){
                int next = v[cur][i].first;
                int ndist = v[cur][i].second;
                if(!check[next])
                    pq.push({-ndist,next});
            }
        }
    }
    return answer;
}
