#include <iostream>
#include <stack>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> stk;
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            stk.pop();
        }
        else
        {
            stk.push(t);
        }
    }

    while (!stk.empty())
    {
        sum += stk.top();
        stk.pop();
    }

    cout << sum;
}