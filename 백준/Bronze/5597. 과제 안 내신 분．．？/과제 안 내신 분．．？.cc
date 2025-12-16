#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool check[31] = {0}; // 31칸짜리 출석부(0번은 안쓰고 1~30번 사용)
                          // bool 타입은 false(0)로 자동 초기화하거나 {0}으로 명시

    // 제출한 28명의 번호를 받아서 출석부에 체크
    for (int i = 0; i < 28; i++)
    {
        int n;
        cin >> n;
        check[n] = true; // n번 학생 왔음!
    }

    // 1번부터 30번까지 훑으면서 체크 안된 사람(false) 확인
    for (int j = 1; j <= 30; j++)
    {
        if (check[j] == false)
        {
            cout << j << '\n';
        }
    }

    return 0;
}