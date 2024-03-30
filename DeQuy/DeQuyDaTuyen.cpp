#include <iostream>


using namespace std;

void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] <<"\t";
    }
    cout << endl;
}

void printPermutations(int a[], int n, int i){
    int j, temp; // Thay đổi tên biến swap thành temp
    printArray(a,n);
    for(j = i+1; j < n ; j++ ){
        if(a[i] > a[j]){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        printPermutations(a,n,i+1);
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    printPermutations(a,n,0);
    return 0;
}
