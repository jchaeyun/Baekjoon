#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string num;
    cin >> num;

    //"0을 찾았니?" 라는 상태를 저장하는 변수(flag)
    bool hasZero = false;

    for (int i = 0; i < num.length(); i++)
    {
        if (num[i] == '0')
        {
            hasZero = true;
            break;
        }
    }

    if (hasZero == false)
    {

        cout << -1;
        return 0;
    }

    long long sum = 0;
    for (int j = 0; j < num.length(); j++)
    {
        // 문자->숫자 변환 잊지 말기!!
        sum = sum + (num[j] - '0');
    }

    if (sum % 3 == 0)
    {
        sort(num.begin(), num.end(), greater<char>());
        cout << num;
    }
    else
    {
        cout << -1;
    }

    return 0;
}