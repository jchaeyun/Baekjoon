#include <string>
#include <vector>
#include <queue>
#include <utility>


using namespace std;

int solution(vector<int> priorities, int location) {
    
    queue<pair<int,int>> q;
   
    priority_queue<int> pq; //자동 내림차순 정렬
  
  

    int count=0;
    //초기화
    for(int i=0;i<priorities.size();i++){
        q.push({priorities[i],i}); //{우선순위,원래위치}
        pq.push(priorities[i]);
    }
    
    while(!q.empty()){ 
        pair<int,int> cur=q.front(); //auto cur = q.front();
        q.pop(); //큐에서 꺼냄
        
        if(cur.first<pq.top()){
        q.push(cur); //뒤로 보냄
      
        }else{
        pq.pop(); //현재 프로세스 실행
        
        count++; //실행 순서
        if(cur.second==location){
            return count;
        }
        }
    }
    
    
}