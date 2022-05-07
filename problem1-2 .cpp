#include <bits/stdc++.h>
using namespace std;
int prices[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

void cut_rod(int n, int c)
{
    int revenues[n+1];
    int solutions[n+1];

    revenues[0] = 0;
    for(int j = 1; j <= n; ++j)
    {
        int q = INT_MIN;
        for(int i = 1; i <= j; ++i)
        {
            int t = prices[i] + revenues[j - i];
            if(q < t)
            {
                q = t;
                solutions[j] = i;
            }
        }
        revenues[j] = q;
    }

    int n_t = n;
    int count = 0;
    while(n_t > 0)
    {
        if(n_t == solutions[n_t]) break;
        cout<<endl<<"The cut was given is "<<solutions[n_t]<<" inc";
        n_t -= solutions[n_t];
        ++count;
    }
    cout<<endl<<endl<<"The maximum revenue after cutting cost will be "<< revenues[n] - count * c<<endl;;
}

int main()
{
    int n = 4;
    int c = 2;

    cut_rod(n, c);

    return 0;
}
