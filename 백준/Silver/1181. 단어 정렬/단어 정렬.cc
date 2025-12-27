#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const string &a, const string &b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    // if (a != b)->이 조건을 넣으면 두 문자열이 같을때는 아무것도 반환 안해서 에러남
    return a < b; // 길이가 같으면 사전 순서(문자열이 서로 같아도 false가 반환됨->안전)
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> v;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        v.push_back(s);
    }

    sort(v.begin(), v.end(), compare);

    // unique와 erase를 사용해 중복 제거
    v.erase(unique(v.begin(), v.end()), v.end());

    for (const auto &s : v)
    {
        cout << s << '\n';
    }

    return 0;
}