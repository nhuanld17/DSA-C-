#include <bits/stdc++.h>
using namespace std;

struct SinhVien
{
    string name;
    float mMath;
    float mPhysical;
    float mLanguage;
};

void Nhap1SinhVien(SinhVien &sinhvien){

	cout << "Name: ";
	cin.ignore();
	getline(cin, sinhvien.name);
	cout << "Toan: ";
	cin >> sinhvien.mMath;
	cout << "Li: ";
	cin >> sinhvien.mPhysical;
	cout << "Ngoai ngu: ";
	cin >> sinhvien.mLanguage;
}

void NhapDSSInhVien(SinhVien sinhvien[], int &n){
	cout << "Nhap so luong sinh vien: ";
	cin >> n;
	for(int i = 0; i < n; i++){
		Nhap1SinhVien(sinhvien[i]);
	}
}

void In1SinhVien(SinhVien sv){
	float dtb = 1.0*(sv.mMath + sv.mPhysical + sv.mLanguage )/3;
	
	cout << setw(20) << sv.name << setw(20) << sv.mMath  << setw(20) <<  sv.mPhysical << setw(20) << sv.mLanguage << setw(20) << dtb << endl;
}

void InDSSinhVien(SinhVien sv[], int n){
	cout << setw(20) << "Name"<<setw(20)<<"Toan" <<setw(20)<< "Ly" << setw(20)<< "Anh" <<setw(20)<< "DTB" << endl;
	for(int i = 0; i < n; i++){
		In1SinhVien(sv[i]);
	}
}

void Insert(SinhVien sv[], int &n){
	int p;
	cout << "Nhap vi tri can chen: " << endl;
	cin >> p;
	while(p > n-1){
		cout << "Vi tri khong hop le, nhap lai: " << endl;
		cin >> p;
	}
	SinhVien sinhvien;
	cout << "Name: " ;
	cin.ignore();
	getline(cin, sinhvien.name);
	cout << "Toan: ";
	cin >> sinhvien.mMath;
	cout << "Li: ";
	cin >> sinhvien.mPhysical;
	cout << "Anh van:" ;
	cin >> sinhvien.mLanguage;
	n++;
	for(int i = n -1; i >= p; i--){
		sv[i] = sv[i - 1];
	}
	sv[p] = sinhvien;
	InDSSinhVien(sv, n);
}

void Search(SinhVien sv[], int n){
	string nameFind;
	bool found = false;
	cout << "Nhap ten can tim:";
	cin.ignore();
	getline(cin, nameFind);
	for(int i = 0; i < n; i++){
		if(nameFind == sv[i].name){
			found = true;
			In1SinhVien(sv[i]);
		}
	}
	if(!found){
		cout << "Khong co ai ten la " << nameFind << endl;
	}
}

int main(){
	int n = 0;
	SinhVien sv[1000];
	NhapDSSInhVien(sv, n);
	InDSSinhVien(sv, n);
	Insert(sv, n);
	Search(sv, n);
	return 0;
}
