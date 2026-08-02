class MedianFinder {
priority_queue <int> mxh;
priority_queue <int,vector <int>, greater <int>> mnh;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (mxh.empty()|| num<=mxh.top()){
            mxh.push(num);
        }
        else {
            mnh.push(num);
        }

        if (mxh.size()>mnh.size()+1){
            mnh.push(mxh.top());
            mxh.pop();
        }
        if (mnh.size()>mxh.size()){
            mxh.push(mnh.top());
            mnh.pop();
        }

    }
    
    double findMedian() {
        if (mxh.size()==mnh.size()){
            return (mxh.top()+mnh.top())/2.0;
        }
        return mxh.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */