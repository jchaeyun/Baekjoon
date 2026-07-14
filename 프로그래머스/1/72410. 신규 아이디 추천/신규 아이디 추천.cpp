#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    //1.lower
    for(int i=0;i<new_id.length();i++){
        new_id[i]=tolower(new_id[i]);
    }
    //2
    string step2="";
    for(int i=0;i<new_id.length();i++){  
        if(isalnum(new_id[i])||new_id[i]=='.'||new_id[i]=='-'||new_id[i]=='_'){
            step2+=new_id[i];
        }
    }
    new_id=step2;
    
    //3
    size_t pos=0;
    while((pos=new_id.find(".."))!=string::npos){
       new_id.replace(pos,2,".");
    }
    //erase
    if(!new_id.empty()&&new_id.front()=='.') new_id.erase(0,1);
    if(!new_id.empty()&&new_id.back()=='.') new_id.pop_back();
    //
    if(new_id.empty()) new_id+="a";
    //erase 두번
    if(new_id.length()>=16) {
        new_id=new_id.substr(0,15);
        if(new_id.back()=='.') new_id.pop_back();
    }
    if(new_id.length()<=2){
        while(new_id.length()<3){
            new_id+=new_id.back();
        }
    }
    return new_id;
}