#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int total=brown+yellow;
    int row=3; //세로
    int col=3; //가로
    
    while(true){
        if(total%col!=0){
            col++;
            continue;
        }
        
        row=total/col;
        
        if(col<row){
            col++;
           continue;
        }
        
        if(brown-2*(col+row-2)){
            col++;
            continue;
        }
           return {col,row};  
        
        
    }
    
}