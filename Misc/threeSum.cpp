<<<<<<< HEAD
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
            return {};
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int su = nums[i] + nums[j] + nums[k];
                if (su == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                };
                if (su > 0)
                    k--;
                if (su < 0)
                    j++;
            }
        }
        for (auto x : s)
            res.push_back(x);
        return res;
    }
};


//A Better Algo (2 pointer taken from other solution)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // If array is small (size < 3)
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
            return {};

        //Sorting Array:
        sort(nums.begin(), nums.end());

        //Declaring Variables:
        vector<vector<int>> ans;
        int i = 0;

        //Evaluating ans:
        for (i = 0; nums[i] <= 0 && i < nums.size() - 2; i++)
        {
            //If Elem at idx i same as previous
            //continue to avoid duplicates:
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            //Applying 2sum Strategy on remaining array:
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                //If sum > 0 decrimenting k to decrease sum:
                if (nums[j] + nums[k] + nums[i] > 0)
                    k--;

                //if sum < 0 incrementing j to increase sum:
                else if (nums[j] + nums[k] + nums[i] < 0)
                    j++;

                //else we push_back one solution
                //And also change idx j and idx k to avoid duplicates:
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int p1 = nums[j];
                    int p2 = nums[k];

                    //change idx j to another elem
                    //so that the elem will not be equal to elem at j
                    while (nums[j] == p1 && j < k)
                        j++;

                    //change idx k to another elem
                    //so that the elem will not be equal to elem at k
                    while (nums[k] == p2 && j < k)
                        k--;
                }
            }
        }
        return ans;
    }
=======
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
            return {};
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int su = nums[i] + nums[j] + nums[k];
                if (su == 0)
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                };
                if (su > 0)
                    k--;
                if (su < 0)
                    j++;
            }
        }
        for (auto x : s)
            res.push_back(x);
        return res;
    }
};


//A Better Algo (2 pointer taken from other solution)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // If array is small (size < 3)
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
            return {};

        //Sorting Array:
        sort(nums.begin(), nums.end());

        //Declaring Variables:
        vector<vector<int>> ans;
        int i = 0;

        //Evaluating ans:
        for (i = 0; nums[i] <= 0 && i < nums.size() - 2; i++)
        {
            //If Elem at idx i same as previous
            //continue to avoid duplicates:
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            //Applying 2sum Strategy on remaining array:
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                //If sum > 0 decrimenting k to decrease sum:
                if (nums[j] + nums[k] + nums[i] > 0)
                    k--;

                //if sum < 0 incrementing j to increase sum:
                else if (nums[j] + nums[k] + nums[i] < 0)
                    j++;

                //else we push_back one solution
                //And also change idx j and idx k to avoid duplicates:
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int p1 = nums[j];
                    int p2 = nums[k];

                    //change idx j to another elem
                    //so that the elem will not be equal to elem at j
                    while (nums[j] == p1 && j < k)
                        j++;

                    //change idx k to another elem
                    //so that the elem will not be equal to elem at k
                    while (nums[k] == p2 && j < k)
                        k--;
                }
            }
        }
        return ans;
    }
>>>>>>> 673ed86091449e4adc8c32e9546b1b85b39181ad
};