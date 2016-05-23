
#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

vector<int> maxSlidingWindow02(vector<int>& nums, int k) {
    vector<int> result;

    //using multiset for collecting the window data (O(nlog(k) time complexity)
    multiset<int> w;

    for(int i=0; i<nums.size(); i++) {
        //remove the left item which leaves window 
        if (i >= k) {
            w.erase(w.find(nums[i-k]));
        }
        //insert the right itme which enter the window
        w.insert(nums[i]);
        if (i>=k-1) {
            result.push_back(*w.rbegin());
        }
    }

    return result;
}

vector<int> maxSlidingWindow01(vector<int>& nums, int k) {
    vector<int> result;

    //using multiset for collecting the window data (O(nlog(k) time complexity)
    deque<int> q;

    for(int i=0; i<nums.size(); i++) {
        //remove the left item which leaves window 
        if (!q.empty() && q.front() == i - k) {
            q.pop_front();
        }
        //remove all num which less than current number from the back one by one
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
        //insert the right itme which enter the window
        q.push_back(i);
        if (i>=k-1) {
            result.push_back(nums[q.front()]);
        }
    }

    return result;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    return maxSlidingWindow01(nums, k);
    return maxSlidingWindow02(nums, k);
}

void printVector( vector<int>& v ) {
    cout << "{ ";
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << (i==v.size() ? " ": ", ");
    }
    cout << "}" << endl;
}

int main(int argc, char** argv) 
{
    int a[] = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> nums(a, a+sizeof(a)/sizeof(a[0]));
    printVector(nums);
    vector<int> result = maxSlidingWindow(nums, k);
    printVector(result);
}
