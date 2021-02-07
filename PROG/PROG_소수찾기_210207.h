#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector <bool> prime,check;
int num_cnt[10],n,ans;
void dfs(int cnt, int sum){
    if(cnt == n){
        if(!prime[sum] && !check[sum]){
            check[sum] = true;
            ans += 1;
        }
        return;
    }
    for(int i=0; i<=9; i++){
        if(num_cnt[i] > 0){
            num_cnt[i] -=1;
            dfs(cnt+1,sum*10 + i);
            num_cnt[i] += 1;
            dfs(cnt+1,sum);
        }
    }
}
int solution(string numbers) {
    prime.resize(10000000);
    check.resize(10000000);
    prime[0] = true,prime[1] = true;
    for(int i=2; i<=10000000; i++){
        if(!prime[i]){
            for(int j= i+i; j<=10000000; j+=i)
                prime[j] = true;
        }
    }
    n = numbers.size();
    sort(numbers.begin(),numbers.end());
    for(int i=0; i<n; i++){
        int temp = numbers[i] - '0';
        if(!prime[temp] && !check[temp]){
            check[temp] = true;
            ans+=1;
        }
        num_cnt[temp]+=1;
    }
    dfs(0,0);
    return ans;
}
