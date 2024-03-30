#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int cot, dong;

    cout << "Nhap so hang:";
    cin >> dong;
    cout << "Nhap so cot:";
    cin >> cot;

    int **ptr = new int*[dong];


    for (int i = 0; i < dong; i++)
    {
        ptr[i] = new int[cot];
    }
    
    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            ptr[i][j] = rand()% 100 + 1;
        }
        
    }

    for (int i = 0; i < dong; i++)
    {
        for (int j = 0; j < cot; j++)
        {
            cout << ptr[i][j] <<" ";
        }
        cout << endl;
    }
        
    return 0;
}
