class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double>lower;
    priority_queue<double, vector<double>, greater<double>>higher;
   
    MedianFinder() {
      
    }
    
    void addNum(int num) {
        int lsize = lower.size(), rsize = higher.size();
        if(lsize == 0){
            lower.push(num);
            return;
        }else if(lsize==rsize){
            if(num < higher.top()){
                lower.push(num);
            }else{
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            }
        }
        else if(lsize > rsize){
            if(num > lower.top()){
                higher.push(num);
            }else{
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            }
        }
        
        
    }
    
    double findMedian() {
        if(lower.size() == higher.size()){
            return (lower.top() + higher.top())/2.0;
        }else
            return lower.top();
        
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
