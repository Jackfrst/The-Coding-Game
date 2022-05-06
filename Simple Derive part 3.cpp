#include<iostream>
using namespace std;

class Base
{
public:
    virtual void show()=0;
};
class Derived : public Base
{
public:
    void show ()
    {
        cout << "Inplement of Virtual Function In Derived class"<<endl;
    }
};
main()
{
    //Base obj;
    Base *b;
    Derived d;
    b = &d;
    b -> show();
}
