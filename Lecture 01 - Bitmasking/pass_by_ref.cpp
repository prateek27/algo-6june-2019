#include <iostream>
using namespace std;
//Pass By Reference using Pointers
void fun(int *y){
    *y = *y + 1;
}

int main() {
    int x = 10;
    //Reference Variables
    fun(&x);
    cout<<x <<endl;

}
