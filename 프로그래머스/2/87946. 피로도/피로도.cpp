#include <string>
#include <vector>

using namespace std;
int ans=0;
void dfs(int k,const vector<vector<int>>& dungeons,int cnt,vector<bool>& visited){
    //종료조건:k가 0 이하일때
    if(k<=0){
        return;
    }
    //모든 곳을 체크함(순서가 다르면 다른 루트이므로)
    for(int i=0;i<dungeons.size();i++){
        if(!visited[i]&&(k>=dungeons[i][0])){
            visited[i]=true;
            dfs(k-dungeons[i][1],dungeons,cnt+1,visited);
            visited[i]=false;
        }
    }
    ans=max(ans,cnt);
}

int solution(int k, vector<vector<int>> dungeons) {
    
    
    // 시작점은 다양하게(가능한 모든 점에서 시작)
    for(int i=0;i<dungeons.size();i++){
        int cnt=0;
        vector<bool> visited(dungeons.size(),false);
        if(k>=dungeons[i][0]){
            visited[i]=true;
            dfs(k-dungeons[i][1],dungeons,cnt+1,visited);
            visited[i]=false;
        }
       
    }
    
    return ans;
  
}