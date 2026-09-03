#include <string>
#include <vector>
#include <queue> //priority_queue
#include <algorithm> //sort

using namespace std;

int solution(vector<int> priorities, int location) {
    int ans=0;
    vector<int> v;
    queue<pair<int,int>> q;
    for(int i=0;i<priorities.size();i++){
        v.push_back(priorities[i]);
        q.push({priorities[i],i});//큐 q는 {priorities,idx}
    }
    //priorities를 내림차순으로 정렬한 v
    sort(v.begin(),v.end(),greater<int>()); 
    
    //v랑 일치하지 않으면 뒤로 보냄 
    int i=0;
    while(!q.empty()){
        auto [p,idx]=q.front(); q.pop();
        if(v[i]!=p){
           q.push({p,idx});
        }else{
            ans++;
            i++;
            if(idx==location) return ans;
            
        }
    }
    //v랑 일치하면 pop,ans++ 그리고 이게 idx도 location이랑 일치하면 return ans;
    
    
}