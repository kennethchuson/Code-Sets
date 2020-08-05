#include <iostream> 
#include <ctime> 

using namespace std; 

struct mat {
    int x, y, z; 
}; 

struct permute {
    string name; 
}; 

int main() {
    mat ml; 
    permute pN; 

    const int maxC = 26; 
    char rP; 
    int n, m, l; 
    int itrP; 
    string eName; 
    int rx, ry, rz = 0; 
    int max, min; 
    int answ = 0; 
    cin >> n >> m >> l >> eName; 
    pN.name = eName; 
    ml.x = n; 
    ml.y = m; 
    ml.z = l; 
    int corMat[ml.x][ml.y][ml.z]; 
    int sizeN = pN.name.length(); 
    int ctC[maxC] = {0}; 
    int score[] = {0, 0, 0, 0, 0}; 


    for (int i = 0; i < ml.x; i++) {
        for (int j = 0; j < ml.y; j++) {
            for (int k = 0; k < ml.z; k++) {
                int rx = rand() % ml.x; 
                int ry = rand() % ml.y; 
                int rz = rand() % ml.z; 
                corMat[i][j][k] = rx + ry + rz;  
                if (corMat[i][j][k] == 0) {
                    corMat[i][j][k] = 1; 
                }  
                if (corMat[i][j][k] > max) {
                    max = corMat[i][j][k]; 
                }
                if (corMat[i][j][k] < min) {
                    min = corMat[i][j][k]; 
                }
            }
        }
    } 
    if (max <= 0 && min <= 0) {
        for (int i = 0; i < sizeN; i++) {
            pN.name[i] = '.'; 
            cout << pN.name << endl; 
        }
    }
    else {        
        for (int i = 0; i < sizeN; i++) {
            ctC[pN.name[i] - 'a']++; 
        }
        for (int i = 0; i < maxC; i++) {
            for (int j = 0; j < ctC[i]; j++) {
                rP = (char) ('a' + i); 
                itrP++; 
                cout << rP << endl;
                for (int k = 1; k < sizeof(score) / sizeof(score[0]); k++) {
                    score[k] = itrP * itrP; 
                    while (score[k] > 0) {
                        answ++; 
                        score[k]--; 
                    }
                }
                cout << answ << endl; 
            }
        }

    }



    





    return 0; 
}