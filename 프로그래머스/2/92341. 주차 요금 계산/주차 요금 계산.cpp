#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<int,int> m;
    map<int,int> in;
    vector<int> result;
    
    //시각을 숫자로 바꿈
    for(int i=0;i<records.size();i++){
        int hour=stoi(records[i].substr(0,2)); //시
        int min=stoi(records[i].substr(3,2)); //분
        int car=stoi(records[i].substr(6,4)); //차량번호
        string inout=records[i].substr(11); //O 또는 I
        
        int time=hour*60+min;
        
        
        if(inout=="IN"){
            in[car]=time;
        }else{
            m[car]+=time-in[car];
            in.erase(car);
        }
        
        
    }
    
    for(auto p:in){
        //out이 없어서 in에 남아있는 경우(앞에서 out하면 erase함)
        
            m[p.first]+=1439-p.second;
        
    }
    
    
    
    //180분 이하,이상 나눠서 요금 구함
    for(auto p:m){
        
        
        if(p.second<=fees[0]){
            result.push_back(fees[1]);
        }else{
            int total=fees[1]+((p.second-fees[0]+fees[2]-1)/fees[2])*fees[3];
            result.push_back(total);
        }
    }
    return result;
}