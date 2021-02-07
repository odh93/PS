#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solution(vector<string> operations) {
    vector<int> answer;
    for(int i=0; i<operations.size(); i++){
        if(operations[i][0] == 'I'){
            operations[i].erase(operations[i].begin(), operations[i].begin()+1);
            int temp = stoi(operations[i]);
            answer.push_back(temp);
            sort(answer.begin(),answer.end());
        }
        else{
            if(answer.size() ==0)
                continue;
            if(operations[i][2] == '1')
                answer.pop_back();
            else
                answer.erase(answer.begin());
        }
    }
    vector <int> ans;
    if(answer.size() == 0){
        ans.push_back(0);
        ans.push_back(0);
    }
    else{
        ans.push_back(answer[answer.size()-1]);
        ans.push_back(answer[0]);
    }
    return ans;
}
