#include <iostream>
#include <ctime> 

using namespace std; 




int main() {

    srand(time(NULL)); 

    string str;
    bool enter = true; 
    int x, y, r, r2; 
    bool ok = false; 
    char vote; 
    cin >> x >> y >> str; 
    int arrMat[x][y]; 
    

    while (enter) {
        for (int i = 0; i < x; i++) {
            r = rand() % x; 
            arrMat[i][0] = r; 
            if (arrMat[i][0] > 0) {
                ok = false; 
                for (int j = 0; j < y; j++) {
                    r2 = (rand() % x) + (rand() % y); 
                    arrMat[i][j] = r2; 
                    if (arrMat[i][j] == arrMat[i - 1][j]) {
                        vote = 'A'; 
                    }
                    else if (arrMat[i][j] == arrMat[i][j + 1]) {
                        vote = 'X'; 
                    }
                    else if (arrMat[i][j] == arrMat[i][j]) {
                        vote = '.'; 
                    }
                    enter = false; 
                }
                if (ok) {
                    for (int k = 0; k < y; k++) {
                        r2 = (rand() % x) - (rand() % y); 
                        arrMat[i][k] = r2; 
                        if (arrMat[i][k] == arrMat[i - 1][k]) {
                            vote = 'Z'; 
                        }
                        else if (arrMat[i][k] == arrMat[i][k + 1]) {
                            vote = 'Y'; 
                        }
                        else if (arrMat[i][k] == arrMat[i][k]) {
                            vote = '#'; 
                        }
                        enter = false; 
                    }
                }
            }
        }
    }

    for (int i = 0; i < str.length(); i++) {
        int ptr1 = 0; 
        int ptr2 = str.length() / 2; 
        int ptr3 = str.length() - 1; 
        if (str[ptr1++] == str[ptr2--] && str[ptr1++] != str[ptr3--]) {
            str[i] = vote; 
        }
        else {
            cout << "....." << endl; 
        }
    }







    return 0; 
}
