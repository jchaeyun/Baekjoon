#include <string>
#include <vector>
#include <set>

using namespace std;
 //가능한 숫자 전부 만들어서 v에 넣기
void dfs(string &numbers,string current,vector<bool> &used,set<int> &v){
        
        for(int i=0;i<numbers.size();i++){
            if(used[i]){
                continue;
            }
            
            used[i]=true;
            
            string next=current+numbers[i];
            
            v.insert(stoi(next)); //insert. set은 중복을 거름
            
            dfs(numbers,next,used,v);
            
            used[i]=false;
        }
        
    }
  
bool isPrime(int n){
     if(n<2){
         return false;
     }
        
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
            
        
    }
    return true;
}
int solution(string numbers) {
    vector<bool> used(numbers.size(),false);
    string current="";
    set<int> v;
   
    
    dfs(numbers,current,used,v);
    
 
    int count=0;
         
    for(int n:v){
        if(isPrime(n)){
         count++;   
        }
    }
    
    return count;
   
    
    
    
  
}