class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        //finding the duplicates by using the floyd's tortoise and hare algo...
        
        //algorithm steps : 
        /*
            slow will move once , fast will move twice
            
            after they made their moves and if they meet at the exact the same place , they formed a cycle basically

            now bring the slow pointer to it's initial position & keep the fast pointer at its place

            now , for finding the duplicate , move both slow and fast only once

            after this , the place where they meet , that value of the index is the duplicate value we are looking for ......

            but in code , make sure that ki slow should be move once and fast twice , otherwise if we keep them at the starting index , it will give always the starting value , hence the purpose is defeated  :(

        */

        //TC : O(N)
        //SC : O(1)

        //when to apply this algorithm : 

        //in the array terms , index value represents the valid indices & there is any duplicacy in the array then we can apply this algorithm
        int fast = nums[0];
        int slow = nums[0];

        slow = nums[slow];
        fast = nums[nums[fast]];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow = nums[0];

        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;

        // return -1;
    }
};
        // for(slow = 0; slow < nums.size(); slow++)
        // {
        //     slow = nums[slow];
        // }

        // while(slow <= nums.size() - 1)
        // {
        //     slow = nums[slow];
        // }

        // while(fast <= nums.size() - 1)
        // {
        //     fast = nums[fast];
        //     fast = nums[fast];
        // }

        // if(slow == fast) slow = 0;

        // for(slow = 0; slow <= nums.size() - 1; slow++)
        // {
        //     slow = nums[slow];
        //     fast = nums[fast];

        //     if(slow == fast) return nums[slow];
        // }
        
        // int n = nums.size();
        // int hold {};

        // sort(nums.begin() , nums.end());
        // for(int i = 0; i < nums.size() - 1; i++)
        // {
        //     if(nums[i] == nums[i + 1])
        //     {
        //         hold = nums[i];
        //         break;
        //     } 
        // }

        // vector<int> checker(n + 1 , 0);

        // for(int i = 0; i < n; i++)
        // {
        //     checker[nums[i]]++;
        // }

        // for(int j = 0; j < checker.size(); j++)
        // {
        //     if(checker[j] >= 2) return j;
        // }

        

        // return -1;