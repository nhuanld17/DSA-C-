#include <iostream>
using namespace std;

void input(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        *(a+i) = rand() % 100 + 1;
    }
}

void output(int *a, int n){
    for (int i = 0; i < n; i++)
    {
        cout << *(a+i) <<" ";
    }
    
}

void removeOdd(int p, int *a, int &n){
    for (int i = p; i < n - 1; i++)
    {
        *(a+i) = *(a+i+1);
    }
    n--;
}

void find(int *a, int &n){
    for (int i = 0; i < n; i++)
    {
        if (*(a+i) % 2 != 0)
        {
            removeOdd(i,a,n);
            i--; //
        }
        
    }
    
}


int main(int argc, char const *argv[])
{
    int n;
    cout << "Nhập kích thước của mảng:";
    cin >> n;
    int *a = new int[n];
    input(a,n);
    output(a,n); 
    cout << endl;
    find(a,n);
    output(a,n); 
    delete[] a; 
    return 0;
}

