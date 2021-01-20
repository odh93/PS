#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(vector<int> priorities, int location) {
    int answer = 1;
    priority_queue <int> pq;
    queue <pair<int,int>> q;
    for(int i=0; i<priorities.size(); i++){
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    }
    while(!q.empty()){
        int cur = q.front().first;
        if(cur == pq.top()){
            if(location == q.front().second)
                return answer;
            pq.pop();
            answer +=1;
        }
        q.push({q.front().first,q.front().second});
        q.pop();
    }
}
