#include <string>
#include <vector>
#include <map>
using namespace std;
map <string,bool> m;
bool solution(vector<string> phone_book) {
    for(int i=0; i<phone_book.size(); i++)
        m[phone_book[i]]=true;
    for(int i=0; i<phone_book.size(); i++){
        for(int j=0; j<phone_book[i].size(); j++){
            if(m[phone_book[i].substr(0,j)])
                return false;
        }
    }    
    return true;
}
