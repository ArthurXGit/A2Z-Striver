class Solution {
public:
    int largestInteger(vector<int>& nums, int k)
    {
        //note : "k" represents the size of the subarray...
        //Approach 1 : hashmap + pointers
        
        if(nums.size() == 1) return nums[0];

        /*
            for subarray , i created these three pointers
            i and j will be at the boundary positions of the array
            x is to traverse within the subarray
        */
        
        int i {};
        int j = k - 1;
        int x {};

        //it will store key as (nums array element) and (element count) as value
        unordered_map<int , int> tracker;

        while(j < nums.size())
        {
            /*
                since x will traverse till the last of the subarray , if it traverses till j , it's fine
                but if it goes beyond that , then for that purpose i have also added some solutions for it
            */

            // if x lies below j or equal to j 
            while(x <= j)
            {
                tracker[nums[x]]++;
                x++;
            }

            //if x crossed j
            if(x > j)
            {
                i++;
                j++;

                //since the boundary is changed , x should be in the starting position of the subarray , that's why i did this
                x = i;
            }
        }

        //in case if k is equal to size of given array , for that return the largest element present in that array
        if(k == nums.size())
        {
            int largest1 {};

            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] > largest1) largest1 = nums[i];
            }

            return largest1;
        }

        //it will store those elements whose count is one
        vector<int> tracker2;

        for(int i = 0; i < nums.size(); i++)
        {
            if(tracker[nums[i]] == 1) tracker2.emplace_back(nums[i]);
        }

        //if no one has the size of 1 , then it will simply return -1 (indicates that there is no missing number present)
        if(tracker2.size() == 0) return -1;

        /*
            now , i have to check which is the bigger number , for that purpose i have declared a largest variable and ran a for loop for finding largest number.
            once the largest number is found , return that number..
        */
        
        int largest {};

        for(int i = 0; i < tracker2.size(); i++)
        {
            if(tracker2[i] > largest) largest = tracker2[i]; 
        }

        return largest;

    }
};
