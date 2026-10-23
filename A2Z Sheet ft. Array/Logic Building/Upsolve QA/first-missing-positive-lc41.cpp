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

        //Approach : Negative indexing + Pigeonhole principle
        //TC : O(N)
        //SC : O(1)

        /*
            this loop will remove the unnecessary numbers (like 0 or numbers greater than n)
            but why we remove numbers greater than n?
            cuz hamara jo array h , manlo ek array ka size 5 h 
            toh usme missing number 1 se 5 ke range mein hein aayega 
            agar saare numbers 5 ke uper hein h toh obvious h ki 1 hein answer hoga
            so that's why we are removing those values
        */

        for(int i = 0; i < n; i++)
        {
            if(nums[i] <= 0 || nums[i] > n) nums[i] = n + 1;
        }
        
        //now , here we will mark the presence of each number.
        
        for(int i = 0; i < n; i++)
        {
            //here abs is to prevent any negative index error
            int num = abs(nums[i]);
            
            //here abs is used specifically for the duplicate numbers , since it can remove our negative flag so
            if(num <= n) nums[num - 1] = -abs(nums[num - 1]);
        }

        
        for(int i = 0; i < n; i++)
        {
            //pehla positive number jo mila , uska index + 1 ko return kar denge 
            if(nums[i] > 0) return i + 1;
        }

        //pigeonhole principle (if 1 se n ke range mein koi number nahi mila missing number = n + 1)
        return n + 1;
    }
};

