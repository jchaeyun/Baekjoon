#include <string>
#include <vector> 
#include <algorithm> // sort

using namespace std;

vector<string> solution(vector<string> strings, int n) {
  sort(strings.begin(),strings.end(),[n](const string &a,const string &b){
      if(a[n]==b[n]){
          return a<b;
      }
     return a[n]<b[n]; //true 반환하면 a가 b앞에 오도록 정렬
  });
    
    return strings;
}