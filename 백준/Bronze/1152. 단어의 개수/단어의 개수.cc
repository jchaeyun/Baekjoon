#include <iostream> //cin,cout등 쓸 수 있음
#include <string>   //문자열 쓸 수 있어요

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;

    getline(cin, s);    // 엔터 전까지 입력 받음,엔터(\n)는 버퍼에 저장 안하고 버림
    int word_count = 1; // 단어 개수 기본적으로 1개(공백 0이면 단어 1개)

    if (s.empty()) // 아무것도 입력 안했을 때
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ') // 공백 1개 당 단어 개수 1개 추가
        {
            word_count++;
        }
    }
    if (s[0] == ' ')
    { // 맨 앞이 공백이면 1개 뺌
        word_count--;
    }

    if (s[s.length() - 1] == ' ')
    { // 맨 뒤가 공백이면 1개 뺌
        word_count--;
    }

    cout << word_count;

    return 0;
}