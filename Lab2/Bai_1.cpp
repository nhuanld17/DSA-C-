#include <bits/stdc++.h>
#include <ostream>
using namespace std;

struct BirthDate{
	int day, month, year;
	void input(){
		cout << "Nhap ngay sinh: " << endl;
		cin >> day;
		cout << "Nhap thang sinh: " << endl;
		cin >> month;
		cout << "Nhap nam sinh: "<< endl;
		cin >> year;
	}
};

struct Student{
	string name;
	BirthDate birtDate;
	double math;
	double physic;
	double language;
	
	void input(){
		cout << "Name: " << endl;
		cin >> name;
		birtDate.input();
		cout << "Math: " << endl;
		cin >> math;
		cout << "Physic: " << endl;
		cin >> physic;
		cout << "Language: " << endl;
		cin >> language;
	}
	
	void display(){
		cout << "Name: " << name <<"| birthdate: " << birtDate.day << "/" << birtDate.month << "/" <<birtDate.year << "| math: " << math << "| physic: " << physic <<"| language: " << language << endl;
	}
};

struct ListNode{
	Student student;
	ListNode* next;
	ListNode(Student student):student(student), next(nullptr){};
};

void NhapDanhSach(ListNode* &head, ListNode* &tail){
	int n;
	cout << "Nhap so luong sinh vien: " << endl;
	cin >> n;
	for(int i = 1; i <= n; i++){
		Student student;
		cout << "Nhap sinh vien thu " << i << endl;
		student.input();
		
		ListNode* newNode = new ListNode(student);
		
		if(head == nullptr){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
	}
}

void InDanhSach(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach sinh vien trong" << endl;
		return;
	}
	ListNode* current = head;
	while(current != nullptr){
		current->student.display();
		current = current->next;
		cout << endl;
	}
}

void CountStudent(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach sinh vien trong" << endl;
		return;
	}
	int year;
	cout << "Nhap nam sinh : " << endl;
	cin >> year;
	
	while(year <= 0){
		cout << "Nhap nam sinh sai, nhap lai: " << endl;
		cin >> year;
	}
	
	int count = 0;
	ListNode* current = head;
	while(current != nullptr){
		if(current->student.birtDate.year == year){
			count ++;
		}
		current = current->next;
	}
	cout << "Co " << count <<" hoc sinh sinh vao nam " << year << endl;
}

void CheckName(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach sinh vien trong" << endl;
		return;
	}
	string name;
	cout << "Nhap ten hoc sinh can kiem tra: " << endl;
	cin >> name;
	
	ListNode* current = head;
	while(current != nullptr){
		if(current->student.name == name){
			cout << "Co hoc sinh ten " << name <<" trong danh sach" << endl;
			return;
		}
		current = current->next;
	}
	cout << "Khong co hoc sinh nao co ten la " << name << " trong danh sach" << endl;
}

int count(ListNode* head){
	ListNode* current = head;
	int count = 0;
	while(current != nullptr){
		count++;
		current = current->next;
	}
	return count;
}

