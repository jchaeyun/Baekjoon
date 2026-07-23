#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    
    vector<int> arr3(n,0);
    vector<string> map(n);

    //최종 지도
    for(int i=0;i<n;i++){
        arr3[i]=arr1[i]|arr2[i];
         //#,' '로 최종 지도 치환
         for(int j=0;j<n;j++){
             if((arr3[i]>>(n-1-j))&1)
                map[i]+='#';
             else{
                map[i]+=' '; 
             }
        }
        
        
    
    
        
    }
    
   return map;
   
    
    
    
    
}