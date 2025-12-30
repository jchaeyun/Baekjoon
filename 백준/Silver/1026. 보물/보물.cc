#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int A;
        cin >> A;

        a.push_back(A);
    }

    for (int j = 0; j < n; j++)
    {
        int B;
        cin >> B;

        b.push_back(B);
    }

    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end());

    long long result = 0;
    for (int k = 0; k < n; k++)
    {
        result = result + a[k] * b[k];
    }

    cout << result;

    return 0;
}