#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    //일단 각자 남은 일수 계산
    //큐 맨앞 작업보다 빨리 끝나면 큐에 넣어두고
    //큐의 맨앞 작업보다 늦게 끝나거나 같으면 그 전 작업들 큐에서 방출(count로 세서 배열에 넣기) 
    vector<int> days;
    
    vector<int> deploy;
    for(int i=0;i<progresses.size();i++){
        int day=(100-progresses[i]+speeds[i]-1)/speeds[i];
        days.push_back(day);
    }
    
    int deployday=days[0];
    int count=1;
    
    for(int i=1;i<days.size();i++){
        if(days[i]<=deployday){
            count++;
        }else{
            
            deploy.push_back(count); //이전 묶음 배포
            deployday=days[i];
            count=1;
        }
        
        
        
    }
    
     deploy.push_back(count);
   
    
    return deploy;
}