#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    string s;
    int sum = 0;
    for(int i=0;i<2;i++){
        cin >> s;
        sum += s.size();
    }
    cout << sum;
    return 0;
}