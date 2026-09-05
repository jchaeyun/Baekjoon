#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
   vector<int> ans(prices.size(),0);
    
    for(int i=0;i<prices.size();i++){
        for(int j=i+1;j<prices.size();j++){
           ans[i]++;
            
            if(prices[i]>prices[j]){
                
                break;
            } 
        }
   
    }
    

   return ans;
}