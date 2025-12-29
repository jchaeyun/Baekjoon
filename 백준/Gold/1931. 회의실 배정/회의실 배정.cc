#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return a.first < b.first; // 끝나는 시간이 같으면 먼저 시작하는 것부터

    return a.second < b.second; // 먼저끝나는 순
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;

        v.push_back({start, end});
    }

    // 회의 먼저끝나는 순대로 정렬
    sort(v.begin(), v.end(), compare);

    int count = 1; // 회의 개수(일단 맨 처음 끝나는 회의는 무조건 함)
    int endTime = v[0].second;
    for (int j = 1; j < n; j++)
    {
        // 그 전 회의 종료시간보다 시작시간이 나중이면
        if (v[j].first >= endTime)
        {
            count++;
            endTime = v[j].second;
        }
    }

    cout << count;
    return 0;
}