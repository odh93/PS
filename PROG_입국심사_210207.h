#include <string>
#include <vector>
#include <algorithm>
using namespace std;
long long low,high,mid,sum;
long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(),times.end());
    low = 1;
    high = (long long)times[times.size()-1]*(long long )n;
    while(low <= high)
    {
        mid = (low+high)/2;
        sum = 0;
        for(int i=0; i<times.size(); i++)
            sum+= mid /times[i];
        if(sum >= n)
        {
            high = mid-1;
            answer = mid;
        }
        else
            low = mid+1;
    }
    return answer;
}
