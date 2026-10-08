class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        // vector<int> holder;
        
        //# by the method of removing and inserting
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(nums[i] != val) holder.emplace_back(nums[i]);      
        // }
        //
        // nums.erase(nums.begin() , nums.end());
        //
        // for(int it : holder)
        // {
        //     // nums.emplace_back(it);
        // }

        // # by the method of overwritting
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     if(nums[i] != val) holder.emplace_back(nums[i]);      
        // }
        //
        // for(int i = 0; i < holder.size(); i++)
        // {
        //     nums[i] = holder[i];
        // }
        //
        // nums.erase(nums.begin() + holder.size() , nums.end());

        //# by using existing functions
        // erase(nums , val);
        // return nums.size();

        //# by using two pointer approach
        int index = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val) {
                nums[index] = nums[i];
                index++;
            }
        }

        return index;
    }
};

