#include <bits/stdc++.h>
using namespace std;

// Bài 1
int factorial1(int n){
	if( n <= 1){
		return 1;
	}
	return n*factorial1(n-1);
}

// Bài 2
int Fibo2(int n){
	if(n == 1 || n == 2){
		return 1;	
	}
	return Fibo2(n-1) +Fibo2(n-2);
}

// Bài 3
void move_disk3(int n, char s, char d, char i){
    if(n == 1)
        cout << "Move " << s << " to " << d << endl;
    else{
        move_disk3(n - 1, s, i, d);
        cout << "Move " << s << " to " << i << endl;
        move_disk3(n - 1, i, d, s);        
    }
}

// Bài 4
void Fibo4(int n){
	int fi1 = 1, fi2 = 1;
	int next = 0;
	cout << 1 <<" "  << 1;
//	for(int i = 3; i <= n; i++){
//		next = fi1 + fi2;
//		fi1 = fi2;
//		fi2 = next;
//		cout << " " << next;
//	}
	int i = 3;
	while(next < n){
		next = fi1 + fi2;
		fi1 = fi2;
		fi2 = next;
		cout << " " << next;	
	}
}

//Bài 5
long long factorial5(int n){
	long long res = 1;
	for(int i = 1; i <= n; i++){
		res *= i;
	}	
	return res;
}

int FactDynamic6(int n){
	int a[n+1];
	a[1] = 1;
	for(int i = 2; i <= n; i++){
		a[i] = a[i-1] * i;
	}
	return a[n];
}

int Fibo7(int n){
	int fi1 = 1, fi2 = 1;
	int next = 0;
	if( n == 1 || n == 2){
		cout << n;
		exit(0);
	}
	for(int i = 3; i <=n; i++){
		next = fi1 +fi2;
		fi1 = fi2;
		fi2 = next;	
	}
	return next;
}

int FiboDynamic8(int n){
	int a[n+1];
	a[1] = 1;
	a[2] = 1;
	for(int i = 3; i<=n; i++){
		a[i] = a[i-1] + a[i-2];
	}
	return a[n];
}
int main(){
	int n;
	cin >> n;
	cout << n<<"! bang de quy = "<<factorial1(n) << endl;
	cout << "So fibonaci thu "<<n<<" bang de quy: "<< Fibo2(n) << endl;
	cout << "Di chuyen "<<n<<" dia:"<<endl;
	move_disk3(n,'A','B','C');
	cout <<"Day so fibo tu 1 den "<<n<<":"<<endl;
	Fibo4(n);
	cout << endl;
	cout <<n<<"! bang vong lap: "<<factorial5(n) << endl;
	cout <<n<<"! bang quy hoach dong: "<< FactDynamic6(n) << endl;
	cout <<"So fibonaci thu "<<n<<" bang vong lap: "<< Fibo7(n) << endl;
	cout <<"So fibonaci thu "<<n<<" bang quy hoach dong: "<<FiboDynamic8(n)<<endl;
	return 0;
}
