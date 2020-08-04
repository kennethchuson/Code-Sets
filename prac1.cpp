#include <iostream>

using namespace std; 

int r, c, select, quad = 0; 
char bh; 




void tr1(int r, int c, char bh) {
    int bh_show = 0; 
    if (bh == 'Y' || bh == 'y') {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < i; j++) {
                if (i % 2 == 0 && j % 2 == 0) {
                    bh_show = 0; 
                }
                else {
                    bh_show = 1; 
                }
                cout << bh_show << " "; 
            }
            cout << endl; 
        }
    }
    else {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < i; j++) {
                cout << i << j << " "; 
            }
            cout << endl; 
        }
    }
    quad = 2; 
    cout << "Quadrant " << quad << endl; 
}


void tr2(int r, int c, char bh) {
    int bh_show = 0; 
    if (bh == 'Y' || bh == 'y') {
        for (int i = 0; i <= r; i++) {
            for (int j = i; j >= 0; j--) {
                if (i % 2 == 0 && j % 2 == 0) {
                    bh_show = 0; 
                }
                else {
                    bh_show = 1; 
                }
                cout << bh_show << " "; 
            }
            cout << endl; 
        }
    }
    else {
        for (int i = 0; i <= r; i++) {
            for (int j = i; j >= 0; j--) {
                cout << i << j << " "; 
            }
            cout << endl; 
        }
    }
    quad = 3; 
    cout << "Quadrant " << quad << endl; 
}

void tr3(int r, int c, char bh, int s1) {
    int bh_show = 0; 
    int s = 2 * r - 2; 
    if (bh == 'Y' || bh == 'y') {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < s; j++) {
                cout << " "; 
            }
            s -= s1; 
            for (int j = 0; j <= i; j++) {
                if (i % 2 == 0 && j % 2 == 0) {
                    bh_show = 0; 
                }
                else {
                    bh_show = 1; 
                }
                cout << bh_show << " "; 
            }
            cout << endl; 
        }
    }
    else {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < s; j++) {
                cout << " "; 
            }
            s -= 2; 
            for (int j = 0; j <= i; j++) {
                cout << i << j << " "; 
            }
            cout << endl; 
        }
    }
    quad = 4; 
    cout << "Quadrant " << quad << endl; 
}

void tr4(int r, int c, char bh) {
    int bh_show = 0; 
    if (bh == 'Y' || bh == 'y') {
        for (int i = r; i > 0; i--) {
                for (int j = 0; j < r - i; j++) {
                    cout << " "; 
                }
                for (int j = 1; j <= i; j++) {
                    if (i % 2 == 0 || j % 2 == 0) {
                        bh_show = 0; 
                    }
                    else {
                        bh_show = 1; 
                    }
                    cout << bh_show << " "; 
                }
                cout << endl; 
            }
    }
    else {
        for (int i = r; i > 0; i--) {
                for (int j = 0; j < r - i; j++) {
                    cout << " "; 
                }
                for (int j = 1; j <= i; j++) {
                   cout << i << j << " "; 
                }
            cout << endl; 
        }
    }
    quad = 4; 
    cout << "Quadrant " << quad << " and " << quad - 1 << endl; 

}






int main() {

    bool rep = true; 

    while (rep) {
        cin >> r >> c >> select >> bh; 
        if ((r <= 0 && c <= 0) || (r <= 0 || c <= 0)) {
            rep = true; 
        }
        else if ((r <= 3 && c <= 3) || (r <= 3 || c <= 3)) {
            rep = true; 
        }
        else {
            if (select == 1) {
                tr1(r, c, bh); 
            }
            else if (select == 2) {
                tr2(r, c, bh); 
            }
            else if (select == 3) {
                tr3(r, c, bh, 2); 
            }
            else if (select == 4) {
                tr3(r, c, bh, 1); 
            }
            else if (select == 5) {
                tr4(r, c, bh); 
            }
            else {
                rep = false; 
            }
        }
    }





    return 0; 
}