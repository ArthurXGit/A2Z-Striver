class Solution {
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        /*
            The Optimal Solution
            TC : O(N)
            SC : O(1)

            Algorithm : Boyer - Moore Voting Algorithm
            (same as the ME - I problem , but slightly upgraded version)

            note : everything is same as ME - I but here's the catch .....

            in the testcase [2 , 1 , 1 , 3 , 1  , 4 , 5 , 6] , if we look up closely at the 5th iteration , there is the allocation of element1 as 1 , but previously element2 is assigned as 1 , which is not good cuz element2 has taken that earlier. So in order to tackle this , we have to add some code in the section of count1 == 0 & count2 == 0

            we have to make sure that if the count is zero (it can be of ele1 or ele2) & here , we have to check that the no. we are taking is not same as ele1 / ele2 (if we took ele2 / ele1).

            that's it , but do a manual search for both of them to make sure that they are appearing (n / 3) times.....
        */
        vector<int> ans;

        int n = nums.size();

        int count1 {};
        int count2 {};

        int element1 = INT_MIN;
        int element2 = INT_MIN;

        for(int i = 0; i < n; i++)
        {
            if(count1 == 0  && nums[i] != element2)
            {
                element1 = nums[i];
                count1 = 1;
            }

            else if(count2 == 0  && nums[i] != element1)
            {
                element2 = nums[i];
                count2 = 1;
            }

            else if(nums[i] == element1) count1++;
            else if(nums[i] == element2) count2++;

            else 
            {
                count1--;
                count2--;
            }
        }

        int element1_occ {};
        int element2_occ {};

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == element1) element1_occ++;
            if(nums[i] == element2) element2_occ++;
        }

        if(element1_occ > (n / 3))ans.emplace_back(element1);
        if(element2_occ > (n / 3))ans.emplace_back(element2);
        
        return ans;
    }
};

    /*
        My approach : Using a hashmap to count the occ.
        TC : O(N)
        SC : O(N)
    */
        // int n = nums.size();

        // vector<int> ans;

        // unordered_map<int , int> hashhmap;

        // for(int i = 0; i < nums.size(); i++)
        // {
        //     hashhmap[nums[i]]++;
        // }

        // //use of this for each loop for unordered_map
        // for(auto it : hashhmap)
        // {
        //     if(it.second > (n / 3)) ans.emplace_back(it.first);
        // }

        // return ans;  