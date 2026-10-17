/*
    * Problem : Two Sum
    * TC : O(N)
    * SC : O(N)
    * Approach : Hashtable
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    { 
        unordered_map<int , int> hashmap;

        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];

            //If we want to check if a certain data is in the map or not , then there are three ways 

            /*
                * Method : 1

                if(hashmap.contains(complement)) return {hashmap[complement] , i};
                else hashmap.emplace(nums[i] , i);

                Notes :

                contains() function only return true or false. if true then the statement executes and if false then it will go to the else part
            */

            /*
                * Method : 2 

                if(hashmap.find(complement) != hashmap.end())
                {
                    return {hashmap[complement] , i};
                }
            
                Notes :

                hashmap will check that complement number till the end
                if it is not found despite searching it till the end of hashmap , we simply put the index and the index number in the hashmap

                if it's found before the hashmap ends , then it will return the indices , which are required for our answer.

                by using unordered hashmap , it takes the SC of O(N)

                why ? cuz there is no sorting happening here so log N operation is reduced here (ek ko agar push kiya toh log N time lagta , agar N items hote toh N log N , but kyunki idhar unordered map h so no sorting , hence O(N) space complexity)
            */  


            /*  
                Method : 3

                if(hashmap.count(complement)) return {hashmap[complement] , i};
                hashmap[nums[i]] = i;

                Notes :
                count returns 0s and 1s

                if the particular element is found which we are looking for , then it will return 1 otherwise 0

                that's it :)
            */  

            /*
                Notes (imp):
                There are three methods to insert values to the map :

                1. map[key] = value;
                2. map.insert(key , value);
                3. map.emplace(key , value);
            */

            /*
                Method : 4

                took the help of find() function and kept it to the iterator 'a'

                if find() function fails to find the required val , it will return map.end()

                -> is used to access the data inside that memory value
            */

            auto a = hashmap.find(complement);

            if(a != hashmap.end())
            {
                return {a -> second , i};
            }

            hashmap[nums[i]] = i;
        }

        return {};
    }
};

        //brute force approach : 
        // TC : O(N ^2)
        // SC : O(1)

        // for(int i = 0; i < nums.size() - 1; i++)
        // {
        //     for(int j = i + 1; j < nums.size(); j++)
        //     {
        //         if(nums[i] + nums[j] == target) return {i , j};
        //     }
        // }

        // return {-1 , -1};


        //mistakes:

        // for(j = i + 1; j < nums.size(); j++)
        // {
        //     if(nums[i] + nums[j] == target) return {i , j};
        // }

        // i++;

        // while(i < nums.size() - 1)
        // {
        //     if(nums[i] + nums[j] == target) return {i , j};
        //     j++;
        // }