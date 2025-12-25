#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n; // 테스트 케이스의 수

    for (int i = 0; i < n; i++)
    {

        int m, idx;
        cin >> m >> idx;

        //<중요도,원래 인덱스>를 저장하는 큐
        queue<pair<int, int>> q;

        // 중요도만 저장해서 자동으로 내림차순 정렬해주는 우선 순위 큐
        priority_queue<int> pq;

        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            q.push({num, j}); // 중요도와 인덱스를 같이 저장
            pq.push(num);     // 중요도만 따로 저장(자동 정렬됨)
        }

        int count = 0;

        while (!q.empty())
        {

            // 1.큐의 가장 앞에 있는 문서를 확인
            int current_priority = q.front().first;
            int current_idx = q.front().second;
            q.pop(); // 문서 중요도.인덱스 큐에서 제거

            // 2.현재 문서의 중요도가 가장 높은 중요도(pq.top)과 같은지 확인
            if (pq.top() == current_priority)
            {
                pq.pop(); // 인쇄. 우선순위 큐에서도 해당 중요도 제거
                count++;  // 인쇄 횟수 증가

                // 3.만약 지금 인쇄한 게 우리가 찾던 그 문서라면(idx)
                if (current_idx == idx)
                {
                    cout << count << '\n';
                    break;
                }
            }
            else
            {
                // 중요도가 낮으면 인쇄하지 않고 뒤로 보냄
                q.push({current_priority, current_idx});
            }
        }
    }

    return 0;
}