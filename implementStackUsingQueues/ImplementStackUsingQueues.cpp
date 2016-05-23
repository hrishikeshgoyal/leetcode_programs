


class Stack {
    public:
        // Push element x onto stack.
        void push(int x) {
            nums.push(x);
        }
        // Removes the element on top of the stack.
        void pop() {
            if (!empty()) {
                int len = nums.size()-1;
                //Don't treat the "-->" is a new operator. ;-)
                while ( len-->0) {
                    nums.push(nums.front());
                    nums.pop();
                }
                nums.pop();
            }
        }
        // Get the top element.
        int top() {
            return nums.back();
        }
        // Return whether the stack is empty.
        bool empty() {
            return nums.empty();
        }

    private:
        queue<int> nums;
};
