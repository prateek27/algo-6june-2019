#include <iostream>
using namespace std;


int main() {
    int x = 10;
    //Reference Variables
   int &y = x;
   y++;
   
   cout<< x <<endl;
   cout<< y  <<endl;

}
