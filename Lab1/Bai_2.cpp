#include <bits/stdc++.h>
using namespace std;

struct SinhVien
{
    char name[30];
    char Class[10];
    float mMath;
    float mPhysical;
    float mLanguage;
};

void Nhap1SinhVien(SinhVien &sinhvien){
    cout << "Ho va ten: ";
    cin.getline(sinhvien.name,30);
    cout << "Lop:";
    cin.getline(sinhvien.Class,10);
    cout << "Diem toan:";
    cin >> sinhvien.mMath;
    cout << "Diem li: ";
    cin >> sinhvien.mPhysical;
    cout << "Diem ngoai ngu: ";
    cin >> sinhvien.mLanguage;
    cin.ignore(); 
}


void NhapDSSinhVien(SinhVien sinhvien[], int &dem, int &n){
    int num;
    cout << "Nhap so luong sinh vien:";
    cin >> num;
    if(dem + num > n + 1){
    	n = dem + num;
	}
    cin.ignore(); 
    for (int i = dem; i <dem + num; i++)
    {
        Nhap1SinhVien(sinhvien[i]);
    }
    dem += num;
}


void In1SinhVien(SinhVien sv){
    cout << "Ten: "<< sv.name <<", Lop: "<< sv.Class <<", Toan: "<<sv.mMath <<", Li: "<<sv.mPhysical <<", Ngoai ngu: " << sv.mLanguage << endl;
}

void InDSSinhVien(SinhVien sv[], int dem){
    for (int  i = 0; i < dem; i++)
    {
        In1SinhVien(sv[i]);
    }
    
}

void SearchAndEditClass(SinhVien sv[], int dem){
	char nameFind[30];
	cin.ignore();
	cout << "Nhap ten sinh vien can tim kiem :";
    cin.getline(nameFind,30);
    bool found = false;
    for(int i = 0; i < dem; i++ ){
    	if(strcmp(sv[i].name,nameFind) == 0){
    		found = true;
    		In1SinhVien(sv[i]);
    		char ClassEdit[10];
    		cout << "Nhap lop moi cho sinh vien "<<sv[i].name;
    		cin.getline(ClassEdit,10);
			strcpy(sv[i].Class, ClassEdit);
		}
	}
	if(!found){
		cout << "Khong tim thay sinh vien" << endl;
	}
}

void SearchByName(SinhVien sv[], int dem){
	char nameFind[30];
    cin.ignore();
	cout << "Nhap ten sinh vien can tim kiem :";
    cin.getline(nameFind,30);
    bool found = false;
    for(int i = 0; i < dem; i++ ){
    	if(strcmp(sv[i].name,nameFind) == 0){
    		found = true;
    		In1SinhVien(sv[i]);
		}
	}
	if(!found){
		cout << "Khong co sinh vien ten "<<nameFind;
	}
}

int main(int argc, char const *argv[])
{
    int dem = 0;
    int n = 1;
    SinhVien *sinhvien = new SinhVien[n];
	while(true){
		cout << "1. Nhap danh sach sinh vien"<<endl;
		cout << "2. Tim sinh vien theo ten"<<endl;
		cout << "3. Sua lop cho sinh vien" << endl;
		cout << "4. Thoat" << endl;
		cout << "Chon chuc nang:";
		int choice;
		cin >> choice;
	    switch (choice){
    		case 1: NhapDSSinhVien(sinhvien, dem, n); 
                    InDSSinhVien(sinhvien, dem);
			        break;
            case 2: SearchByName(sinhvien,dem); 
                    break;
            case 3: SearchAndEditClass(sinhvien, dem);
                    InDSSinhVien(sinhvien, dem);
                    break;
            case 4:
                    delete[] sinhvien;
                    exit(0);
    		default:
            cout <<"Nhap sai, nhap lai";
        	break;
    	}
	}
    return 0;
}
