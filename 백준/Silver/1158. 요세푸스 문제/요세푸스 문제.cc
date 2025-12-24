#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    deque<int> dq;
    for (int j = 1; j < n + 1; j++)
    {
        dq.push_back(j);
    }
    cout << '<';
    while (dq.size() > 1) // 1개 남기 전까지 삭제
    {

        for (int i = 0; i < k - 1; i++) // k-1명만 뒤로 보내기
        {
            dq.push_back(dq.front()); // 맨 앞의 값을 맨 뒤에 집어넣고
            dq.pop_front();           // 맨 앞에서 삭제
        }
        cout << dq.front() << ", ";
        dq.pop_front(); // 세번째 순회일때 삭제
    }
    cout << dq.front() << '>';

    return 0;
}