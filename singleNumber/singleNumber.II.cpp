

class Solution {
public:
    Solution(){
        srand(time(0));
    }
    
    //random invoker
    int singleNumber(int A[], int n) {
        if (rand()%2){
            return singleNumber_1(A, n);
        }
        return singleNumber_2(A, n);
    }

    int singleNumber_1(int A[], int n) {
        int count[32] = {0};
        int result = 0;
        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < n; j++) {
                if ((A[j] >> i) & 1) {
                    count[i]++;
                }
            }
            result |= ((count[i] % 3) << i);
        }
        return result;
    }


    int singleNumber_2(int A[], int n) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < n; i++) {
            // `ones & A[i]` the result is the bitmask which the bits appeared twice
            twos |= ones & A[i]; 
            // XOR means remove the bit which appeared twice int `ones` 
            ones ^= A[i];
            // count the `three`
            threes = ones & twos;
            // clear the `ones` and `twos` if the i-th bit had appeared three times.
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }

};
