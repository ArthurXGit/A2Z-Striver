/*
    Approach : Sorting + Pointer
    TC : O(N log N)
    SC : O(log N)
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums)
    {

        int n = nums.size();
        int flag {};
        int start {};

        sort(nums.begin() , nums.end());
        
        for(int it : nums)
        {
            if(it == 1)
            {
                flag = 1;
                start = 1;
                break;
            }
        }

        if(flag == 0) return 1;

        else
        {
            for(int i = 0; i < n; i++)
            {
                if(nums[i] == start) start++;
            }
        }

        return start;
    }
};

