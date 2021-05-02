#include <string>
#include <vector>
using namespace std;

int solution(vector<int> a) {
    int answer = 0,min;
    vector<int> left(a.size()),right(a.size());
    min = a[0];
    for(int i=0; i<a.size(); i++){
        if(a[i] < min)
            min = a[i];
        left[i] = min;
    }
    min = a[a.size()-1];
    for(int i=a.size()-1; i>=0; i--){
        if(a[i] < min)
            min = a[i];
        right[i] = min;
    }
    for(int i=0; i<a.size(); i++){
        if(a[i]<=left[i] || a[i]<=right[i])
            answer+=1;
    }
    return answer;
}
