#include <iostream>
#include <vector>
using namespace std;
class Result
{
public:
    void show_result(int a, int b, int c)
    {
        cout << "Average: " << (a + b + c) / 3 << endl;
    }     void show_result(int a, int b, double c)
    {
        cout << "Product: " << a * b * c << endl;
    }     void show_result(int size, int arr[])
    {
        int temp = 0;
        for (int i = 0; i < size; i++)
        {
            temp += arr[i];
        }
        cout << "Summation: " << temp << endl;
    }
};
int main()
{
    Result result;
    result.show_result(10, 15, 30);
    result.show_result(10, 20, 30.5);
    int arr[] = {5, 5, 6, 9, 8, 7, 9};
    result.show_result(sizeof(arr) / sizeof(arr[0]), arr);
}
