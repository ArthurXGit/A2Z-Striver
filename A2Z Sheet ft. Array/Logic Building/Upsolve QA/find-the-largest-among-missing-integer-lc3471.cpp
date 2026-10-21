class Solution {
public:
    int largestInteger(vector<int>& nums, int k)
    {

        //Approach 1 : hashmap + pointers
        if(nums.size() == 1) return nums[0];

        int i {};
        int j = k - 1;
        int x {};
        
        unordered_map<int , int> tracker;

        while(j < nums.size())
        {
            while(x < j + 1)
            {
                tracker[nums[x]]++;
                x++;
            }

            if(x == j + 1)
            {
                i++;
                j++;

                x = i;
            }
        }

        if(k == nums.size())
        {
            int largest1 {};

            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] > largest1) largest1 = nums[i];
            }

            return largest1;
        }

        vector<int> tracker2;

        for(int i = 0; i < nums.size(); i++)
        {
            if(tracker[nums[i]] == 1) tracker2.emplace_back(nums[i]);
        }

        if(tracker2.size() == 0) return -1;


        int largest {};

        for(int i = 0; i < tracker2.size(); i++)
        {
            if(tracker2[i] > largest) largest = tracker2[i]; 
        }

        return largest;

    }
};