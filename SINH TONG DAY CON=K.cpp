#include <bits/stdc++.h>
using namespace std;
int n, k, a[100];
int u[100];
bool isFinal;
void ktao()
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = 0;
    }
}
void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        i--;
    }
    if (i == 0)
    {
        isFinal = true;
    }
    else
    {
        a[i] = 1;
    }
}
bool check()
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i] * u[i];
    }
    return sum == k;
}
int main()
{
    int cnt = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> u[i];
    }
    isFinal = false;
    while(!isFinal)
    {
        if (check())
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] == 1)
                {
                    cout << u[i] << " ";
                }
            }
            cnt++;
            cout << endl;
        }
        sinh();
    }
    cout << cnt;
}