#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 큰 수가 먼저 나옴
    priority_queue<int> pq;

    int n;
    cin >> n;
    // 1.데이터 넣기
    for (int i = 0; i < n; i++)
    {

        int num;
        cin >> num;

        if (num == 0)
        {
            if (!pq.empty())
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else
        {
            pq.push(num);
        }
    }

    return 0;
}