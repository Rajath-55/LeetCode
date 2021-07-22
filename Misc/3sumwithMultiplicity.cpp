class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        long int ans = 0;
        for(int i = 0; i < n-2; ++i){
            int num1 = arr[i];
            int toFind = target - num1;
            int left = i + 1;
            int right = n - 1;
            
            while(left < right){
                if(arr[left] + arr[right] > toFind) right--;
                else if(arr[left] + arr[right] < toFind) left++;
                else if(arr[left] != arr[right]){
                    int count1 = 1,count2 = 1;
                    while(left + 1 < right and arr[left] == arr[left + 1]){
                        count1++;
                        left++;
                    }
                    while(left < right - 1 and arr[right] == arr[right-1]){
                        count2++;
                        right--;
                    }
                    ans += count1*count2;
                    left++;
                    right--;
                }else{
                    int l = right - left + 1;
                    ans += l*(l-1)/2;
                    break;
                }
            }
         
        }
           int mod = 1e9 + 7;
            return ans%mod;
    }
    
    
};

/*

Sort the array 
and two pointer twchnique with edge cases:
for every element, get the two sum : 
if the two elements in two sum are same, then the multiplicity = length C 2
else the multiplicity = count(firstEle)*count(secondEle)
add this to the answer;
standard left++ rigt-- shit also needed
thats it
O(N^2) O(1);
*/
