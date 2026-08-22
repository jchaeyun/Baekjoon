#include <string>
#include <vector>

using namespace std;

int cnt=0;

void dfs(int answer,const vector<int>& numbers,int target,int idx){
    if(idx==numbers.size()){
        if(answer==target){
        cnt++;
        
        }
        return;
    }
    
    
   
        //덧셈
        dfs(answer+numbers[idx],numbers,target,idx+1);
        //뺄셈
        dfs(answer-numbers[idx],numbers,target,idx+1);

    
  
    
    
}

int solution(vector<int> numbers, int target) {
   //개수가 작다...완전탐색
   //dfs
    //더하고 
    
    int answer=0;
     
    dfs(answer,numbers,target,0);
     
    
    return cnt;
}