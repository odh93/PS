#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int,int>> food;

bool cmp(pair<int,int> p1, pair<int,int> p2)
{
    return p1.second < p2.second;
}
int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int size = food_times.size();
    for(int i=0; i<size; i++)
    {
        food.push_back({food_times[i],i+1});
    }
    sort(food.begin(),food.end());
    long long totalsum =0;
    long long sum = 0;
   
    for(int i=0; i<size; i++)
    {
       totalsum = sum;
        if((i==0) && ((size-i) * food[i].first <=k))
        {
            sum = (size-i)*food[i].first;
            continue;
        }
        else if(i!=0)
        {
            sum += (food[i].first - food[i-1].first) * (size-i);
            if(sum<=k)
                continue;
        }
        
        k-= totalsum;
        sort(food.begin() + i , food.end(),cmp);
        int cnt = size - i;
        return food[i+(k%cnt)].second;
    }
   
    return -1;
}
