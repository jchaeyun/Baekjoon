#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string new_id) {
    string id="";
    //1
    for(int i=0;i<new_id.length();i++){
        new_id[i]=tolower(new_id[i]);
        //2
        if(!(isalnum(new_id[i])==0
             &&new_id[i]!='-'
             &&new_id[i]!='_'
             &&new_id[i]!='.')){

            id+=new_id[i]; //string에서 동적으로 늘어나게 하는법

        }
    }
    
    //3
    size_t pos=0;
    while((pos=id.find("..",pos))!=string::npos){
        id.replace(pos,2,".");
        pos=0;
    }
    
    //4
    if(!id.empty()&&id.front()=='.'){
        id=id.substr(1,id.length()-1);
    }
    if(!id.empty()&&id.back()=='.'){
        id=id.substr(0,id.length()-1);
    }
    
    //5
    if(id.empty()){
        id+='a';
    }
    
    //6
    if(id.length()>=16){
        id=id.substr(0,15);
        if(id.back()=='.'){
            id=id.substr(0,14);
        }
    }//7
    else if(id.length()<=2){
        char word=id.back();
        while(id.length()<3){
            id+=word;
        }
    }
    
    return id;
    
    
}