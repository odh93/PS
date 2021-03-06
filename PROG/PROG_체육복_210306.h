#include <string>
#include <vector>

using namespace std;
vector <bool> check;
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector <int> check(n+2,1);
    for(int i=0; i<lost.size(); i++)
        check[lost[i]]-=1;
    for(int i=0; i<reserve.size(); i++)
        check[reserve[i]]+=1;
    for(int i=1; i<=n; i++){
        if(check[i]==0){
            if(check[i-1]==2){
                check[i-1]-=1;
                check[i]+=1;
            }
            else if(check[i+1]==2){
                check[i+1]-=1;
                check[i]+=1;
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(check[i]!=0)
            answer+=1;
    }
    return answer;
}
