#include <iostream>
using namespace std;

int main() {
  string arr[2];
  for(int i=0;i<2;i++){
    cin >> arr[i];
  }

  if(arr[0].size() == arr[1].size()){
    cout << "same";
  }else if(arr[0].size() > arr[1].size()){
    cout << arr[0] << ' ' << arr[0].size();
  }else{
    cout << arr[1] << ' ' << arr[1].size();
  }
  // Please write your code here.
  return 0;
}