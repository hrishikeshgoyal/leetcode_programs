

class Solution {
public:
    bool canJump(int A[], int n) {
        if (n<=0) return false;
        
        // the basic idea is traverse array, maintain the most far can go
        int coverPos=0;
        // the condition i<=coverPos means traverse all of covered position 
        for(int i=0; i<=coverPos && i<n; i++){
            
            if (coverPos < A[i] + i){
                coverPos = A[i] + i;
            }
            
            if (coverPos>=n-1){
                return true;
            }
        }
        return false;
    }
};
