#include <string>
#include <vector>
using namespace std;
int ans;
void dfs(vector<int> numbers,int target,int cnt,int sum){
    if(cnt == numbers.size()){
        if(sum == target)
            ans+=1;
        return;
    }
    dfs(numbers,target,cnt+1,sum-numbers[cnt]);
    dfs(numbers,target,cnt+1,sum+numbers[cnt]);
}
int solution(vector<int> numbers, int target) {
    dfs(numbers,target,0,0);
    return ans;
}
