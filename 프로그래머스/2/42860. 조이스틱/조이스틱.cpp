#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    // ABCDE FGHIJ KLM | NOPQR STUVW XYZ 
    // 전자: 타겟-'A' 후자:이전알파벳 'Z'-타겟+1
    // 절반 길이만 오른쪽 이동, 나머지는 왼쪽이동? A연속을 어케 처리하지
    // A몇개인지 세보고 반대쪽으로 가는횟수랑 비교 000AAAA0
    int idx=0;
    int count=0;
    int idxA=0;
    
    //알파벳 바꾸기
    while(idx<=name.size()-1){
        
        if(name[idx]-'A'<=13){
            count=count+(name[idx]-'A');
        }else{
            count=count+('Z'-name[idx]+1);
        }
        idx++;
    }
    
    //좌우이동
    
    int move=name.size()-1; //일단 전체 이동횟수 더함
    int next=0;
    for(int i=0;i<name.size();i++){
        next=i+1;
        
        while(next<name.size()&&name[next]=='A'){
            next++;
        }
        
        //i 먼저 갔다가 반대편으로 가서 처리하고 다시 돌아오기
        move=min(move,i*2+((int)name.size()-next));
        //반대편 먼저 갔다가 i로 가기
        move=min(move,i+2*((int)name.size()-next));
        
    }
       
        
  
    return count+move;
}