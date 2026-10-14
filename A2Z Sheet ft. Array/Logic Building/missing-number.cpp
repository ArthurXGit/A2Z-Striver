class Solution {
public:
    int missingNumber(vector<int>& nums) {

        //my naive approach
        //TC : O(N log N)
        //SC : O(log N)

        // sort(nums.begin() , nums.end());

        // int n = nums.size();
        // int missing {};
        // int flag {};

        // for(int i = 0; i < n; i++)
        // {
        //     if(nums[i] == n)
        //     {
        //         flag = 1;
        //         break;
        //     }
        //     else flag = 0;
        // }

        // if(flag == 0)
        // {
        //     return n;
        // }

        // else
        // {
        //     for(int i = 1; i < nums.size(); i++)
        //     {
        //         if(nums[i] != nums[i - 1] + 1) 
        //         {
        //             missing = nums[i] - 1;
        //             break;
        //         }
        //     }

        //     return missing;
        // }

        //better approach using my idea :
        // simple and concise code and logic

        //my previous logic : if next no : previous no + 1 then return that
        //for handling the error of not finding n , we have to run a loop specific for that only

        //so this handles it perfectly and no other loop is needed for this n 
        
        //my take : in array , if possible u can try for a thing to look some kind of relationship related to the index and the data present inside the index

        // sort(nums.size() , nums.end());

        // int n = nums.size();

        // for(int i = 0; i < n; i++)
        // {
        //     if(nums[i] != i) return i;
        // }

        // return n;

        //  Optimal approach 1 : using the boolean array ....
        //  TC : O(N)
        //  SC : O(N)

        //APPROACH : since every element is from 0 to n (maybe n missing so ultimately n - 1 elements) , here to create a boolean array of size n + 1 and iterate thru the loop and assign true value to those who are actually present in the indices , if not they are by default zero

        // int n = nums.size();
        // int missing {};
        // vector<bool> checker(n + 1 , false);

        // for(int i = 0; i < n; i++)
        // {
        //     checker[nums[i]] = true;
        // }
        
        // // for(int c : nums)
        // // {
        // //     checker[c] = true;
        // // }

        // for(int j = 0; j < n; j++)
        // {
        //     if(!checker[j]) return j;
        // }

        // return n;

        //optimal approach 2 : using the sum method 
        //TC : O(N)
        //SC : O(1)

        // int n = nums.size();

        // int sumExpected = n * (n + 1) / 2;
        // int sumActual {};

        // for(int it : nums)
        // {
        //     sumActual += it;
        // }

        // return sumExpected - sumActual;

        //Optimal Approach 3 : using the XOR method .
        //int xorResult = nums.size();

        // for(int i = 0; i < nums.size(); i++)
        // {
        //     xorResult ^= i ^ nums[i];
        // }

        // return xorResult;

        /*
            approach notes #for me obv :)
            
            in xor : 
            1. xor of same nos : 0
            2. xor of 0 and a no : no

            in this : we will try to make pairs 

            why : if pairs existed , they will cancel each other by xor and that value will remain which have no pair , as 0 xor X : X

            so , x will be our final answer ....
        */

        
    }
};



