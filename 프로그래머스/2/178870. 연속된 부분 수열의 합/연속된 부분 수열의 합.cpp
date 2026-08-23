#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int left=0;
    int right=0;
    vector<int> v;
    v.push_back(left);
    v.push_back(right);
     int sum=sequence[left];
    int mindist=sequence.size();
    while(right<sequence.size()&&left<=right){
        if(sum==k){
            if(mindist>right-left){//거리가 짧을때만 갱신
                mindist=right-left;
                v.pop_back();
                v.pop_back();
                v.push_back(left);
                v.push_back(right);
                
            }
            sum-=sequence[left];    
            left++;
            
            
            
          
        }
        else if(sum>k){
            sum-=sequence[left];
            left++;
            
        }else{
            right++;
            sum+=sequence[right];
           
            
        }
        
    }
    
    return v;
}