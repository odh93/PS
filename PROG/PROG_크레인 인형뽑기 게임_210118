#include <string>
#include <vector>
using namespace std;
int pick_up(vector<vector<int>> &board,int j){
    j-=1;
    int N = board.size();
    for(int i=0; i<N; i++){
        if(board[i][j]!=0)
        {
            int temp = board[i][j];
            board[i][j] = 0;
            return temp;
        }
            
    }
    return 0;
}
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector <int> stack;
    for(int i=0; i<moves.size(); i++){
        int temp = pick_up(board,moves[i]);
        if(temp == 0)
            continue;
        if(stack.size() > 0){
            if(stack.back() == temp)
            {
                answer += 2;
                stack.pop_back();
            }
            else
                stack.push_back(temp);
        }
        else
            stack.push_back(temp);
    }
    return answer;
}
