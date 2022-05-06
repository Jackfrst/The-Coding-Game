#include <iostream>
using namespace std;

calss A
{
public:
    int x=1;
protected:
    int y=2;
private:
    int z=3;
}
class B: public A
{
protected:
    int x;
    int y;
private:
    int z:
};
class C: protected A
{
private:
    int z;

};

class D:private class A
{
private:
    int z;
};
main()
{
   A obj;
    B obj2;
    C obj3;
    D obj4;
   cout<<obj.x<<obj.y;
   cout<<obj2.x<<obj2.y;

}
