#include <iostream>
#include <string>

using namespace std;

int alphabet[26][200001];
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    int len = s.length();

    // 미리 누적 합 구하기
    for (int i = 0; i < len; i++)
    {
        int current_char = s[i] - 'a'; // a면 인덱스 0
        for (int j = 0; j < 26; j++)
        {
            // 일단 이전 줄 복사
            alphabet[j][i + 1] = alphabet[j][i];
        }

        // 해당 알파벳의 숫자만 1 증가
        alphabet[current_char][i + 1]++;
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;
        int l, r;
        cin >> l >> r;
        int curr_char = c - 'a';

        cout << alphabet[curr_char][r + 1] - alphabet[curr_char][l] << '\n';
    }

    return 0;
}