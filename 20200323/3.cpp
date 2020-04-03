#include <iostream>

using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int t;
    int m, n;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> m >> n;
        int **a = new int *[m];
        for (size_t i = 0; i < m; i++)
        {
            a[i] = new int[n];
        }

        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int q = a[0][0];
        int p = a[0][0];
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                p = max(p, a[i][j]);
                q = min(q, a[i][j]);
            }
        }
        cout << q << " " << p << endl;
    }
    return 0;
}