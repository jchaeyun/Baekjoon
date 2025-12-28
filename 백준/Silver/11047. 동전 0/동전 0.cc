#include <iostream>
#include <string>
#include <vector>
#include <algorithm> //unique

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;

    cin >> n >> k;

    vector<int> v(n);
    int count = 0; // 동전 개수

    for (int i = 0; i < n; i++)
    {
        cin >> v[i]; // 동전의 가치
    }

    for (int j = n - 1; j >= 0; j--)
    {

        if (v[j] <= k)
        {
            count += k / v[j]; // 동전 개수
            k = k % v[j];      // 남은 금액 갱신
        }
    }

    cout << count;

    return 0;
}