// bfs

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

char grid[105][105];
bool visited[105][105];

int n;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

int count_o, count_x;

// 적록색약x 주변에 글자 같은 거면 bfs
void bfs_x(int start_r, int start_c)
{
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n)
            {
                continue;
            }

            if ((grid[next_r][next_c] == grid[cur_r][cur_c]) && !visited[next_r][next_c])
            {
                visited[next_r][next_c] = true;
                q.push({next_r, next_c});
            }
        }
    }
    count_x++;
}

// 적록색약o 주변에 글자 같은 거면 bfs
void bfs_o(int start_r, int start_c)
{
    queue<pair<int, int>> q;
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    while (!q.empty())
    {
        int cur_r = q.front().first;
        int cur_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];

            if (next_r < 0 || next_r >= n || next_c < 0 || next_c >= n)
            {
                continue;
            }

            if (grid[cur_r][cur_c] == 'B' && (grid[next_r][next_c] == grid[cur_r][cur_c]) && !visited[next_r][next_c])
            {
                visited[next_r][next_c] = true;
                q.push({next_r, next_c});
            }
            if (grid[cur_r][cur_c] != 'B' && grid[next_r][next_c] != 'B' && !visited[next_r][next_c])
            {
                visited[next_r][next_c] = true;
                q.push({next_r, next_c});
            }
        }
    }
    count_o++;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            grid[i][j] = s[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs_x(i, j);
            }
        }
    }

    fill(&visited[0][0], &visited[0][0] + 105 * 105, false);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                bfs_o(i, j);
            }
        }
    }

    cout << count_x << " " << count_o;

    return 0;
}
