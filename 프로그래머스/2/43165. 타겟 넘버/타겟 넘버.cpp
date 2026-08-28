#include <string>
#include <vector>

using namespace std;
int answer=0;

void dfs(const vector<int>& numbers,int target,int cnt,int i){
        
        if(i==numbers.size()){
            if(cnt==target) {
            answer++;
            }
            return;
        }
        
        dfs(numbers,target,cnt+numbers[i],i+1);
        dfs(numbers,target,cnt-numbers[i],i+1);
    
    
    
}

int solution(vector<int> numbers, int target) {
    //종료조건:타겟넘버될때 기록
    int cnt=0;
    
        dfs(numbers,target,cnt+numbers[0],1);
        dfs(numbers,target,cnt-numbers[0],1);
    
    
    return answer;
}