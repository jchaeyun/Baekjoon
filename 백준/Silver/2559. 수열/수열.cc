#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<long long> v(n + 1, 0);
    long long max_value = -1e18; //-10의 18승(안전빵으로 최대한 작은 수)

    // 일단 누적합 구하기
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }

    // i번째부터 2개의 연속된 값이면 v[i+1]-v[i-1]하면됨
    // 세개의 연속된 값이면 v[i+2]-v[i-1] 즉 v[i+k-1]-v[i-1]
    for (int i = 1; i <= n; i++)
    {
        if (i + k - 1 > n)
            break;

        if (max_value < v[i + k - 1] - v[i - 1])
            max_value = v[i + k - 1] - v[i - 1];
    }

    cout << max_value;

    return 0;
}