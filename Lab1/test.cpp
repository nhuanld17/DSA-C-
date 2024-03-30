#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
using namespace std;



int main(){
	int n = 0;
	double p = 0;
	while( n < 100){
		p = (0.5+0.25*p);
		n++;
	}
	cout << p;
	return 0;
}