#include <iostream>
#include <ctime>

using namespace std; 

struct hInfo {
    string name; 
    int l; 
    int h; 
}; 

struct cor {
    int x; 
    int y; 
}; 


void func2(string, string); 


void func1(string n) {
    hInfo hI; 
    hI.name = n; 
    hI.l = 0; 
    hI.h = hI.name.length() - 1; 

    store s;
    
    if (n == " " && hI.h == 0) {
        cout << " " << endl; 
    }
    else {
        for (int i = hI.l; i < hI.h / 2; i++) {
            char temp = hI.name[i]; 
            hI.name[i] = hI.name[hI.name.length() - i - 1]; 
            hI.name[hI.name.length() - i - 1] = temp; 
        }
        if (hI.name != n) {
            func2(hI.name, n); 
        }
        else {
            cout << " " << endl; 
        }
    }
}

void func2(string n1, string n2) {
    cor c; 
    c.x = n1.length() - 1; 
    c.y = n2.length() - 1; 
    int cor_path[c.x][c.y]; 
    int cor_path2[c.x][c.y]; 
    int r1, r2; 
    int ct = 0; 

    bool flag = true; 

    if ((c.x == 0 && c.y == 0) || (c.x == 0 || c.y == 0)) {
        cout << " " << endl;
    }
    else {
        for (int i = 0, j = 0; i < c.x && j < c.y; i++, j++) {
            while (flag) {
                char a = n1[i]; 
                char b = n2[j];  
                r1 = rand() % c.x; 
                r2 = rand() % c.y; 
                if (r1 <= 0 && r2 <= 0) {
                    ct++; 
                    if (ct <= 0) {
                        func2(n1, n2); 
                    }
                    r1 = ct; 
                    r2 = ct; 
                }
                cor_path[i][j] = r1; 
                cor_path2[i][j] = r2;

                if (cor_path[i][j] == cor_path2[i][j]) {
                    flag = true; 
                }
                flag = false; 
            }
            cout << cor_path[i][j] << "|" << cor_path2[i][j] << " ";
        } 
        cout << endl; 
    }
}




int main() {

    string n; 

    cin >> n; 
    
    func1(n); 




    return 0; 
}