class Solution {
public:
    void flip(vector<int>&arr, int idx){
        int i = 0;
        while(i < idx){
            swap(arr[i++], arr[idx--]);
        }
    }
    vector<int> pancakeSort(vector<int>& arr) 
    {
        vector<int> res;
        int ele = arr.size();
        while(ele > 0)
        {
            for(int i = 0 ; i < arr.size() ; i++)
            {
                if (arr[i] == ele)
                {
                    if (ele != i+1)
                    {
                        res.push_back(i+1);
                        flip(arr, i);
                    }
                    if (ele != i+1)
                    {
                        res.push_back(ele);
                        flip(arr, ele - 1);
                    }
                    break;
                }
            }
            ele--;
        }
        return res;
    }
};
/*
For i = lastIndex downto 1:
find the max Element in arr[:lastIdx + 1];
then flip it till the maxIdx;
then flip again till lastIdx;

*/
