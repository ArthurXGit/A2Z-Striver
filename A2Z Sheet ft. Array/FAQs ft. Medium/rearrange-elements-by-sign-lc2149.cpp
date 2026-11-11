class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        int n = nums.size();

        /*
        takeaway from this problem : 

        1.memory is not magically allocated in cpp and direct access is much fast in response to dynamic allocation . agar mein koi bhi ek array ke index ko koi ek particular value dena chah rha hun , to sabse pehle woh index exist karna chahiye na ... uske liye uska size define hona chahiye .....
        
        2. swapping karna se array ka relative order toot jaata h , agar koi future ma yeh question aaye two pointer related and waha p agar relative order maintain rakhna h toh , 
        swapping ka use mat hein karo thoh acha h : )

        */
        vector<int> ansStore(n);

        int posIndex = 0;
        int negIndex = 1;

        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= 0)
            {
                ansStore[posIndex] = nums[i];
                posIndex += 2;
            }     

            else if(nums[i] < 0)
            {
                ansStore[negIndex] = nums[i];
                negIndex += 2;
            }

        }    

        return ansStore;
    }
};
        //made the vector to store the all positive numbers of the main array 
        // vector<int> holdPos;

        //the vector to store all the -ve numbers of the main array
        // vector<int> holdNeg;

        //written for traversing thru array.

        // for(int i = 0; i < n; i++)
        // {
                /*
                main concept written in the for loop

                1. agar number +ve h , toh kya karo ki usko positive array ma daal do.
                2. agar number -ve h , toh usko negative number waali array ma daal do.

                */
        //     if(nums[i] >= 0) holdPos.emplace_back(nums[i]);
        //     else if(nums[i] < 0) holdNeg.emplace_back(nums[i]);
        // }

        //i did this to resize the array because i have to insert the values again to the main array , that's why 
        // nums.resize(0);

        //i created two pointers for positive and negative numbers.

        //nhPS for positive numbers and nhNS for negative numbers.

        // int nhPS {}; (mujeh positve array se nikaal kar dena h na , so iske liye maine yeh banaya )
        // int nhNS {}; (i created this for the array which holds the negative values :) )

        // for(int i = 0; i < n; i++)
        // {

        // from the test cases , it's obvious that positive numbers are stored in the even indices and negative numbers are stored in the odd indices

        //     if(i%2 == 0)
        //     {
        //         nums.emplace_back(holdPos[nhPS]);
        //         nhPS++;
        //     }
        //     else
        //     {
        //         nums.emplace_back(holdNeg[nhNS]);
        //         nhNS++;
        //     } 
                
        // }

        // return nums;