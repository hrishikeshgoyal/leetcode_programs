

class Solution {
public:

    int min(int a, int b) {
        return a < b ? a:b;
    }
    
    int min(int a, int b, int c) {
        return min( min(a, b),  c);
    }

    //  
    // The idea is we generate the ugly number instead of checking every number.
    //
    // To generate the next ugly number, we can use the existed ugly numbers to multipy 2,3,5,
    // and get the minimal one.
    //
    //     Let's start from the first ugly number - [1]
    //
    //        [1]  next = min( 1*2=2, 1*3=3, 1*5=5) = 2
    //
    //     Now we have [1,2], we can see, only the second one need be multipied by 2
    //     but both 3 and 5 still need be multipied by first one. So:
    // 
    //        [1,2]  next = min(2*2=4, 1*3=3, 1*5=5) = 3
    //
    //     Now we have [1,2,3], we can see the second one need be mulityped by 2 and 3,
    //     but the 5 still needs be multipied by first one. So:
    //
    //        [1,2,3]  next = min (2*2, 2*3, 1*5) = 4
    //
    //     and so on...
    //
    // So, we can see we need to maintain three indics in ugly number list, 
    // each one represents the place need be mulipied by 2,3,5.
    //
    // And we increase the index who's multiplication is the minimal. 
    //
    
    int nthUglyNumber01(int n) {
            
        int i=0, j=0, k=0;
        vector<int> v(1,1);
        
        while(v.size() < n){
            int next = min(v[i]*2, v[j]*3, v[k]*5);
            if (next == v[i]*2) i++;
            if (next == v[j]*3) j++;
            if (next == v[k]*5) k++;
            v.push_back(next);
        }
        return v.back();
    }
    
    // This version just uses the static variable to cache 
    // the 3 indics and the ugly number list
    int nthUglyNumber02(int n) {
            
        static int i=0, j=0, k=0;
        static vector<int> v(1,1);
    
        if (v.size()>=n) return v[n-1];
        
        while(v.size() < n){
            int next = min(v[i]*2, v[j]*3, v[k]*5);
            if (next == v[i]*2) i++;
            if (next == v[j]*3) j++;
            if (next == v[k]*5) k++;
            v.push_back(next);
        }
        return v.back();
    }
    
    int nthUglyNumber(int n) {
        return nthUglyNumber02(n); // 4ms-8ms
        return nthUglyNumber01(n); // 28ms
    }
};
