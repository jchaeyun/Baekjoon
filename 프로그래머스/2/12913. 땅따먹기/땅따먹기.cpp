#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    
   
        for (int i = 1; i < land.size(); i++) {
        land[i][0] += max({land[i-1][1], land[i-1][2], land[i-1][3]});
        land[i][1] += max({land[i-1][0], land[i-1][2], land[i-1][3]});
        land[i][2] += max({land[i-1][0], land[i-1][1], land[i-1][3]});
        land[i][3] += max({land[i-1][0], land[i-1][1], land[i-1][2]});
        }
            
          
    
    int r=land.size()-1;
   
    return max({land[r][1],land[r][2],land[r][3],land[r][0]});

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
   

}