#include <string>
#include <vector>
using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer,v;
   for(int i=0; i<progresses.size(); i++){
       int temp;
       if((100-progresses[i])%speeds[i]==0)
           temp = (100-progresses[i])/speeds[i];
       else
           temp = (100-progresses[i])/speeds[i]+1;
       v.push_back(temp);
   }
    int temp = v.front();
    v.erase(v.begin());
    int cnt = 1;
    while(v.size()!=0){
        int num = v.front();
        v.erase(v.begin());
        if(temp >= num)
            cnt+=1;
        else{
            answer.push_back(cnt);
            cnt = 1;
            temp = num;
        }
    }
    answer.push_back(cnt);
    return answer;
}
