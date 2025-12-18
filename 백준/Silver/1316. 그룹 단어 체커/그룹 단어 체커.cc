#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int count = 0; // 단어 개수 셈

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        // 맨처음 알파벳 먼저 체크
        bool check[26] = {false};  // 이 알파벳이 전에 나왔는지 확인 용->for문 안에서 써야 앞단어에서 썼던 기록이 초기화됨!!!
        check[s[0] - 'a'] = true;  // 문자를 숫자로 변환(인덱스로 씀)
        bool is_group_word = true; // 일단 그룹단어라고 생각

        for (int j = 1; j < s.length(); j++)
        {

            // 전의 알파벳과 다를때만 검사
            if (s[j] != s[j - 1])
            {
                if (check[s[j] - 'a'])
                {
                    is_group_word = false;
                    break; // 연속으로 나온게 아니고 전에 나왔던 알파벳이면 for문 탈출
                }
                check[s[j] - 'a'] = true; // 앞의 글자와 다르고 처음보는 글자면 체크
            }
        }
        if (is_group_word)
        {
            count++;
        }
    }
    cout << count;

    // 연속으로 나오거나 처음 나오는건 걍 냅두고 저번에 나왔는데 나오는거만 false
}