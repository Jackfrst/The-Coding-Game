#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

vector<int> p(3001),rnk(3001);

int find(int a)
{
    return p[a]==a?a:p[a]=find(p[a]);
}

bool same(int a,int b)
{
    return find(a)==find(b);
}

void merge(int a,int b)
{
    {
        if(rnk[find(a)]>rnk[find(b)])
        {
            p[find(b)]=find(a);
        }
        else
        {
            p[find(a)]=find(b);
        }
        if(rnk[find(a)]==rnk[find(b)])
        {
            rnk[find(b)]++;
        }
    }
}
int main()
{
    int node,edges;
    cin>>node>>edges;

    for(int i=1; i<=node; i++)
    {
        p[i]=i;
        rnk[i] = p[i];
    }
    vector<vector<int>> a;

    for(int i=0; i<edges; i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        a.push_back({w,x,y});
    }

    sort(a.begin(),a.end(),[](const vector<int> &l,const vector<int> &r)
    {
        if(l[0]<r[0])
        {
            return true;
        }
        if(l[0]==r[0])
        {
            return l[1]+l[2]<r[1]+r[2];
        }
        return false;
    }
        );

    int sum=0;
    for(int i=0; i<edges; i++)
    {
        if(!same(a[i][1],a[i][2]))
        {
            merge(a[i][1],a[i][2]);
            sum+=a[i][0];
        }
    }
    cout<<sum<<endl;
}
