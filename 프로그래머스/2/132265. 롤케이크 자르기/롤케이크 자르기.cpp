#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    //구역을 먼저 나눠야하나?
    map<int,int> m;

    vector<int> left(topping.size()); //누적 가짓수(왼쪽 기준)
    vector<int> right(topping.size());//누적 가짓수(오른쪽 기준)
    
    //i 기준으로 잘랐을때 누적 토핑 종류 수(왼쪽) 저장
    for(int i=0;i<topping.size();i++){
        int key=topping[i];
        m[key]++;
        left[i]=m.size(); 
    }
    m.clear();
    //i 기준으로 잘랐을 때 누적 토핑 종류 수(오른쪽) 저장
    for(int i=topping.size()-1;i>=0;i--){
        int key=topping[i];
        m[key]++;
        right[i]=m.size();
    }
    
    int count=0;
   
    for(int i=0;i<left.size()-1;i++){
        if(left[i]==right[i+1]){
            count++;
        }
    }
    
    
    
    return count;
 
}