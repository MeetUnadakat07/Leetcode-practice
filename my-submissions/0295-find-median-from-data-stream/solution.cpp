class MedianFinder {
public:
    priority_queue<int> maxPq;
    priority_queue<int, vector<int>, greater<int>> minPq;

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: push to max heap
        maxPq.push(num);

        // Step 2: move top to min heap
        minPq.push(maxPq.top());
        maxPq.pop();

        // Step 3: balance
        if (maxPq.size() < minPq.size()) {
            maxPq.push(minPq.top());
            minPq.pop();
        }
    }
    
    double findMedian() {
        if (maxPq.size() > minPq.size()) {
            return maxPq.top();
        }
        return (maxPq.top() + minPq.top()) / 2.0;
    }
};
