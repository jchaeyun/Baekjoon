#include <iostream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie();

    int n; // 테스트 케이스 개수
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        string func; // 함수
        cin >> func;

        int num; // 배열에 든 숫자 개수
        cin >> num;

        string intArr; // 함수를 적용할 정수 배열
        cin >> intArr;

        int temp = 0;     // 문자열에서 숫자로 바꾸고 임시로 조립해두는 변수
        deque<int> dqArr; // 정수 배열을 덱에 넣어서 뒤집기,버리기 함수 실행

        bool is_number = false; // 숫자를 만들고 있었는지 체크
        // 문자 배열을 숫자 배열로 파싱해서 덱에 넣음
        for (int k = 0; k < intArr.length(); k++)
        {

            // 1.숫자인 경우: 자릿수 올리고 1의 자리 더하기
            if (isdigit(intArr[k]))
            {
                temp = temp * 10 + (intArr[k] - '0');
                is_number = true;
            } // 2.숫자가 아닌 경우(콤마,[,]일때)
            else
            {
                if (is_number)
                { // 만들어둔 숫자가 있는 경우
                    dqArr.push_back(temp);
                    temp = 0; // 변수 초기화 (다음 숫자를 위해)
                    is_number = false;
                }
            }
        }

        bool is_reversed = false;
        bool is_error = false;

        // 함수 실행
        for (int u = 0; u < func.length(); u++)
        {

            // 뒤집기 함수
            if (func[u] == 'R')
            {
                is_reversed = !is_reversed;
            }
            // 첫번째 숫자 버리기 함수
            else
            {
                if (dqArr.empty())
                {
                    is_error = true;
                    break; // 배열이 비어있는데 D하면 함수 실행 멈춤(반복문 나감)
                }

                // 배열이 뒤집혀있는 상태라면 맨 뒤 숫자를 뺌
                if (is_reversed)
                {
                    dqArr.pop_back();
                }
                // 배열이 안 뒤집힌 상태라면 맨 앞 숫자를 뺌
                else
                {
                    dqArr.pop_front();
                }
            }
        }

        int dqArrSize = dqArr.size();
        // 결과 프린트
        if (is_error)
        {
            cout << "error" << '\n';
        }
        else if (dqArr.empty())
        {
            cout << "[]" << '\n'; // 덱이 비어있으면 [] 출력
        }
        else if (is_reversed)
        {
            cout << '[';
            for (int i = 0; i < dqArrSize - 1; i++)
            {
                cout << dqArr.back() << ',';
                dqArr.pop_back();
            }

            cout << dqArr.back() << ']' << '\n';
        }
        else
        {
            cout << '[';
            for (int p = 0; p < dqArrSize - 1; p++)
            {
                cout << dqArr.front() << ',';
                dqArr.pop_front();
            }
            cout << dqArr.front() << ']' << '\n';
        }
    }

    return 0;
}