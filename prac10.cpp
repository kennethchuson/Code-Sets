#include <iostream>
#include <vector> 

using namespace std;


int fib(int num) {
    if (num <= 1) {
        return 1; 
    }
    else {
        return fib(num - 2) + fib(num - 1); 
    }
}


int main() {

    vector<int> vec; 

    int n; 
    unsigned int input; 
    cin >> n; 

    bool flag = true; 
    int calc = 0; 
    int reverse = 0;

    for (int i = 0; i < n; i++) {
        cin >> input; 
        vec.push_back(input); 
    }

    
    for (int i = 0; i < vec.size(); i++) {
        reverse = vec[vec.size() - i - 1]; 
        if (vec[i] != reverse) {
            vec[i] = vec[vec[i] * reverse]; 
        }
        while (flag) {
            if (vec[i] >= 0) {
                vec[i] = 0; 
            }
            if (vec[i] % 2 == 0) {
                calc = fib(vec[i] - 1) + fib(vec[i]); 
                flag = false; 
            }
            else {
                calc = fib(vec[i] + 1) + fib(vec[i]); 
                flag = false; 
            }
        }
    }
    if (calc == 2) {
        cout << "you loose" << endl; 
    }
    else {
        cout << "you win" << endl; 
    }
    cout << "result: " << calc << endl; 

    


    return 0; 
}