#include <iostream>
using namespace std;

int main() {
    int x = 10;
    cout<< x <<endl;
    cout<< &x <<endl; // abc
    int *y;
    y = &x;
    cout<< y <<endl; //abc
    int **z = &y; //pqs
    //Derfercing
    cout<< z <<endl;
    cout<< **z <<endl;
    cout<< *z <<endl;
    cout<< *(&y) <<endl;
    cout<<&(*y) <<endl;
    cout<<&(*z)<<endl;
    cout<<&z <<endl;
    cout<<(*x) <<endl;





}
