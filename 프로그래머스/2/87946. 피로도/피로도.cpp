#include <string>
#include <vector>

using namespace std;

int answer=0;

void dfs(int k, const vector<vector<int>>& dungeons,vector<bool>&visited,int cnt){
    
    answer=max(cnt,answer); //최대 던전 수 기록. cnt는 지난 경로의 던전 수, answer는 지금까지 최대 던전 수
    
    if(k<=0) return; //종료 조건
    
    //다음에 방문할 던전 고르기
    for(int i=0;i<dungeons.size();i++){
        
        if(visited[i]) continue;
        
        if(k>=dungeons[i][0]){
            visited[i]=true;
            dfs(k-dungeons[i][1],dungeons,visited,cnt+1);
            visited[i]=false;
        }
        
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    //완전탐색 순열
   
    int cnt=0;
    vector<bool> visited(dungeons.size(),false);
    
    dfs(k,dungeons,visited,cnt);
    
    return answer;
}