
#include <stdlib.h>
#include <iostream>
#include <map>
using namespace std;

int squares(int n) {
    int result = 0;
    int sq = 0;
    for (; n>0; n/=10) {
        sq = n%10;
        result += (sq * sq);
    }
    return result;
}

bool isHappy(int n) {

    if (n==1) return true;

    map<int, bool> m;
    m[n]=true;

    while (n!=1) {
        n = squares(n);
        //cout << n << endl;
        if (m.find(n) != m.end()){
            return false;
        }
        m[n] = true;
    }

    return true;
}


int main(int argc, char** argv) 
{
    int n = 2;
    if (argc > 1){
        n = atoi(argv[1]);
    }
    cout << n << (isHappy(n) ? " is " : " isn't ") << "a happy number" << endl;
    return 0;
}
