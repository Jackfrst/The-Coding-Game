#include <iostream>

using namespace std;

int main()
{

    int n;
    cin>>n;
    while(n-->0)
    {
        int t;
        cin>>t;
        while(t -->0)
        {
            int x;
            cin >> x;
            if(x==1)
            {
                cout<<"Rolien"<<endl;
            }
            if(x==2)
            {
                cout<<"Naej"<<endl;
            }
            if(x==3)
            {
                cout<<"Elehcim"<<endl;
            }
            if(x==4)
            {
                cout<<"Odranoel"<<endl;
            }
        }
    }

    return 0;
}
