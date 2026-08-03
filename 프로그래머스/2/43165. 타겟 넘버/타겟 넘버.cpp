#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &numbers, int target,int index,int sum,int &answer){
    
    if(numbers.size()==index){
        if(target==sum){
            answer++;
            return;
        }
        
        return;
    }
    
    dfs(numbers,target,index+1,sum+numbers[index],answer);
    
    dfs(numbers,target,index+1,sum-numbers[index],answer);
}

int solution(vector<int> numbers, int target) {
    int index=0;
    int answer=0;
    int sum=0;
    
    dfs(numbers,target,index,sum,answer);
    
    return answer;
}