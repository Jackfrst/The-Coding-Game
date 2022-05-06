#include <iostream>
#include <vector>
using namespace std;
class Result
{
public:
    void show_result(int a, int b, int c){
        cout << "Average: " << (a + b + c) / 3 << endl;
    }

    void show_result(int a, int b, double c){
        cout << "Product: " << a * b * c << endl;
    }

    void show_result( int arr[]){
        int temp = 0 ;
         int size = sizeof(arr)/sizeof(arr[0]);
        for (int i = 0; i < size ; i++)
        {
            temp += arr[i];
        }
        cout << "Summation: " << temp << endl;
    }
};
int main()
{
    Result result;
    result.show_result(20, 25, 30);
    result.show_result(20, 25, 30.7);
    int arr[] = {1, 2, 3, 4, 8};
    result.show_result( arr);
}
