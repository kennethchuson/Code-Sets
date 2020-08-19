#include <iostream>

using namespace std; 


struct check {
    int a; 
    int b;  
}; 

int main() {

    check c; 

    int n, s, calc; 
    bool fail = false; 
    int answ = 0; 
    cin >> n;  

    if (n == 0) {
        cout << " " << endl; 
    }
    else {
        while (true) {
            int st = 0; 
            while (st < n) {
                c.a = (n % 2 == 0)? 1000 : 3000; 
                if (c.a == 1000) {
                    c.b += c.a - 1; 
                }
                else if (c.a == 3000) {
                    c.b += c.a + 1; 
                }
                st++; 
            }
            for (int i = 0; i < c.a; i++) {
                i = c.a - 1; 
                for (int j = i + 1; j < c.b; j++) {
                    s += (i + j) * (j - i); 
                }
            }
            if (s <= 0) {
                break; 
            }
            cout << s << endl; 
        }
    }






    return 0; 
}