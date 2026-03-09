#include <iostream>

using namespace std;
int n, m;
int result[10];
// depth:현재까지 몇개의 숫자를 선택했는지 나타냄
// start:다음 숫자를 선택할 때 어느 숫자부터 탐색을 시작할지 결정
void backtracking(int depth, int start)
{

    // 1.종료 조건(m개를 모두 고른 경우)
    if (depth == m)
    {
        // 결과 출력
        for (int j = 0; j < m; j++)
        {
            cout << result[j] << ' ';
        }
        cout << '\n';
        return; // 반드시 return하여 이전 단계로 돌아가야함
    }

    // 2.탐색 루프(start부터 n까지)
    for (int i = start; i <= n; i++)
    {
        result[depth] = i;              // 현재 깊이에 숫자 저장
        backtracking(depth + 1, i + 1); // 다음 숫자는 현재 i보다 큰 i+1부터 시작
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

        cin >> n >> m;

    backtracking(0, 1); // 시작할 땐 0개 선택, 숫자 1부터 탐색 시작

    return 0;
}