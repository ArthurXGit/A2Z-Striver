
//Concept of this problem : Two pointers swapping (slow and fast pointer)

class Solution {
public:
    void moveZeroes(vector<int>& nums)
    {
        int n = nums.size();

        vector<int> temp;

        //1 . Brute Force : Overwrite 
        //TC : O(2N)
        //SC : O(N) (if no zeros , then max size of the temp array : size of the nums array)

        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0)
            {
                temp.emplace_back(nums[i]);
            }
        }

        int n1 = temp.size();

        //learning : if u declare vector's size before putting smth into it , it will store no value and if u do it after declaring the vector , then it will hold some value 
        //in short : dont measure smth which dont have anything

        for(int i = 0; i < temp.size(); i++)
        {
            nums[i] = temp[i];
        }

        for(int i = n1; i < n; i++)
        {
            nums[i] = 0;
        }

  
        //2. Optimal Approach : Two Pointers
        //mistake : doing the same thing to allocate the pointer location zeroPointer to nonzeroPointer
        //TC : O(N)
        //SC : O(1)

        int n = nums.size();

        int zeroPointer;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0) 
            {
                zeroPointer = i;
                break;
            }
        }

        int nonzeroPointer = zeroPointer + 1;

        while(nonzeroPointer < n)
        {
            if(nums[nonzeroPointer] != 0)
            {
                swap(nums[zeroPointer] , nums[nonzeroPointer]);
                zeroPointer++;
            }
            nonzeroPointer++;
        }
    }
};

