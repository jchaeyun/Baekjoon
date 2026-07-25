#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    stack<int> stk;
    vector<int> ans(numbers.size(),-1);
    
    
    for(int i=0;i<numbers.size()-1;i++){
        if(numbers[i]>=numbers[i+1]){
            stk.push(i); //바로 다음 숫자가 답이 아닌건 일단 스택에 넣어둠
        }else{
            ans[i]=numbers[i+1];
        }
        
        
            while(!stk.empty() &&(numbers[stk.top()]<numbers[i+1])){
                ans[stk.top()]=numbers[i+1];
                stk.pop();
            }
        
            
                
    }
    
    
    
    return ans;
}