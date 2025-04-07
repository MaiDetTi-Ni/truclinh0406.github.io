#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

// Danh sách liên kết số nguyên
class ListInt {
private:
    Node* head;
public:
    ListInt() : head(nullptr) {}

    // Hàm thêm phần tử vào cuối danh sách
    void add(int value) {
        Node* newNode = new Node{value, nullptr};
        if (head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Hàm xóa một phần tử có giá trị k
    void remove(int k) {
        if (head) return;

        // Xóa nếu phần tử đầu tiên là k
        while (head && head->data == k) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }

        // Xóa phần tử ở giữa hoặc cuối
        Node* current = head;
        while (current && current->next) {
            if (current->next->data == k) {
                Node* temp = current->next;
                current->next = temp->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }

    void merge(ListInt& other) {
        if (!head) {
            head = other.head;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = other.head;
        }
        other.head = nullptr;
    }

    // Xuất danh sách
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void testListInt() {
    ListInt list1;
    cout << "Nhap 10 so nguyen:\n";
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        list1.add(x);
    }

    cout << "Danh sach vua nhap: ";
    list1.print();

    cout << "Nhap so nguyen k de xoa: ";
    int k;
    cin >> k;
    list1.remove(k);
    cout << "Danh sach sau khi xoa " << k << ": ";
    list1.print();

    // Nhập danh sách thứ hai
    ListInt list2;
    cout << "Nhap 5 so nguyen cho danh sach thu 2:\n";
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        list2.add(x);
    }
    
    list1.merge(list2);
    cout << "Danh sach sau khi gop: ";
    list1.print();
}

int main() {
    testListInt();
    return 0;
}
