#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a, string b){
    return a+b > b+a; 
}
string solution(vector<int> numbers) {
    string answer = "";
    vector <string> str_numbers;
    for(int i=0; i<numbers.size(); i++){
        str_numbers.push_back(to_string(numbers[i]));
    }
    sort(str_numbers.begin(),str_numbers.end(),cmp);
    for(int i=0; i<str_numbers.size(); i++)
        answer += str_numbers[i];
    if(answer[0]=='0')
        return "0";
    return answer;
}
