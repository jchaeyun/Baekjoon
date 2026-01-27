#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime[250000];
int cnt_prime[250000];

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    fill(is_prime, is_prime + 250000, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i < 250000; i++)
    {
        if (is_prime[i])
        {
            for (int j = i; j * i < 250000; j++)
            {
                is_prime[j * i] = false;
            }
        }
    }

    cnt_prime[0] = 0;
    cnt_prime[1] = 0;

    for (int i = 2; i < 250000; i++)
    {
        cnt_prime[i] = cnt_prime[i - 1];
        if (is_prime[i])
        {
            cnt_prime[i]++;
        }
    }

    while (true)
    {

        int n;
        cin >> n;

        if (n == 0)
            break;

        cout << cnt_prime[2 * n] - cnt_prime[n] << '\n';
    }

    return 0;
}