#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> & numbers, int target,int &answer,int sum,int count){
   
    //멈추는 조건
       if(count==numbers.size()){
           if(sum==target){
            answer++; 
            
        }
         
        return;
       }
    
        dfs(numbers,target,answer,sum-numbers[count],count+1);
        
        
        dfs(numbers,target,answer,sum+numbers[count],count+1);
        
    
    return;
}

int solution(vector<int> numbers, int target) {
    int sum=0;
    int answer=0;
    int count=0;
    dfs(numbers,target,answer,sum,count);
    
    return answer;
}