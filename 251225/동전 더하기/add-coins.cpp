#include <iostream>

using namespace std;

int n, k;
int coins[10];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int count = 0;

    for(int i = n-1;i>=0;i--){
        count += k / coins[i];
        k = k % coins[i];
    }
    cout << count;

    return 0;
}
