

#include <iostream>
#include <vector>
using namespace std;




int findPeakElement(const vector<int> &num) {

    int n = num.size();
    int low = 0;
    int high = n - 1;

    int mid = 0, v1, v2;

    while ( low < high ) {

        // Find the index of middle element
        mid = low + ( high - low ) / 2;

        // Compare middle element with its neighbours (if neighbours exist)
        if ( ( mid == 0 || num[mid] > num[mid-1] ) && 
                ( mid == n-1 ||  num[mid] > num[mid+1] )  ){
            return mid;
        }

        // If middle element is not peak and its left neighbor is greater than it
        // then left half must have a peak element
        if (mid >0 && num[mid-1] > num[mid]){
            high = mid - 1;
        // If middle element is not peak and its right neighbor is greater than it
        // then right half must have a peak element
        }else{
            low = mid + 1;
        }

    }

    return low;
}


void printVector(vector<int> &n) {
    cout << "[ ";
    int i;
    for(i=0; i<n.size(); i++){
        cout << n[i] << (i==n.size()-1 ? " ]" : ", ");
    }
    cout << endl;
}

void test(int a[], int n) {
    vector<int> v(a, a+n);
    cout << "Peak Index = " << findPeakElement(v) << "\t";
    printVector(v);
}


#define TEST(a) test(a, sizeof(a)/sizeof(a[0]))

int main(int argc, char**argv)
{
    int n0[] = {1};
    TEST(n0);

    int n1[] = {1,2};
    TEST(n1);

    int n2[] = {2,1};
    TEST(n2);

    int n3[] = {1,2,3};
    TEST(n3);

    int n4[] = {3,2,1};
    TEST(n4);

    int n5[] = {1,2,3,2};
    TEST(n5);

    int n6[] = {0,1,2,9,7,5,4,2,1};
    TEST(n6);

    int n7[] = {1,2,1,2,1};
    TEST(n7);

    int n8[] = {1,2,1,2,3,1};
    TEST(n8);

    int n9[] = {1,2,3,2,4,2,1};
    TEST(n9);

    int n10[] = {1,3,1,2,1,3,1};
    TEST(n10);

    return 0;
}
