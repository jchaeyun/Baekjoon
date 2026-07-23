#include <string>
#include <vector>


using namespace std;

int solution(string s) {
    
  vector<string> words={"zero","one","two","three","four","five","six","seven","eight","nine"};
    
   
    for(int i=0;i<words.size();i++){ //벡터 배열은 length()가 아니라 size()
        size_t pos=0;
        while((pos=s.find(words[i],pos))!=string::npos){
            s.replace(pos,words[i].length(),to_string(i));
        }
    }
    
        
    
    return stoi(s);
}   
    