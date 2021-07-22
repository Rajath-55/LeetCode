class Solution {
public:
    int getTime(int mid, vector<int>&piles){
        int time = 0;
        for(int i = 0; i < piles.size(); ++i){
            time+=(piles[i]%mid == 0 ? piles[i]/mid : piles[i]/mid + 1);
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int maxi = piles[piles.size() -1];
        int low =1, high = maxi;
        
        while(low < high){
            int mid = low + (high - low)/2;
            int time = getTime(mid, piles);
            if(time > h){
                low = mid + 1;
            }else{
                high = mid;
            }
            
        }
        return low ;
        
    }
};


/*
binary search for the optimal speed
with a condition that with that speed the monkey should be able to finish 
in h hrs
n log n time complexit;


*/
