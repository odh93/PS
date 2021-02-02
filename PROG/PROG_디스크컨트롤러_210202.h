#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}
int solution(vector<vector<int>> jobs) {
    int answer=0 ,time =0,size= jobs.size();
    sort(jobs.begin(),jobs.end(),cmp);
    while(!jobs.empty()){
        for(int i=0; i<jobs.size(); i++){
            if(jobs[i][0] <= time){
                time += jobs[i][1];
                answer += time - jobs[i][0];
                jobs.erase(jobs.begin() + i);
                break;
            }
            if(i== jobs.size() -1)
                time+=1;
        }
    }
    return answer / size;
}
