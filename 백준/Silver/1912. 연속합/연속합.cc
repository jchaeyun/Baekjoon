#include <iostream>
#include <algorithm> //max 사용

using namespace std;

long long sum[100005];
long long score[100005];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {

        cin >> score[i];
    }

    sum[1] = score[1];

    // i번째 숫자일때
    // 1.sum[i-1]+score[i]와 score[i] 비교

    for (int i = 2; i <= n; i++)
    {
        sum[i] = max(sum[i - 1] + score[i], score[i]);
    }

    long long result = sum[1];
    for (int i = 2; i <= n; i++)
    {
        if (sum[i] > result)
        {
            result = sum[i];
        }
    }

    cout << result;

    return 0;
}
