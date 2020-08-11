//ISSUE


#include <iostream> 

using namespace std; 

char bounderA(char a) {
    if (a == 'b') {
        a = 'e';  
    }
    else if (a == 'y') {
        a = 'v';  
    }
    return a; 

}
char bounderB(char b) {
     if (b == 'c') {
        b = 'd';  
    }
    else if (b == 'x') {
        b = 'w';  
    }
    return b; 
}

int recalc(int a, int s1, int s2) {
    int formation = 0; 

    bool repeat = true;
    while (repeat) {
        if (a < 0) {
            a = -a; 
            if ((a > s1 || a > s2) || (a > s1 && a > s2)) {
                formation = a - s1; 
                repeat = true; 
            }
            else {
                formation = a - s1 + 1; 
                repeat = false; 
            }
        }
    }

    if ((a > s1 || a > s2) || (a > s1 && a > s2)) {
        formation = a - s2; 
    }
    return formation; 
}

int main() {

    string str1, str2; 
    int n, form; 
    char r1, r2, fA, fB; 
    bool rep = true; 

    while (rep) {
        cin >> str1 >> str2 >> n; 
        int s1 = str1.length(); 
        int s2 = str2.length(); 
        form = n * n + n; 

        if ((s1 < 20 && s2 < 20) || (s1 < 20 || s2 < 20)) {
            rep = true; 
        }
        else if (s1 == s2) {
            if (((form < 0 || form > s1) || (form < 0 && form > s1)) || ((form < 0 || form > s2) && (form < 0 && form > s2))) {
                form = recalc(form, s1, s2);  
            }   
            for (int i = 0, j = 0; i < s1 && j < s2; i++, j++) {
                r1 = str1[s1 - i - 1]; 
                r2 = str2[s2 - j - 1]; 
                if ((r1 != r2) || (str1[i] == str2[j])) {
                    while (form > 1) {
                        fA = bounderA(r1); 
                        fB = bounderB(r2); 
                        if ((fA == 'a' || fA == 'z') || (fA == 'a' || fB == 'z')) {
                            fA = '.'; 
                            fB = '!'; 
                            r1 = fA; 
                            r2 = fB; 
                        }
                        else {
                            r1 = fA; 
                            r2 = fB; 
                        }
                        form--; 
                    }
                }
                cout << r1 << ' ' << r2 << endl; 
            }
            rep = false; 
        }
        else {
            cout << "..." << endl; 
            rep = false; 
        }
    }
    
    return 0; 
}