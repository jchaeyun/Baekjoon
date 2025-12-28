#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {

        cin >> v[i];
    }

    // 작은순대로 나열
    sort(v.begin(), v.end());

    int sum = 0; // 기다려야 하는 시간의 최소 합

    int k = 0;
    for (int j = n; j > 0; j--)
    {
        sum += j * v[k];
        k++;
    }

    cout << sum;

    return 0;
}