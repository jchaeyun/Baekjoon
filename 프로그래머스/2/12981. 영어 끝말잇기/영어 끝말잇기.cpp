#include <string>
#include <vector>
#include <iostream>
#include <map>

//완전탐색
using namespace std;

vector<int> solution(int n, vector<string> words) {
   //몇번째인건 /n해서 0나오면 1번쨰,1나오면 2번째
    //map<string,int>해서 map[string]!=0이면 중복. ==0이면 map[string]++ words[i]에서 i/n해서 차례 구하고 %n해서 번호 구함 (0이면 n번째)
   map<string,int> m;
    int order=0;
    int num=0;
   for(int i=0;i<words.size();i++){
       //끝말잇기를 틀린 경우 또는
       //중복일 경우
       if((i>0&&words[i].front()!=words[i-1].back())||m[words[i]]!=0){
           num=i%n+1; //번호
           order=(i/n)+1; //차례
           
           break;
       }else{
           m[words[i]]++;
       }
   }
    return {num,order};
    
}