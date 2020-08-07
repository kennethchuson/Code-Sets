#include <iostream> 

using namespace std; 

int func(int a) {
    int b, s = 0; 
    if (a == 0 || a == 1) {
        return 1; 
    }
    else {
        b = a + func(a - 1); 
    }
    return b; 
}

int main() {


    int rep = true;
    int solve = 0; 
    int fiveDiv = 0; 
    int sum = 0; 
    int n; 
    int size = 0; 
    string s; 
    while (rep) {
        cin >> n >> s; 
        size = s.length();  
        if (n <= 0 || n > 100 || size > 1000) {
            rep = true; 
        }
        else {
            while (n >= 1) {
                solve = func(n) * func(n + 1); 
                if (solve % 5 == 0) {
                    fiveDiv = solve; 
                }
                n--; 
            }
            rep = false; 
        }
    }
    if (fiveDiv <= 0) {
        cout << "ERROR" << endl; 
    }
    else {
        for (int i = 0; i < fiveDiv; i++) {
            sum += i; 
            for (int j = 0; j < size; j++) {
                if (j > 0 && j < 3) {
                    s[j] = '.'; 
                    sum -= j; 
                }
                cout << s[j] << endl; 
            }
            cout << sum << endl; 
        }
        if (sum == size) {
            cout << "SUCCESS" << endl; 
        }
        else {
            cout << "FINE" << endl; 
        }
    }
    return 0; 
}