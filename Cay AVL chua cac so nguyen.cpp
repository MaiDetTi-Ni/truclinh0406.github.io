#include <iostream>
using namespace std;
// Cấu trúc của một nút trong cây BST
struct Node {
    int value;  // Giá trị của nút
    Node* left; 
    Node* right; 
    // Constructor khởi tạo nút với giá trị cho trước
    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};
// Hàm thêm một phần tử vào cây BST
Node* insert(Node* root, int value) {
    if (root == nullptr) {  // Nếu cây rỗng, tạo nút mới
        return new Node(value);
    }
    if (value < root->value) {  // Nếu giá trị nhỏ hơn giá trị của nút hiện tại, thêm vào cây con trái
        root->left = insert(root->left, value);
    }
    else if (value > root->value) {  // Nếu giá trị lớn hơn giá trị của nút hiện tại, thêm vào cây con phải
        root->right = insert(root->right, value);
    }
    return root;  // Trả về nút gốc của cây
}
// Hàm tìm kiếm một phần tử trong cây BST
Node* search(Node* root, int value) {
    if (root == nullptr || root->value == value) {   // Nếu cây rỗng hoặc đã tìm thấy giá trị
        return root;
    }
    if (value < root->value) {  // Nếu giá trị cần tìm nhỏ hơn giá trị của nút hiện tại, tìm trong cây con trái
        return search(root->left, value);
    }
    return search(root->right, value);  // Nếu giá trị cần tìm lớn hơn giá trị của nút hiện tại, tìm trong cây con phải
}
// Hàm tìm nút có giá trị nhỏ nhất trong cây
Node* findMin(Node* root) {
    Node* current = root;
    while (current && current->left != nullptr) {  // Duyệt đến nút trái nhất trong cây
        current = current->left;
    }
    return current;
}
// Hàm xóa một phần tử khỏi cây BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) {
        return root;
    }
    if (value < root->value) {  // Nếu giá trị nhỏ hơn giá trị của nút hiện tại, tìm và xóa trong cây con trái
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->value) {   // Nếu giá trị lớn hơn giá trị của nút hiện tại, tìm và xóa trong cây con phải
        root->right = deleteNode(root->right, value);
    }
    // Nếu tìm thấy nút cần xóa
    else {
        // Nếu nút chỉ có một con hoặc không có con
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);  // Nếu nút có cả hai con, tìm giá trị nhỏ nhất trong cây con phải
        root->value = temp->value;  // Thay giá trị của nút cần xóa với giá trị nhỏ nhất
        root->right = deleteNode(root->right, temp->value);  // Xóa nút có giá trị nhỏ nhất trong cây con phải
    }
    return root;
}

// Hàm duyệt cây theo thứ tự trung trực (in-order)
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left); // Duyệt cây con trái
        cout << root->value << " "; // In giá trị của nút hiện tại
        inorder(root->right); // Duyệt cây con phải
    }
}

int main() {
    Node* root = nullptr;

    // Thêm các phần tử vào cây BST
    root = insert(root, 26);
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 18);
    root = insert(root, 12);
    root = insert(root, 30);
    // Duyệt cây theo thứ tự trung trực (in-order)
    cout << "duyet cay theo thu tu in_order: ";
    inorder(root);
    cout << endl;
    // Tìm kiếm một phần tử trong cây
    int value = 18;
    Node* foundNode = search(root, value);
    if (foundNode) {
        cout << "tim thay phan tu " << value << " trong cay." << endl;
    } else {
        cout << "khong tim thay phan tu " << value << " trong cay." << endl;
    }
    // Xóa một phần tử khỏi cây
    cout << "xoa phan tu 9 khoi cay: " << endl;
    root = deleteNode(root, 9);
    // Duyệt cây sau khi xóa
    cout << "duyet cay sau khi xoa phan tu 9: ";
    inorder(root);
    cout << endl;

    return 0;
}
