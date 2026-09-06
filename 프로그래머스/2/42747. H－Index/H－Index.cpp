#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    //65310
    //idx+1>=citations[idx]면 citations[idx]반환
    sort(citations.begin(),citations.end(),greater<>());
    
    for(int i=0;i<citations.size();i++){
        if(i+1>=citations[i]) return i;
    }
    
    return citations.size();
}