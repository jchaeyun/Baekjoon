#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
   queue<int> bridge;
    for(int i=0;i<bridge_length;i++) bridge.push(0);
   int time=0;
  int idx=0;
       while(idx<truck_weights.size()){
           time++; 
           if(!bridge.empty()){
                weight+=bridge.front();
                bridge.pop();
            }
           
            if(weight>=truck_weights[idx]){
                bridge.push(truck_weights[idx]);     
                weight-=truck_weights[idx];
                idx++;
            }else{
                bridge.push(0);
            }

            

        
    }
    time+=bridge_length;
    
    return time;
}