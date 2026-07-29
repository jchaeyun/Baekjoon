#include <string>
#include <vector>

using namespace std;
//약수 쌍
vector<int> solution(int brown, int yellow) {
    int total=brown+yellow;
    int row=3;
    
    int col=total/row;
    
    int b=2*(col+row-2);
    //48 3 16 34->
    
    while(col>=row){
        
        if(total%row!=0){
            row++;
                
        }else{
            col=total/row;
            b=2*(col+row-2);

            if(b==brown){
                return {col,row};
            }else{
                row++;
            }

            
        }
        
        
    }
    
    return {};
        
}   
    
