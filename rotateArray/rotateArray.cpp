

#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;


void reverseArray(int nums[],int start, int end){
    int temp;
    while(start < end){
        int temp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = temp;
    }
}


void rotate1(int nums[], int n, int k) {
    if (k<=0) return;
    k %= n; 
    reverseArray(nums, n-k, n-1);
    reverseArray(nums, 0, n-k-1);
    reverseArray(nums, 0, n-1);    
}

void rotate2(int nums[], int n, int k) {
    if (k<=0) return;
    k %= n;
    int currIdx=0, newIdx=k;
    int tmp1 = nums[currIdx], tmp2; 
    int origin = 0;

    for(int i=0; i<n; i++){

        tmp2 = nums[newIdx];
        nums[newIdx] = tmp1;
        tmp1 = tmp2; 

        currIdx = newIdx;

        //if we meet a circle, move the next one
        if (origin == currIdx) {
            origin = ++currIdx;
            tmp1 = nums[currIdx];
        }
        newIdx = (currIdx + k) % n;

    } 
}

void rotate(int nums[], int n, int k) {
    if (random()%2==0) {
        cout << "[1] ";
        return rotate1(nums, n, k);
    }
    cout << "[2] ";
    return rotate2(nums, n, k);
}

void printArray(int nums[], int n) {
    cout << "[ " ;
    for(int i=0; i<n; i++) {
        cout << nums[i] << ((i==n-1)? " " : ", ");
    }
    cout << "]" << endl;
}

void initArray(int nums[], int n) {
    for(int i=0; i<n; i++) {
        nums[i] = i;
    }
}


int main(int argc, char**argv) {
    
    srand(time(0));

    int nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    const int n = sizeof(nums)/sizeof(int);

    for (int i=0; i<n; i++) {
        initArray(nums, n);
        rotate(nums, n, i);
        printArray(nums, n);
    }
    return 0;
}
