

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int findMin(vector<int> &num) {

    int low=0, high=num.size()-1;

    while(high-low>1){
        //skip the same element, this would cause the O(n) run-time complexity. 
        while (high - low > 1 && num[low] == num[high]){
            low++;
        }
        //binary search
        int mid = low + (high-low)/2;
        //If the array is not rotated then return num[low]
        //Notes: checking the equal situation
        if (num[low] <= num[mid] && num[mid] <= num[high]){
            return num[low];
        }
        //move the high pointer to the middle, if sub-array from low to mid is rotated.
        if (num[low] > num [mid]){
            high = mid;
            continue;
        }
        // move the low pointer to the middle, if sub-array from mid to high is rotated.
        if (num[mid] > num[high]){
            low = mid;
            continue;
        }
    }
    
    // checking the edge case 
    if (high == low) return num[low];
    return num[low] < num[high] ? num[low] : num[high];

}


void rotate_array(int a[], int n, int pos){
    int i, from=0;
    pos = pos % n;
    if (n<=0) return;

    int tmp = a[0];

    for(int i=0, step=0; step<n && i<pos; step++){
        int to;
        if (from-pos < 0) {
            to = n-pos+from; 
        }else{
            to = from-pos;
        }
        int t ;
        t = a[to];
        a[to] = tmp; 
        tmp = t;
        from = to;
        if ( to == i ){
            i++;
            from++;
            tmp = a[from];
        }
    }

}

void printArray(int A[], int n) {
    printf("{");
    for(int i=0; i<n; i++) {
        printf("%d, ", A[i]);
    }
    printf("}\n");
}

int main(int argc, char** argv)
{

    int cnt=20;

    if (argc>1) {
        cnt = atoi(argv[1]);
    }

    srand(time(NULL)); 

    int expectedMin, actualMin;
    int *a = new int[cnt];
    for(int n=0; n<=cnt; n++) {
        printf("--------------------------------------\n");
        //generate the array with random elements
        for(int i=0; i<cnt; i++){
            a[i]=rand()%cnt;
        }
        //sort the array
        sort(a, a+cnt); 
        expectedMin = a[0];
        //printArray(a, cnt);
        int rotate_pos = random() % cnt;
        //rotate_pos=2;
        printf("rotate=%d\n", rotate_pos);
        rotate_array(a, cnt, rotate_pos);
        printArray(a, cnt);

        vector<int> num(a, a+cnt);
        actualMin = findMin(num);
        cout << "findMin = " << actualMin << "   " << (expectedMin==actualMin ? "passed" : "failed") << endl;

    }
    delete[] a;

    return 0;
}
