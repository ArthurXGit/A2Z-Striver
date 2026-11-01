class Solution {
public:
    int majorityElement(vector<int>& nums)
    {

        //3. The optimal solution (using the moore's voting algorithm)
        
        int n = nums.size();
        
        //made to select an element from the array.
        int element;
        
        //basic flag for element.
        int countElement {};

        //loop used to iterate through the array.
        for(int i = 0; i < n; i++)
        {
            /*
                Concept of this code.
                1.if the countElement is = 0 , select the element (depends upon the "i" value).
                2.make the countElement = 1.
                3.if the element = the current array element -> increase the countElement.
                4.if the element != the current array element -> decrease the countElement.
            */
           
            if(countElement == 0)
            {
                element = nums[i];
                countElement = 1;
            }

            else if(element == nums[i])
            {
                countElement++;
            }

            else
            {
                countElement--;
            }

        }

        //variable declared to check the occurance of the element
        int count_occurance {};


        //loop used to iterate through the array.
        for(int i = 0; i < n; i++)
        {
            // if selected number = element , increase the count.
            if(nums[i] == element) count_occurance++;
        }

        //if the count_occurance is greater than n/2 (n signifies the size of the array) , then return it.
        if(count_occurance > (n/2)) return element;

        //it's returned cuz function has to return something , that's why i returned this value :)
        return -1;
   }

};
        //1. it's definitely the BRUTE FORCE approach :)
        // int n = nums.size();

        // //i want to select elements one by one , so i created this ....
        // int testData = 0;

        // //i created this to check the majority element in the array , as stated in the question
        // int midd = n/2;

        // //i run this loop to select elements one by one to check it's occurence
        // for (int i = 0; i < n; i++)
        // {

        //     testData = nums[i];
        //     //i want to count the no of appearances of that test data , that's why i created this..
        //     int cnt = 0;
        //     for(int j = 0; j < n; j++)
        //     {
        //         if(nums[j] == testData) cnt++;
        //     }
        //     /*
        //     lastly , if the count exceeds the midd , then return the testdata , since in the question , it was stated that majority element appears in the array n/2 times , so 
        //     */
        //     if(cnt > midd)
        //     {
        //         break;
        //     } 
            
        // }
        // return testData;




        //2.the better approach

        // int n = nums.size();

        /*
        to count the no of occurance (bcoz there are negative inputs as per question condition)
        i made the map hash array , named it as trackOccurance...
        */
        // map<int , int> trackOccurance;

        /*
        to select element one by one , i did this for loop , so that the key will be selected as nums[i]
        and the value will be increasing as the for loop runs.
        */
        // for(int i = 0; i < n; i++)
        // {
        //     trackOccurance[nums[i]]++;
        // }

        /*
        since the iterator has the local scope , i created this variable , so that i can give the (it.first) value to this variable , so i can able to return it :)
        */
        // int holdValue;
        // for(auto it : trackOccurance)
        // {
            //this is the condition to check whether an element is in majority or not as stated in the question ....
        //     if(it.second > n/2)
        //     {
        //         holdValue = it.first;
        //         break;
        //     }
        // }
        
        // return holdValue;