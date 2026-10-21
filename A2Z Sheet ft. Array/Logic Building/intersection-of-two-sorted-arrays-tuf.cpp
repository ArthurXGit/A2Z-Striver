/*
    Approach : Two Pointers
    TC : O(M + N)
    SC : O(1) (took this space to return the intersection)
         Why the SC is not O(k) = min(nums1.size() , nums2.size()) ?

         ans : since we are required to return an array at the end for our answer . We didnt used any extra space to solve the problem . Only for the sake of returning the answer , we used extra array so it wont count in space complexity ....
*/


class Solution {
public:
    vector<int> intersectionArray(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;

        int i {};
        int j {};

        while(i < nums1.size() && j < nums2.size())
        {
            if(nums1[i] == nums2[j])
            {
                ans.emplace_back(nums1[i]);
                i++;
                j++;
            }

            else if(nums2[j] < nums1[i]) j++;

            else if(nums2[j] > nums1[i]) i++;

        }

        return ans;

        //testcase : 2
        /* 
            1 2 5

            2

            ans

        */
    }
};