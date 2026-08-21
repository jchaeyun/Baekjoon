#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int answer=0; 
void dfs(int depth,int k, vector<bool>& visited,const vector<vector<int>>& dungeons){
    answer=max(answer,depth);//던전 수
    
    for(int i=0;i<dungeons.size();i++){
        if(visited[i]) continue;
        if(k<dungeons[i][0]) continue;
        
        
                visited[i]=true; 
                dfs(depth+1,k-dungeons[i][1],visited,dungeons);
                visited[i]=false;
        
        
    }
    
    
}

int solution(int k, vector<vector<int>> dungeons) {
    //그리디로 풀리는 문제면 8개라는 제한을 안둠->완전탐색 하라는 얘기
    //최소 피로도<=k인 경우 그 던전 돌고 count++ 아니면 건너뜀
    //visited 배열로 체크하기
    vector<bool> visited(dungeons.size(),false);
    dfs(0,k,visited,dungeons);
    
    return answer;
    
    
    
    
}