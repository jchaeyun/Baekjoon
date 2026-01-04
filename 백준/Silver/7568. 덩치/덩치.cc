#include <iostream>
#include <vector>
#include <utility> //pair쓰려면 필요

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int wgt, hgt;
        cin >> wgt >> hgt;

        v.push_back({wgt, hgt});
    }

    for (int j = 0; j < n; j++)
    {
        // 덩치 순위. 일단 제일 크다고 가정
        int num = 1;

        for (int k = 0; k < n; k++)
        {
            // v[j]가 덩치가 클때
            if (v[j].first > v[k].first && v[j].second > v[k].second)
            {
                // 순위 유지
                continue;

            } // v[j]가 덩치가 작을 때
            else if (v[j].first < v[k].first && v[j].second < v[k].second)
            {
                // 순위 하락
                num++;
            } // 덩치 우열 정할 수 없을 때
            else
            {
                // 공동 num등
                continue;
            }
                }
        cout << num << ' ';
    }

    return 0;
}