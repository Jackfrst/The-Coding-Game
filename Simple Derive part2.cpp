#include<iostream>
using namespace std;

class Base{
public:
    virtual void show ()
    {
        cout<<"Base class"<<endl;
    }
};

class Derived:public Base{
private:
    void show ()
    {
        cout<<"Derived Class"<<endl;
    }
};

int main()
{
    Base*b;
    Derived d;
    b = &d;
    b->show();
}
