#include <iostream>
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

    sort(v.begin(), v.end());

    int m;
    cin >> m;
    for (int j = 0; j < m; j++)
    {
        int target;
        cin >> target;
        int cnt = upper_bound(v.begin(), v.end(), target) - lower_bound(v.begin(), v.end(), target);
        cout << cnt << ' ';
    }

    return 0;
}
