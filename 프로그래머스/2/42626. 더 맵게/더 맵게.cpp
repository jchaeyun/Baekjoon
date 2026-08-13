#include <string>
#include <vector>
#include <functional>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int,vector<int>,greater<int>> pq;
    
    for(int s:scoville){
        pq.push(s);
    }
    
    int scv=0;
    int count=0;
    
    //최소값이 K 미만일때
    while(!pq.empty()&&pq.top()<K){
        
        //합치기
        scv=pq.top();
        pq.pop();
        scv=scv+(pq.top()*2);
        pq.pop();
        
        //섞은 횟수 기록
        count++;
        pq.push(scv);
        
        if(pq.size()==1&&pq.top()<K) return -1;
       
        
    }
    
    
    return count;
    
}