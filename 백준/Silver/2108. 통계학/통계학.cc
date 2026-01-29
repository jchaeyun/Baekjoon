#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int number[8001];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        sum += num; // 입력과 동시에 합계 계산
        //-4000이면 number[0]에, -2000이면 number[2000],1이면 number[4001];
        number[num + 4000]++;

        v.push_back(num);
    }

    // 산술평균
    double nbr = n;
    double avg = round(sum / nbr); // 반올림
    if (avg == -0)
        avg = 0; //-0.3일 경우 반올림 시 -0 방지

    // 정수형 출력 보장
    cout << (int)avg << '\n';

    // 중앙값
    sort(v.begin(), v.end());
    cout << v[n / 2] << '\n';

    // 최빈값
    int max = 0;
    for (int i = 0; i < 8001; i++)
    {
        if (number[i] > max)
        {
            max = number[i];
        }
    }

    // 최빈값
    vector<int> freqs;
    for (int i = 0; i < 8001; i++)
    {
        if (number[i] == max)
        {
            freqs.push_back(i - 4000);
        }
    }

    if (freqs.size() > 1)
    {
        cout << freqs[1] << '\n';
    }
    else
    {
        cout << freqs[0] << '\n';
    }

    // 범위
    int range = v.back() - v.front();
    cout << range << '\n';
    return 0;
}