class Solution {
    
public:
    int singleNumber(vector<int>& nums) 
    {
        //3. this is the optimal approach to solve the problem.
        
        int n = nums.size();

        
        int xorr = 0;

        //i went through all of the array by using this for loop
        for(int i = 0; i < n; i++)
        {
            /*
            *note : xorr of same elements = 0
            *xorr of 0 and a particular element is always the particular element
            *so i did this because xorr of same element leads to 0 and xorr of 0 and a particular element is the same element , so if a number's occurance is one in the array then by writing this statement will give us the desired answer :)
            */

            xorr = xorr ^ nums[i];
        }

        return xorr;

        //1. this is the better approach to solve this problem :)


        // //to store the size of the array
        // int n = nums.size();

        
        // map <long long , int> hashArray;

        // //this loop is used to increment the occurance of a particular element of the nums vector one by one.
        // for(int j = 0; j < n; j++)
        // {
        //     hashArray[nums[j]]++;
        // }

        // //i declared this to store the value of the key since "it" iterator is in local scope.
        // long long storage;

        // //this for each loop is to iterate through the entire hashArray.
        // for(auto it : hashArray)
        // {
        //     //it checks that if the value is 1 then store the value of the key to the storage and exit from the loop
        //     if(it.second == 1)
        //     {
        //       storage = it.first;
        //       break;
        //     } 
        // }

    
        // return storage;



        //2. //this is the brute force approach to solve the question.

        // //it signifies the size of the given array which was stored in a variable.
        // int n = nums.size();

        // //i took it because i have to check one by one that how many times that particular number appears.
        // int test_data;


        // //the first for loop is for selecting a element to check it's occurences
        // for(int i = 0; i < n; i++)
        // {
        //     //it tells the no of times the element appears.
        //     int reps = 0;

        //     //iam assiging the testdata as the value of the particular index of given array
        //     test_data = nums[i];

        //     //iterating through the array to check same numbers.
        //     for(int j = 0; j < n; j++)
        //     {

        //         /*this is the statement to check that if the test data is similar to a index value or not. if statement is true , then it increases the counting of that number that how many times that number appears*/
        //         if(nums[j] == test_data)
        //         {
                    
        //             reps++;
        //         }
        //     }

        //     /*if the count of a particular number is one , break from the current loop*/
        //     if(reps == 1) break;
        // }

        // //after breaking , return the test data we took.
        // return test_data;
    }
};
       
       
        