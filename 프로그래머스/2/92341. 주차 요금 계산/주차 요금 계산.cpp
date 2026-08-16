#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    
    map<int,int> inTime;
    map<int,int> totalTime;
    vector<int> answer;
    
    for(int i=0;i<records.size();i++){
        size_t pos=0;
        int carNum=stoi(records[i].substr(6,4));
        int time=stoi(records[i].substr(0,2))*60+stoi(records[i].substr(3,2));
            
        if((pos=records[i].find("IN"))!=string::npos){
            inTime[carNum]=time;
        }else{
            
            int total=time-inTime[carNum];
            totalTime[carNum]+=total;
            inTime.erase(carNum);
        }
    }
    
   
    
    for(auto [carNum, time]:inTime){
        int total=23*60+59-time;
        totalTime[carNum]+=total;
        
    }
    
    //요금 계산
     for(auto [carNum, total]:totalTime){
        if(totalTime[carNum]>fees[0]){
            int extra=total-fees[0];
            int unit=(extra+fees[2]-1)/fees[2]; 
            int fee=unit*fees[3]+fees[1];
            answer.push_back(fee);
            
        }else{
            answer.push_back(fees[1]);
        }
    }
  
    return answer;
}