#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> s(n + 1); // 누적합 배열(s[0]~s[n])
    long long sum = 0;
    s[0] = 0;
    for (int u = 1; u <= n; u++)
    {
        int num;
        cin >> num;
        sum += num;
        s[u] = sum;
    }

    int i, j;
    for (int k = 0; k < m; k++)
    {
        cin >> i >> j;
        //(j까지 합)-(i-1까지의 합)
        cout << s[j] - s[i - 1] << '\n';
    }

    return 0;
}