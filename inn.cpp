#include <iostream>

using namespace std;

int main()
{

    int N, Counter=0, Increment=0;

    cout << "How many elements would you want to work with in array : ";
    cin>> N;

    int Array[N], Frequency[N];

    cout << "\n\nNow enter your elements in Array:\n";
    for(int i=0; i<N; i++)
    {
        cin>> Array[i];
        Frequency[i] = -1;
    }

    cout << "\n\nYou Entered ";
    for(int i=0; i<N; i++)
    {
        cout << Array[i] <<" ";
    }

    for(int i=0; i<N; i++)
    {
        Increment = 1;
        for(int j=i+1; j<N; j++)
        {
            if(Array[i] == Array[j])
            {
                Increment++;
                Frequency[j] = 0;
            }
        }

        if(Frequency[i] != 0)
        {
            Frequency[i] = Increment;
        }
    }

    cout<< "\n\n The Unique element(s) are/is : ";
    for(int i=0; i<N; i++)
    {
        if(Frequency[i] == 1)
        {
            cout << Array[i] << " ";
            Counter++;
        }
    }

    cout<< "\n\nThe number of unique element is: "  << Counter << "\n";

    cout << endl << endl;
}
