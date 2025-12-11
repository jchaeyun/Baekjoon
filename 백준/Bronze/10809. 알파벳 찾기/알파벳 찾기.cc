#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<int> alphabet(26, -1);

    for (int i = 0; i < s.length(); i++)
    {
        int index = s[i] - 'a'; // 해당 알파벳을 숫자로 바꿈(a=0,b=1...)

        if (alphabet[index] == -1)
        {
            alphabet[index] = i; // s에 쓰인 순서를 해당 인덱스에 넣음
        }
    }
    for (int i = 0; i < 26; i++)
    {
        cout << alphabet[i] << ' ';
    }
    return 0;
}