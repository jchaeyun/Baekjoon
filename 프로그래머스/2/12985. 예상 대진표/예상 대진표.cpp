#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    //몇번째 그룹에 있는지 체크
    //n은 매 단계마다 n/2됨
    //a는 i번째 그룹이면 다음 단계에 i됨
    //b는 i+1번째 그룹이면 다음단계에 i+1됨
    //n/2개의 그룹. 2*i>=a면 a는 i번째그룹
    //a,b가 같은 그룹에 있을때 리턴
    int grpa;
    int grpb;
    int rnd=0;
    while(n/2>0){
        n/=2;
        rnd++; //현재 라운드
        
        //a 그룹찾기
        for(int i=1;i<=n;i++){
            if(2*i>=a){
                grpa=i;
                break;
            }
            
            
        }
        //b 그룹찾기
        for(int i=1;i<=n;i++){
            if(2*i>=b){
                grpb=i;
                break;
            }
        }
        
        if(grpa==grpb) return rnd;
        a=grpa;
        b=grpb;
    }
}