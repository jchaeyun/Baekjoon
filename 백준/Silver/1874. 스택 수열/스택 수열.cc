#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> stk;
    vector<char> v;
    int j = 1;
    bool is_possible = true;

    for (int i = 0; i < n; i++)
    {

        int target;
        cin >> target;

        while (true)
        {

            if (!stk.empty() && stk.top() == target)
            {
                stk.pop();
                v.push_back('-');
                break;
            }
            else if (j <= target)
            {
                stk.push(j++);
                v.push_back('+');
            }
            else
            {
                is_possible = false;
                cout << "NO" << '\n';
                break;
            }
        }

        if (!is_possible)
        {
            break;
        }
    }

    if (is_possible)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << '\n';
        }
    }

    return 0;
}
