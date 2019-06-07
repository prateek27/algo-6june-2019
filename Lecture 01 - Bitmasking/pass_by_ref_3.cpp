#include <iostream>
using namespace std;

void fun(int &z){
    z++;
}
int main() {
    int x = 10;
    //Reference Variables
   int &y = x;
   y++;
   fun(x);
   fun(y);
   cout<< x <<endl;
   cout<< y  <<endl;

}
