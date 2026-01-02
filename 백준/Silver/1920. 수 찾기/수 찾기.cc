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

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // binary_search 쓰기 전 무조건 sort해야함
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    bool exist = false;
    for (int j = 0; j < m; j++)
    {
        int num;
        cin >> num;
        // 있으면 true(1),없으면 false(0) 반환
        exist = binary_search(v.begin(), v.end(), num);
        cout << exist << '\n';
    }

    return 0;
}