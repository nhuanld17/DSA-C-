#include <bits/stdc++.h>
using namespace std;

int main(){
	int N, K;
	cout << "Nhap so luong phan tu cua danh sach:";
	cin >> N;
	cout << "Nhap gia tri cua K:";
	cin >> K;
	
	// Khi báo mảng để lưu trữ giá trị lớn nhất
	int *largestK = new int[K];
	
	// Đọc và sắp xếp K phần tử đầu tiên
	cout <<"Nhap "<<K<<" phan tu dau tien:";
	for(int i = 0; i < K; ++i){
		cin >> largestK[i];
	}
	sort(largestK, largestK + K, greater<int>());
	
	// Đọc và sử lí các phần tử còn lại trong danh sách
	for (int i = K; i < N; ++i){
		int num;
		cin >> num;
		if(num > largestK[K -1]){
			int j = K - 2;
			while(j>=0 && largestK[j] < num){
				largestK[j+1] = largestK[j];
				j--;
			}
			largestK[j + 1] = num;
		}
	}
	
	cout <<"So thu "<< K <<" lon nhat la: "<< largestK[K -1] << endl;
	
	delete[] largestK;
	return 0;
}