void DeleteStudent(ListNode* &head, ListNode* &tail){
	if(head == nullptr){
		cout << "Danh sach sinh vien trong" << endl;
		return;
	}
	string name;
	cout << "Nhap ten sinh vien can xoa: " << endl;
	cin >> name;
	int Count = count(head);
	int index = 0;
	ListNode* current = head;
	while(current != nullptr){							// Xóa sinh viên:
		index ++;										// TH1: Xóa sinh viên ở node đầu: nếu ds gồm 1 sv hoặc nhiều sv
		if(current->student.name == name){				// TH2: Xóa sinh viên ở node cuối: Nếu ds gồm 1 sv hoặc nhiều sv                             
			// Xử lí trường hợp xóa Node head           // TH3: Xóa sinh viên ở node nằm giữa: 
			if(index == 1){
				// Nếu danh sách chỉ có 1 sv
				if(Count == 1){
					ListNode* temp = current;
					
					head = nullptr;
					tail = nullptr;
					delete temp;
				}else{ // Nếu danh sách có nhiều hơn 1 sinh viên
					head = current->next;
					ListNode* temp = current;
					temp = nullptr;
					delete temp;
				}
			}
			// Xử lí trường hợp xóa Node tail
			else if(index == Count){
				// Nếu chỉ có 1 sinh viên trong danh sách
				if( Count == 1){
					current = nullptr;
					head = nullptr;
					tail = nullptr;
					delete current;
				}else{ // Nếu danh sách có nhiều hơn 1 sinh viên
					// Duyệt lại danh sách để lấy Node kế cuối
					ListNode* NextLastNode = head;
					while(NextLastNode->next->next != nullptr){
						NextLastNode = NextLastNode->next;
					}
					// Bây giờ current là Node cuối và cần xóa
					ListNode* temp = current;
					temp = nullptr;
					delete temp;
					
					// Cập nhật con trỏ next của NextLastNode thành Node cuối
					NextLastNode->next = nullptr;
					
					// Cập nhật con trỏ tail
					tail = NextLastNode;
				}
			}else{// Nếu sinh viên cần xóa nằm giữa (không nằm ở head và tail)
				// Lấy Node đứng trước vị trí cần xóa
				ListNode* Before = head;
				for(int i = 1; i < index - 1; i++){
					Before = Before->next;
				}
				// Cập nhật con trỏ next cho Node Before
				Before->next = current->next;
				ListNode* temp = current;
				temp = nullptr;
				delete temp;
			}
		}
		current = current->next;
	}
}

double Avg(ListNode* head){
	return (head->student.math + head->student.physic + head->student.language)/3.0;
}

void BiggestAverage(ListNode* head){
	if(head == nullptr){
		cout << "Danh sach sinh vien trong" << endl;
		return;
	}
	double MaxAvg = 0;
	ListNode* current = head;
	while(current != nullptr){
		int Aver = Avg(current);
		if(Aver > MaxAvg){
			MaxAvg = Aver;
		}
		current = current->next;
	}
	ListNode* current1 = head;
	while(current1 != nullptr){
		if(Avg(current1) == MaxAvg){
			current1->student.display();
		}
		current1 = current1->next;
	}
	
}

void LessThan5(ListNode* head){
	bool found = false;
	ListNode* current = head;
	while(current != nullptr){
		if(current->student.math < 5){
			current->student.display();
			found = true;
		}
		current = current->next;
	}
	if(!found){
		cout << "Khong co hoc sinh nao co diem toan < 5" << endl;
	}
}

void XuatFile(ListNode* head){
    ofstream file("StudentList.txt");
    
    if(!file.is_open()){
        cerr << "Khong the mo tep" << endl;
        return;
    }
    
    ListNode* current = head;
    while(current != nullptr){
        file << "Name: " << current->student.name << endl;
        file << "Birthdate: " << current->student.birtDate.day << "/" << current->student.birtDate.month << "/" << current->student.birtDate.year << endl;
        file << "Math score: " << current->student.math << endl;
        file << "Physic score: " << current->student.physic << endl;
        file << "Language score: " << current->student.language << endl;
        file << endl;
        current = current->next;
    }
    file.close();
}


int main();

int main() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    while(true){
        cout << "1. Nhap thong tin sinh vien " << endl;
        cout << "2. In danh sach sinh vien " << endl;
        cout << "3. Dem so luong sinh vien theo nam sinh " << endl;
        cout << "4. Kiem tra hoc sinh x co ton tai trong list hay khong " << endl;
        cout << "5. Xoa sinh vien theo ten" << endl;
        cout << "6. Tim sinh vien co DTB lon nhat " << endl;
        cout << "7. List sinh vien co diem toan < 5" << endl;
        cout << "8. Xuat file .txt" << endl;
        cout << "0. Thoat" << endl;
        cout <<"Nhap chuc nang: " << endl;
        int  choice;
        cin >> choice;

        switch (choice){
            case 1: NhapDanhSach(head,tail); break;
            case 2: InDanhSach(head); break;
            case 3: CountStudent(head); break;
            case 4: CheckName(head); break;
            case 5: DeleteStudent(head,tail); break;
            case 6: BiggestAverage(head); break;
            case 7: LessThan5(head); break;
            case 8: XuatFile(head); break;
            case 0: exit(0);
            default:
                cout << "Nhap sai, nhap lai: " << endl;
                break;
        }
    }
    return 0;
}
