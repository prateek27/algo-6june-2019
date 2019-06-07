#include <iostream>
using namespace std;


int main() {
    int arr[] = {4,2,4,7,6,7,6,5,3,3,5};
    int n = sizeof(arr)/sizeof(int);

    int uniq=0;
    for(int i=0;i<n;i++){
        uniq = uniq^arr[i];
    }
    cout<<uniq;

    return 0;
}
