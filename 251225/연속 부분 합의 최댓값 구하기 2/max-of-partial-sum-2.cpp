#include <iostream>
using namespace std;

int arr[100000];

int main() {
  int max = -1001;
  int sum = 0;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i=0;i<n;i++) {
    if (sum <= 0){
      sum = 0;
      sum += arr[i];
    }else {
      sum += arr[i];
    }
    if (sum > max) {
      max = sum;
    }
  }

  cout << max;
  return 0;
}