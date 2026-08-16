#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    //2담고 3이 2보다 크면 3담고 똑같거나 작으면 스택에 넣고 
    stack<pair<int,int>> stk;
    vector<int> answer(numbers.size(),-1);
    for(int i=0;i<numbers.size();i++){
        while(!stk.empty()&&stk.top().second<numbers[i]){
            answer[stk.top().first]=numbers[i];
            stk.pop();
            
        }
            
        stk.push({i,numbers[i]});
    }
    
    return answer;
}