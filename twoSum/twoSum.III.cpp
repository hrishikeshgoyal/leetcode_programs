

class TwoSum {
    private:
        unordered_map<int, int> nums;
    public:

        //O(1) add
        void add(int number) {
            nums[number]++;
        }

        //O(n) find
        bool find(int value) {
            int one, two;
            for(auto it = nums.begin(); it != nums.end(); it++){
                one = it->first;
                two = value - one;
                if ( (one == two && it->second > 1) ||
                        (one != two && nums.find(two) != nums.end() ) ){
                    return true;
                }
            }
            return false;
        }
};
