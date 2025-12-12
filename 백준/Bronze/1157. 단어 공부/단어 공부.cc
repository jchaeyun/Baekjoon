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

    vector<int> alphabet(26, 0);

    for (int i = 0; i < s.length(); i++)
    {
        int index;
        if (s[i] >= 'a')
        { // 소문자일 경우 대문자 변환후 숫자로 변환
            index = s[i] - 32 - 'A';
        }
        else // 대문자일 경우 숫자로 변환
        {
            index = s[i] - 'A'; // 문자->숫자 변환해서 인덱스에 저장
        }

        alphabet[index] += 1; // 해당 문자 사용 횟수 1 증가
    }

    int max_freq = -1; // 제일 많이 나온 횟수
    char result = '?'; // 출력할 문자

    // 2.최댓값 찾기
    for (int j = 0; j < 26; j++)
    {
        if (alphabet[j] > max_freq)
        {
            max_freq = alphabet[j]; // 최댓값 갱신
            result = j + 'A';       // 해당 알파벳 저장(인덱스->문자)
        }
        else if (alphabet[j] == max_freq)
        {
            result = '?'; // 최대 빈도수가 같은게 발견되면 result='?'
        }
    }

    cout << result;

    return 0;
}
