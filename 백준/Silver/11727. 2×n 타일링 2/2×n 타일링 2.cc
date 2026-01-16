#include <iostream>
#include <algorithm>

using namespace std;

long long dp[1005];
int answer[1005];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 1x2->dp[n-2]가지
    // 2X1->dp[n-1]가지
    // 2x2->dp[n-2]가지

    // 그럼 dp[n]=dp[n-1]+2dp[n-2]?

    int n;
    cin >> n;
    dp[1] = 1 % 10007;

    dp[2] = 3 % 10007;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 2 * dp[i - 2];
        dp[i] %= 10007;
    }

    cout << dp[n];

    return 0;
}