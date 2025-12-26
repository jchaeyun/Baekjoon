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

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    for (int j = 0; j < v.size(); j++)
    {
        cout << v[j].first << ' ' << v[j].second << '\n';
    }

    return 0;
}