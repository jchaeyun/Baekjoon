#include <string>
#include <vector>

using namespace std;
//완전탐색 dfs bfs 다됨
void dfs(int r,int n,vector<bool>& visited,const vector<vector<int>>& computers){
    for(int j=0;j<n;j++){
            if(computers[r][j]==1&&visited[j]!=true){
                visited[r]=true;
                dfs(j,n,visited,computers);
            }
        }
    return;
}
int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n,false);
    int net=0;
    
   
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,n,visited,computers);
                net++;
            }
        }
        
    
    //더이상 없으면 return. 한 턴 끝날때마다 net++
    return net;
}