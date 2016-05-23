


class Solution {
public:

    int countDigitOne(int n) {
        long long base=1, left=n, right=0, currDigit=0;
        int numOfOne = 0;
        while(left>0) {
            currDigit = left % 10;
            left = left/ 10;
            
            if (currDigit == 0) {
                numOfOne += (left * base);
            }else if (currDigit == 1) {
                numOfOne += (left * base + right + 1);
            }else {
                numOfOne += ((left+1)*base);
            }
            
            right = right + currDigit * base;
            base *= 10;
        }
        return numOfOne;
    }
};
