#include <iostream>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int check[42] = {0}; // 42로 나누면 0~41까지의 나머지가 나옴
    //->나왔냐 안 나왔냐 표시하는거면 bool로 해도 되긴함
    int count = 0; // check 배열에 0이 아닌 숫자 들어있는 수 세는 용
    for (int i = 0; i < 10; i++)
    {
        int n;
        cin >> n;
        int temp = n % 42;
        check[temp]++;
    }
    for (int j = 0; j < 42; j++)
    {
        if (check[j] != 0)
        {
            count++;
        }
    }
    cout << count;

    return 0;
}