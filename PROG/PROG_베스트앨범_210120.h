#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map <string,pair<vector<pair<int,int>>,int>> m;
bool cmp1(pair<string,pair<vector<pair<int,int>>,int>> a,pair<string,pair<vector<pair<int,int>>,int>> b){
    return a.second.second > b.second.second;
}
bool cmp2(pair<int,int> a, pair<int,int> b){
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0; i<genres.size(); i++){
        m[genres[i]].first.push_back({plays[i],i});
        m[genres[i]].second+= plays[i];
    }
    vector <pair<string,pair<vector<pair<int,int>>,int>>> v(m.begin(),m.end());
    sort(v.begin(),v.end(),cmp1);
    for(int i=0; i<v.size(); i++){
        sort(v[i].second.first.begin(),v[i].second.first.end(),cmp2);
        if(v[i].second.first.size()>1){
            answer.push_back(v[i].second.first[0].second);
            answer.push_back(v[i].second.first[1].second);
        }
        else
            answer.push_back(v[i].second.first[0].second);
            
    }
    return answer;
}
