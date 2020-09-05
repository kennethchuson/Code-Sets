#include <iostream>

using namespace std; 


int main() {

    int n, m; 
    int form; 
    unsigned int group = 0; 
    unsigned int s = 0; 
    

    while (true) {
        cin >> n >> m; 
        unsigned int trMat[n][m];
        int trMat2[n][m];   
        if ((n <= 0 || m <= 0) || (n <= 0 && m <= 0)) {
            continue; 
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    trMat[i][j] = 0;  
                }
            }
            for (int i = 0; i < (n * m) / 2; i++) {
                if (i % 2 == 0 || i % 3 == 0) {
                    for (int j = 1; j < i; j++) {
                        if (i + j > i - j) {
                            form = i + j; 
                        }
                    }
                }
                else if (i % 2 == 0 && i % 5 == 0) {
                    for (int k = 1; k < i; k++) {
                        if (i + k > i - k) {
                            form = i + k; 
                        }
                    }
                }
            } 
            if (form <= 0) {
                break; 
            }

            for (int i = 0; i < n; i++) {
                trMat2[i][0] = form; 
                for (int j = 0; j < m; j++) {
                    trMat2[i][j] = (form << (form - 1)); 
                    trMat[i][j] = trMat2[i + 1][j] + trMat2[j][i - 1]; 
                    if (trMat[i][j + 1] > group) {
                        group = trMat[i - 1][j]; 
                    }
                    if (trMat2[i - 1][j] > group) {
                        group = trMat2[i][j + 1]; 
                    }
                }
            }

            s = (group % group - 1 == 0 && group >= group - form)? group - group / 2 : group + 1; 
            
            cout << "grouping: " << s << endl; 

        }

    }










    return 0; 
}