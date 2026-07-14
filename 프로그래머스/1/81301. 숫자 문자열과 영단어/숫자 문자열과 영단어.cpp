#include <string>
#include <vector>


using namespace std;

int solution(string s) {
    
    vector<string> words={
        "zero","one","two","three","four","five","six","seven","eight","nine"
    };
    
    for(int i=0;i<10;i++){
        size_t pos=0;
        while((pos=s.find(words[i],pos))!=string::npos){
            s.replace(pos,words[i].length(),to_string(i));
            pos=+1;
        }
    }
    
    return stoi(s);
}