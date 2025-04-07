#include <iostream>
#include <cstring>
using namespace std;
struct SinhVien {
    char hoTen[50];
    char diaChi[70];
    char lop[10];
    int khoa;
};

// Cấu trúc Node cho danh sách liên kết
struct Node {
    SinhVien sv; 
    Node* next;  
};

// Lớp quản lý danh sách sinh viên
class ListSV {
private:
    Node* head; 
public:
    // Constructor: Khởi tạo danh sách rỗng
    ListSV() : head(nullptr) {}

    // Destructor: Giải phóng bộ nhớ khi hủy danh sách
    ~ListSV() { clear(); }

    // Thêm sinh viên vào cuối danh sách
    void add(const SinhVien& sv) {
        Node* newNode = new Node{sv, nullptr}; 
        if (head == nullptr) {
            head = newNode; 
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  
            }
            temp->next = newNode;  
        }
    }

    // Xóa sinh viên theo tên
    void removeByName(const char* name) {
        if (head == nullptr) 
		return;  
        if (strcmp(head->sv.hoTen, name) == 0) {  // Nếu sinh viên đầu tiên có tên cần xóa
            Node* temp = head;
            head = head->next;  
            delete temp;       
            return;
        }
        Node* current = head;
        while (current->next != nullptr && strcmp(current->next->sv.hoTen, name) != 0) {
            current = current->next;  // Duyệt đến sinh viên cần xóa
        }
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;  // Bỏ qua phần tử cần xóa
            delete temp;  // Giải phóng bộ nhớ
        }
    }

    // Xóa sinh viên theo địa chỉ
    void removeByAddress(const char* address) {
        if (head == nullptr)
		return;  
        if (strcmp(head->sv.diaChi, address) == 0) {  // Nếu sinh viên đầu tiên có địa chỉ cần xóa
            Node* temp = head;
            head = head->next;  
            delete temp;        
            return;
        }
        Node* current = head;
        while (current->next != nullptr && strcmp(current->next->sv.diaChi, address) != 0) {
            current = current->next;  
        }
        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = current->next->next;  // Bỏ qua phần tử cần xóa
            delete temp;  // Giải phóng bộ nhớ
        }
    }

    // Xuất danh sách sinh viên
    void print() const {
        if (head == nullptr) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            xuatSinhVien(temp->sv);  
            temp = temp->next;       
        }
    }

    // Hàm hủy danh sách
    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;  // Giải phóng bộ nhớ
        }
    }

    // Hàm nhập thông tin một sinh viên
    void nhapSinhVien(SinhVien& sv) {
        cout << "Nhap ho ten: ";
        cin.getline(sv.hoTen, 50);   
        cout << "Nhap dia chi: ";
        cin.getline(sv.diaChi, 70);  
        cout << "Nhap lop: ";
        cin.getline(sv.lop, 10);    
        cout << "Nhap khoa: ";
        cin >> sv.khoa;              
        cin.ignore();                
    }

    // Hàm xuất thông tin một sinh viên
    void xuatSinhVien(const SinhVien& sv) const {
        cout << "Ho ten: " << sv.hoTen << endl;
        cout << "Dia chi: " << sv.diaChi << endl;
        cout << "Lop: " << sv.lop << endl;
        cout << "Khoa: " << sv.khoa << endl;
    }
};

int main() {
    ListSV list;  
    SinhVien sv;  
    cout << "Nhap 10 sinh vien:" << endl;
    for (int i = 0; i < 10; i++) {
        list.nhapSinhVien(sv);  
        list.add(sv);           
    }

    // Xuất danh sách sinh viên
    cout << "\nDanh sach sinh vien:" << endl;
    list.print();

    // Xóa sinh viên có tên "Nguyen Van Teo"
    cout << "\nXoa sinh vien co ten 'Nguyen Van Teo'..." << endl;
    list.removeByName("Nguyen Van Teo");

    // Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    cout << "\nXoa sinh vien co dia chi 'Nguyen Van Cu'..." << endl;
    list.removeByAddress("Nguyen Van Cu");

    // Thêm sinh viên mới vào danh sách
    SinhVien newSv = {"Tran Thi Mo", "25 Hong Bang", "TT0901", 2009};
    list.add(newSv);

    cout << "\nDanh sach sau khi thay doi:" << endl;
    list.print();

    return 0;
}