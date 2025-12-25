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
            // 스택이 비어있거나, 스택 맨 위의 값이 타겟보다 작은 경우
            // j는 앞으로 스택에 넣을 값
            if (j <= target)
            {
                stk.push(j++);
                v.push_back('+');
            }
            else if (target == stk.top())
            {
                stk.pop();
                v.push_back('-');
                break;
            }
            else
            {

                is_possible = false;
                break;
                // 이미 불가능한거 아는데 break;를 하면 바깥 for문이 계속 돌아서 시간낭비
                // 바깥쪽 반복문도 멈춰야함
            }
        }
        // 불가능한 경우면 바깥쪽 반복문도 탈출
        if (is_possible == false)
        {
            break;
        }
    }
    if (is_possible)
    {
        for (int k = 0; k < v.size(); k++)
        {
            cout << v[k] << '\n';
        }
    }
    else
    {
        cout << "NO"; // 출력을 is_possible=false할때 같이 하지말고 마지막에 미뤄야함. 출력이 자
    }

    return 0;
}