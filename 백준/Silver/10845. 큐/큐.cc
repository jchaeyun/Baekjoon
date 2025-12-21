#include <iostream>
#include <queue>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    queue<int> q;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "push")
        { // 문자열일땐 "" 문자일땐 ''
            int num;
            cin >> num;
            q.push(num);
        }
        else if (s == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
                q.pop();
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (s == "size")
        {
            cout << q.size() << '\n';
        }
        else if (s == "empty")
        {
            if (q.empty())
            {
                cout << 1 << '\n';
            }
            else
            {
                cout << 0 << '\n';
            }
        }
        else if (s == "front")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
        else if (s == "back")
        {
            if (!q.empty())
            {
                cout << q.back() << '\n';
            }
            else
            {
                cout << -1 << '\n';
            }
        }
    }

    return 0;
}