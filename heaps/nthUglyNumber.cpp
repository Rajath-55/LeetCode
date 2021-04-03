class Solution {
public:
    long long int nthUglyNumber(int n) {
            priority_queue <long long, vector<long long>, greater<long long> > pq;
           long long x;
        pq.push(1ll);
        while(n--){
            if(pq.top()==x){
                pq.pop();
                n++;
                continue;
            }
            x = pq.top();
            
            pq.push(2*x);
            pq.push(3*x);
            pq.push(5*x);
            pq.pop();
        }
        return x;

    }
};
