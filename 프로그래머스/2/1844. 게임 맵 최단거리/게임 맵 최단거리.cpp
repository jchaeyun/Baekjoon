#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    //n행 m열
    //0은 못지나가고 1이면 갈수있음
    //시작위치:1,1 도착지:n,m. 못다다르면 
    //bfs
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    int n=maps.size(); //y,행
    int m=maps[0].size(); //x, 열
    
    queue<pair<int,int>> q;
    vector<vector<int>> visited(n,vector<int>(m,1));
    
    q.push({0,0});
  
    while(!q.empty()){
        auto [y,x]=q.front(); q.pop();
        if(y==n-1&&x==m-1) break;
        
        for(int i=0;i<4;i++){
            int r=y+dy[i];
            int c=x+dx[i];
            if(r<0||r>=n||c<0||c>=m) continue;
            if(visited[r][c]==1&&maps[r][c]==1){
                visited[r][c]+=visited[y][x];
                q.push({r,c});
            }
        }
    }
    if(visited[n-1][m-1]==1){
        return -1;
    }else{
      return visited[n-1][m-1];
    }
    
    
   
}