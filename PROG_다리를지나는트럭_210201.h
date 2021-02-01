#include <string>
#include <vector>
#include <queue>
using namespace std;
queue <int> q;
int total_weight;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    for(int i=0; i<truck_weights.size(); i++){
        int cur_weight = truck_weights[i];
        while(1){
            if(q.empty()){
                q.push(cur_weight);
                total_weight += cur_weight;
                answer+=1;
                 break;
            }
            else if(q.size()==bridge_length){
                total_weight -= q.front();
                q.pop();
            }
            else{
                if(cur_weight + total_weight <= weight){
                    q.push(cur_weight);
                    total_weight += cur_weight;
                    answer+=1;
                    break;
                }
                else{
                    q.push(0);
                    answer+=1;
                }
            }
        }
    }
    return answer+bridge_length;
}
