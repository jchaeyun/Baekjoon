#include <string>
#include <vector>

using namespace std;
int answer=0;

void dfs(const vector<int>& numbers,int target,int start,int sum){
    if(start==numbers.size()){
        if(sum==target){answer++;} 
        return;
    } 
    
    
        dfs(numbers,target,start+1,sum+numbers[start]);
        dfs(numbers,target,start+1,sum-numbers[start]);
    
    
  return;
}
int solution(vector<int> numbers, int target) {
        int sum=0;
        dfs(numbers,target,1,sum+numbers[0]);
        dfs(numbers,target,1,sum-numbers[0]);
    
    return answer;
}