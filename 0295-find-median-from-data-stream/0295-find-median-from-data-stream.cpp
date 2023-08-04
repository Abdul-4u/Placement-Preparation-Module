class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        _max_priority_queue.push(num);
        _min_priority_queue.push(_max_priority_queue.top());
        _max_priority_queue.pop();

        if (_min_priority_queue.size() - _max_priority_queue.size() >= 1)
        {
            _max_priority_queue.push(_min_priority_queue.top());
            _min_priority_queue.pop();
        }
    }
    
    double findMedian() {
        if (_max_priority_queue.empty() && _min_priority_queue.empty())
            return 0;
        else if (_max_priority_queue.empty())
            return _min_priority_queue.top();
        else if (_min_priority_queue.empty())
            return _max_priority_queue.top();
        else
        {
            auto max_top = _max_priority_queue.top();
            auto min_top = _min_priority_queue.top();
            if (_max_priority_queue.size() == _min_priority_queue.size())
                return (max_top + min_top) / 2.;
            else
            {
                return _max_priority_queue.top();
            }
        }
    }

private:
    priority_queue<int, vector<int>, less<int>> _max_priority_queue; // Stores smaller half seen.
    priority_queue<int, vector<int>, greater<int>> _min_priority_queue; // Stores larger half seen.
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */