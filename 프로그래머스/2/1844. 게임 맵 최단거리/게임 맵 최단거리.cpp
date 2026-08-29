#include<vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    //maps가 1이면 가능, 0이면 못감
    int dy[4]={-1,1,0,0};
    int dx[4]={0,0,-1,1};
    
    int n=maps.size(); //행 개수
    int m=maps[0].size(); //열 개수
    queue<pair<int,int>> q;
    vector<vector<bool>> visited(n,vector<bool>(m,false));
    vector<vector<int>> dist(n,vector<int>(m,-1));
    q.push({0,0});
    dist[0][0]=1;
    
    
    while(!q.empty()){
        
        auto [y,x]=q.front(); q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            
            if(ny>=n||ny<0||nx>=m||nx<0||maps[ny][nx]==0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx]=true;
            dist[ny][nx]=dist[y][x]+1;
            if(ny==n-1&&nx==m-1) return dist[n-1][m-1];
            q.push({ny,nx});
            
            
        }
    }
    return -1;
    
}