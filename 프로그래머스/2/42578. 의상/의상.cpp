#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    //의상 종류마다 1개까지만 착용 가능
    map<string,int> m; //map<의상종류,int>
    
    for(int i=0;i<clothes.size();i++){
            m[clothes[i][1]]++;  
    }
    
    long long ans=1;
    
    //안입는 경우 포함해 전부 곱하고 아무것도 안입는 경우 빼기
    for(auto[s,num]:m){
        ans*=(num+1);
    }
    return ans-1;
    
 
   
    
    
}