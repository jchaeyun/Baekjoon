#include <string>
#include <vector>

using namespace std;
void dfs(int current,vector<vector<int>> &computers,vector<bool> &visited){
   
    visited[current]=true;
    
    for(int next=0;next<computers.size();next++){
        if(computers[current][next]==1&&!visited[next]){
            dfs(next,computers,visited);
        }
    }
        
        
    
    
    return;
}
int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(computers.size(),false);
    int count=0;
    
    for(int i=0;i<computers.size();i++){
            
            if(!visited[i]){
                count++;
                dfs(i,computers,visited);
            }
        }
    
    return count;
}