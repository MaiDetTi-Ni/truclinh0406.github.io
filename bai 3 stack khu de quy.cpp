#include<iostream>
#include<stack>
using namespace std ;

// De quy tinh fibonacci
int fibonacci_dequy(int n) {
	if(n <= 0) 
	    return 0 ;
	if(n == 1)
	    return 1 ;
	return fibonacci_dequy(n-1) + fibonacci_dequy(n-2) ;
}

// Khu de quy tinh fibonacci dung stack
int fibonacci_stack(int n) {
	if(n <= 0)
	    return 0 ;
    if (n == 1)
	    return 1 ;
    
    stack<pair<int, int>> s ;
    s.push({n, 1}) ;
    int a = 0, b = 1 ;
    
   for(int i = 2; i <= n; i++) {
   	int temp = b ;
   	b = a+b ;
   	a = temp ;
    }
    return b ;
}

// De quy dao nguoc so
int DaoSo_dequy(int n, int rev= 0) {
    if (n == 0)
	return rev ;
    return DaoSo_dequy(n / 10, rev * 10 + n % 10);
}

// Khu de quy dao nguoc so dung stack
int DaoSo_stack(int n) {
    stack<int> s;
    while (n > 0) {
        s.push(n % 10);
        n /= 10;
    }
    int ketqua = 0, BoiSo = 1;
    while (!s.empty()) {
        ketqua += s.top() * BoiSo ;
        s.pop();
        BoiSo *= 10;
    }
    return ketqua ;
}

int main() {
    int n ;
    cout<< "Nhap n: " ;
    cin>> n ;
    cout<< "Fibonacci dequy("<< n <<") = " << fibonacci_dequy(n) << endl ;
    cout<< "Fibonacci Stack("<< n <<") = " << fibonacci_stack(n) << endl ;
    
    int SoCanDao ;
    cout<< " Nhap so can dao: " ;
    cin>> SoCanDao ;
    cout<< "Dao nguoc so De Quy: " << DaoSo_dequy(SoCanDao) << endl;
    cout<< "Dao nguoc so Stack: " << DaoSo_stack(SoCanDao) << endl;
    
    return 0 ;
}
