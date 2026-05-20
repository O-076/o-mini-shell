#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    cout << "Hello" << endl;
    fork();
    cout << "Hi";
}