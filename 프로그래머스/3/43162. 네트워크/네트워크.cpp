#include <string>
#include <vector>

using namespace std;
int net=0;
void dfs(int cur,const vector<vector<int>>& computers,vector<bool>& connected){ 
    
    connected[cur]=true;
    
        for(int i=0;i<computers.size();i++){
            if(connected[i]) continue;
            
             if(computers[cur][i]){ //연결된 컴퓨터 찾음
            dfs(i,computers,connected); //연결된 다른 컴퓨터 찾음
            }
    
        }
       
    //연결된 컴퓨터 찾기 실패
    return;
    
}
int solution(int n, vector<vector<int>> computers) {
  //dfs 바닥을 찍으면 ans++
   
    vector<bool> connected(n,false);
  
    int net=0;
    
    for(int i=0;i<n;i++){
        if(connected[i]) continue;
        dfs(i,computers,connected);
        net++;
    }
    
    return net;
    
}