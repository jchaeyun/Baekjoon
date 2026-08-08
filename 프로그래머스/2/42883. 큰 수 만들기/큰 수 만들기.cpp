#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer="";
    
    for(char x:number){
        while(!answer.empty()&&x>answer.back()&&k>0){
            answer.pop_back();
            k--;
        }
        
        answer.push_back(x);
    }
    
    while(k>0){
        answer.pop_back();
        k--;
    }
 
    return answer;
}