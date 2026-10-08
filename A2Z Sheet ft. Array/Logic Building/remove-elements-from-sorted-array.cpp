class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        //# method 1 : by taking the help of STL : set and using overwritting
        //TC : O(N)
        //SC : O(N log N)

        // set<int> st(nums.begin() , nums.end());   
        // int index = 0;
        // for(int it : st)
        // {
        //     nums[index] = it;
        //     index++;
        // }
        // return index;

        //# method 2 : by using the two pointer approach 
        // main intution : current is unique or not is to check it's previous element is same or diff 
        //j is acting as a pivot
        //mainly i is moving for finding the unique element

        int j = 1;

        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1]) 
            {
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};

