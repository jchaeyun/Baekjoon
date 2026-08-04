#include<vector>
#include <queue>
using namespace std;
int bfs(int r,int c,vector<vector<int> >& maps,vector<vector<int> >& dist){
    int n=maps.size();
    int m=maps[0].size();
    queue<pair<int,int>> q;
    
    int br[4]={-1,1,0,0};
    int bc[4]={0,0,-1,1};
    
    maps[r][c]=0;
    q.push({r,c});
    
    while(!q.empty()){
        
        int currentR=q.front().first;
        int currentC=q.front().second;
        q.pop();
        
    for(int i=0;i<4;i++){
        int nr=currentR+br[i];
        int nc=currentC+bc[i];
        
        if(nr<0|| nr>=n||nc<0||nc>=m) continue;
          
         
        
        if(maps[nr][nc]==1){
               dist[nr][nc]=dist[currentR][currentC]+1; //거리 기록
               maps[nr][nc]=0;
               q.push({nr,nc});
            if(nr==n-1&&nc==m-1) return dist[n-1][m-1];
         }
    }
          
        
    }
    
    return -1;
    
    
}

int solution(vector<vector<int> > maps)
{   
    int r=0;
    int c=0;
    vector<vector<int> > dist(maps.size(),vector<int>(maps[0].size(),0));
    dist[0][0]=1;
    int answer=bfs(r,c,maps,dist);
    
    return answer;
}