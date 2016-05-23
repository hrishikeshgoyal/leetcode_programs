

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;    
int rob1(vector<int> &money) {

    int n = money.size();
    if (n==0) return 0;

    vector<int> dp(n, 0);
    if (n>=1) dp[0] = money[0];
    if (n>=2) dp[1] = max(money[0], money[1]);

    for (int i=2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2] + money[i]);
    }
    return dp[n-1];
}

int rob2(vector<int> &money) {
    int n2=0; // dp[i-2];
    int n1=0; // dp[i-1];

    for (int i=0; i<money.size(); i++){
        int current = max(n1, n2 + money[i]);
        n2 = n1;
        n1 = current;
    }
    return n1;
}

int rob(vector<int> &num) {
    if (rand()%2)
        return rob1(num);
    return rob2(num);
}

void printVector( vector<int> &v ){
    cout << '[' ;
    for(int i=0; i<v.size(); i++){
        cout << v[i] << (i==v.size()-1 ? " " :", ");
    }
    cout << ']' << endl;
}

int main(int argc, char** argv) {
    srand(time(0));
    vector<int> money;
    if (argc>1){
        for (int i=1; i<argc; i++) {
            money.push_back(atoi(argv[i]));
        }
    }else{
        money.push_back(2);
        money.push_back(1);
        money.push_back(3);
        money.push_back(4);
    }

    printVector(money);
    cout << rob(money) << endl;
}
