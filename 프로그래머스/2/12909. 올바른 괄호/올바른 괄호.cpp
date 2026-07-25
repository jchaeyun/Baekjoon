#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int count=0;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            count++;
        }else{
            count--;
        }
        
        if(count<0){
            return false;
        }
    }
    if(count!=0){
        return false;
    }else{
        return true;
    }
    

   
}