#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool isPossible(long long ans,int n,const vector<int>& times){
    long long sum=0;
    for(int t:times){
        sum+=ans/t;
    }
    return sum >= n;
}

long long solution(int n, vector<int> times) {
    //sum+=전체시간/times
    //sum>=n이면 전체시간 줄여보고(일단 그 시간을 후보로 기록)
    //sum<n이면 전체시간 늘리기
    sort(times.begin(),times.end());
    long long sum=0;
    long long ans=n;
    long long left=1;
    long long right=(long long)n*times.back();
 
    while(left<=right){
        long long mid=left+(right-left)/2;
        if(isPossible(mid,n,times)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    
    return ans;
    
}