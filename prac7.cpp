//ISSUE


#include <iostream>

using namespace std; 



int main() {

    string str; 
    bool ok = true; 
    int n; 
    int make = 0; 
    int order = 0; 
    bool key = false; 
    int ct = 0; 
    cin >> str >> n; 

    if ((str.length() == 0 || n == 0) || (str.length() == 0 && n == 0)) {
        ok = false;         
    }
    else if (str.length() > n || str.length() < n) {
        while (ok) {
            order = n * (n + 1) / 2;
            if (order > n + (n - 1)) {
                if (str.length() > n) {
                    for (int i = 0; i < str.length(); i++) {
                        if (str[i - 1] == str[i + n]) {
                            str[i] = '$'; 
                            ct++; 
                            key = true; 
                            ok = false; 
                        }
                        else {
                            str[i] = '.'; 
                            ok = false; 
                        }
                    }
                }
                else if (str.length() < n) {
                    make = n << str.length(); 
                    for (int j = 0; j < str.length(); j++) {
                        if (str[j + 1] == str[j - n]) {
                            str[j] = '#'; 
                            ct++; 
                            key = true; 
                            ok = false; 
                        }
                        else {
                            str[j] = '.'; 
                            ok = false; 
                        }
                    }
                }
            }
        }
        if (key) {
            if (ct > 0) {
                cout << "Possible" << endl; 
            }
            else {
                cout << "impossible" << endl; 
            }
        }
    }
    else if (str.length() == n) {
        cout << "default" << endl; 
    }




    return 0; 
}
