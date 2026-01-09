#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int num[1000005];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    queue<int> q;

    q.push(n);
    num[n] = 0; // 시작점
    int next;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        // 세가지 연산 /3,/2,-1

        if (cur % 3 == 0)
        {
            next = cur / 3;
            // 아직 방문 안 했으면
            if (num[next] == 0)
            {
                num[next] = num[cur] + 1;
                q.push(next);
            }
        }

        if (cur % 2 == 0)
        {
            next = cur / 2;
            if (num[next] == 0)
            {
                num[next] = num[cur] + 1;
                q.push(next);
            }
        }

        if (cur > 1)
        {
            next = cur - 1;
            if (num[next] == 0)
            {
                num[next] = num[cur] + 1;
                q.push(next);
            }
        }
    }

    cout << num[1];

    return 0;
}
