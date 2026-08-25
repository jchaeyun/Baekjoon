#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//완전탐색,dp->여기까지의 최적값을 저장
int solution(vector<vector<int> > land)
{
    int r=land.size(); //행 개수
    
    
    for(int i=1;i<r;i++){
        land[i][0]+=max({land[i-1][1],land[i-1][2],land[i-1][3]});
        land[i][1]+=max({land[i-1][0],land[i-1][2],land[i-1][3]});
        land[i][2]+=max({land[i-1][1],land[i-1][0],land[i-1][3]});
        land[i][3]+=max({land[i-1][1],land[i-1][2],land[i-1][0]});
        
    }
    
    int ans=max({land[r-1][0],land[r-1][1],land[r-1][2]});
    return max(ans,land[r-1][3]);
    
}