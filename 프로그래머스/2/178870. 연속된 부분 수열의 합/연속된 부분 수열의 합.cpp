#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int left=0;
    int right=0;
    int sum=sequence[0];
    int answerleft=0;
    int answerright=sequence.size()-1;
 
    
    while(left<=right&&right<sequence.size()){
       
        if(sum==k){
            if(right-left<answerright-answerleft){
                answerleft=left;
                answerright=right;
            }
            sum-=sequence[left];
            left++;
            
            
        }
        
        else if(sum<k){
            right++;
            if(right<sequence.size()){
                sum+=sequence[right];
            }
        }else{
            sum-=sequence[left];
            left++;  
        }
    }
    
    
    
    return {answerleft,answerright};
    
}