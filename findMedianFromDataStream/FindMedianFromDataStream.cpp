


class MedianFinder {
    
private:
    //we seprate the sorted array to two parts
    multiset<int> first, second;
    
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        if (first.empty() || num <= *(first.rbegin()) ) {
            first.insert(num);
        } else {
            second.insert(num);
        }
        
        if (first.size() > second.size() + 1) {
            auto it = first.end();
            it--;
            second.insert(*(it));
            first.erase(it);
        }
        
        if ( first.size() < second.size() ) {
            first.insert(*(second.begin()));
            second.erase(second.begin());
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (first.size()> second.size()) {
            return *(first.rbegin());
        }
        double x = *first.rbegin();
        double y = *second.begin();
        return (x+y)/2;
    }
};

