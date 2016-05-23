

#include <iostream>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int> &height) {
    if (height.size()<=0) return 0;
    //Create an empty stack.
    vector<int> stack;
    //add a flag as a trigger if the end bar is met, and need to check the stack is empty of not .
    height.push_back(0);
    int maxArea = 0;
    for(int i=0; i<height.size(); i++){
        //If stack is empty or height[i] is higher than the bar at top of stack, then push ‘i’ to stack.
        if ( stack.size()<=0 || height[i] >= height[stack.back()] ) {
            stack.push_back(i);
            continue;
        }
        //If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
        //Let the removed bar be height[top]. Calculate area of rectangle with height[top] as smallest bar. 
        //For height[top], the ‘left index’ is previous (previous to top) item in stack and ‘right index’ is ‘i’ (current index).
        int topIdx = stack.back();
        stack.pop_back();
        int area = height[topIdx] * (stack.size()==0 ? i : i - stack.back() - 1 );
        if ( area > maxArea ) {
            maxArea = area;
        }
        //one more time. Because the stack might still have item.
        i--;
    }

    return maxArea;
}

void printArray(vector<int> &v)
{
    cout << "{";
    for(int i=0; i<v.size(); i++) {
        cout << " " << v[i];
    }
    cout << "}" << endl;
}
void test(int a[], int n)
{
    vector<int> v(a, a + n);
    printArray(v);
    cout << largestRectangleArea(v) << endl;
}

int main()
{
#define TEST(a) test(a, sizeof(a)/sizeof(int))

    int a0[] = {2,1,3,1};
    TEST(a0);
    int a1[] = {2,1,5,6,2,3};
    TEST(a1);

    return 0;
}

