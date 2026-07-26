#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string,int> count;
    
    for(string name:participant){
        count[name]++;
    }
    for(string name:completion){
        count[name]--;
    }
    
    for(auto cnt:count){
        if(cnt.second>0){
            return cnt.first;
        }
    }
}