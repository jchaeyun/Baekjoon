#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 처음 나온거면 ok
// 저번에 나왔던거면 직전에 나왔는지 확인후, 있으면 ok
// 저번에 나온건데 직전에 안나왔으면 그룹단어 아님
// 단어 다 순회했는데 is_group=true면 count++

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int count = 0; // 그룹 단어 개수
    for (int i = 0; i < n; i++)

    {
        bool is_group = true; // 그룹 단어인지 여부
        bool alphabet[26] = {
            false,
        }; // 알파벳 방명록
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            int c = s[j] - 'a';
            // 처음 나온 알파벳일때 나온거 방명록 체크
            if (!alphabet[c])
            {
                alphabet[c] = true;
            } // 저번에 나온 알파벳일 때
            else
            {
                // 연속으로 나온게 아닐때(j=0일땐 무조건 처음나온 알파벳이라 j-1ㄱㅊ)
                if (s[j] != s[j - 1])
                {
                    is_group = false;
                    break;
                }
            }
        }
        if (is_group)
            count++;
    }

    cout << count;

    return 0;
}