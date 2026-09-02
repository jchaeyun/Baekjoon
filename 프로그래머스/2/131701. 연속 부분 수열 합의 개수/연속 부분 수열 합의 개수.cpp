#include <string>
#include <vector>
#include <set>


using namespace std;

int solution(vector<int> elements) {
   
    set<int> s;
   int n=elements.size();
    for(int len=1;len<=n;len++){//길이
       
       for(int start=0;start<n;start++){//시작점
           int sum=0;
           for(int j=0;j<len;j++){
               sum+=elements[(start+j)%n];
           }
           s.insert(sum);
       }
       
        
        
        
        
    }
    
    return s.size();
}