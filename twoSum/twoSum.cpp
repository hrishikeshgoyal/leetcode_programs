

class Solution {
public:


    //
    // The implementation as below is bit tricky. but not difficult to understand
    //
    //  1) Traverse the array one by one
    //  2) just put the `target - num[i]`(not `num[i]`) into the map
    //     so, when we checking the next num[i], if we found it is exisited in the map.
    //     which means we found the second one.
    //      
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int, int> m;
        vector<int> result;
        for(int i=0; i<numbers.size(); i++){
            // not found the second one
            if (m.find(numbers[i])==m.end() ) { 
                // store the first one poisition into the second one's key
                m[target - numbers[i]] = i; 
            }else { 
                // found the second one
                result.push_back(m[numbers[i]]+1);
                result.push_back(i+1);
                break;
            }
        }
        return result;
    }
};
