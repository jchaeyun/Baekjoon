#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    vector<string> v;
    
    //문자열로 바꾸기
    for(int x:numbers){
        v.push_back(to_string(x));
    }
    
    //커스텀 정렬
    sort(v.begin(),v.end(),[](string a,string b){
    
        return a+b>b+a;
    
    });
    
    string answer="";
    for(string s:v){
        answer+=s;
    }
    if(answer[0]=='0'){
        return "0";
    }
    return answer;
}