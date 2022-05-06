#include <iostream>
using namespace std;

class Person{
public:
    string profession;
    int age;

    Person():profession("Unemployed"),age(16) {}
    void display()
    {
        cout<<"MY profession is : "<<profession<<endl;
        cout<< "My age is : "<<age<<endl;
        walk();
        talk();
    }
    void walk()
    {
        cout<<"I can walk."<<endl;
    }
    void talk ()
    {
        cout<<"I can  talk."<<endl;
    }

};

class MathTeacher:public Person{
public:
    void teachMath()
    {
        cout<<"I can teach Maths."<<endl;
    }
};

class Footballer : public Person{
public :
    void playFootball()
    {
        cout<<"I can play Football."<<endl;
    }
};

class Student:public Person{
public:
    void study()
    {
        cout<<"I read books ."<<endl;
    }
};

int main()
{
    MathTeacher teacher;
    teacher.profession="Theacher";
    teacher.age=23;
    teacher.display();
    teacher.teachMath();

    cout<<endl<<endl;

    Footballer footballer;
    footballer.profession="Footballer";
    footballer.age=19;
    footballer.display();
    footballer.playFootball();

    cout<<endl<<endl;

    Student student;
    student.profession="Student";
    student.age=18;
    student.display();
    student.study();

    return 0;
}
