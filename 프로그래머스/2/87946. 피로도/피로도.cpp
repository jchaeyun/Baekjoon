#include <string>
#include <vector>

using namespace std;

void dfs(int k,vector<vector<int>>& dungeons,int &answer,int count,vector<bool> &visited){
    answer=max(count,answer);
    
    for(int i=0;i<dungeons.size();i++){
        if(k<dungeons[i][0]){
            continue;
        }
        
        if(visited[i]){
            continue;
        }
        
        visited[i]=true;
        dfs(k-dungeons[i][1],dungeons,answer,count+1,visited);
        visited[i]=false;
        
        
        
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer=0;
    int count=0;
    vector<bool> visited(dungeons.size(),false);
    
    dfs(k,dungeons,answer,count,visited);
    
    return answer;
    
    
}