

class NumArray {
private:
    int size;
    vector <long long> sums;
public:
    NumArray(vector<int> &nums): size(nums.size()), sums(size+1, 0) {
        for(int i=0; i<size; i++) {
            sums[i+1] = sums[i] + nums[i];
        } 
    }
    int sumRange(int i, int j) {
        return sums[j+1] - sums[i];
    }
};


