class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {

        //approach : Two Pointers (solved this by taking an array)
        //TC : O(M + N)
        //SC : O(M + N) 
        
        int Pl {};
        int Pr {};
        
        vector<int> arrayMerged;

        while(Pl < nums1.size() && Pr < nums2.size())
        {
            if(nums1[Pl] <= nums2[Pr]) 
            {
                if(Pl >= m && nums1[Pl] == 0) Pl++;

                else 
                {
                    arrayMerged.emplace_back(nums1[Pl]);
                    Pl++;
                }
            }

            else
            {
                arrayMerged.emplace_back(nums2[Pr]);
                Pr++;
            }
        }

        while(Pl < nums1.size())
        {
            if(Pl >= m && nums1[Pl] == 0) Pl++;
                
                else 
                {
                    arrayMerged.emplace_back(nums1[Pl]);
                    Pl++;
                }
        }

        while(Pr < nums2.size())
        {
            arrayMerged.emplace_back(nums2[Pr]);
            Pr++;
        }

        for(int i = 0; i < m + n; i++)
        {
            nums1[i] = arrayMerged[i];
        }

        //Approach 2 : Used Three Pointer Approach and used constant space :)
        //TC : O(M + N)
        //SC : O(1)

        /*
            bugs fixed before final submission : 
            1. left the condition when m = 0
            2. left the condition when i = 0
            3. negative index access ho rha tha in some test cases
        */

        int i = m - 1;
        int j = n - 1;
        int k = nums1.size() - 1;

        if(m == 0) 
        {
            // i = nums1.size() - 1; (:funne:)
            k = nums1.size() - 1;
        }

        while(j >= 0)
        {
            if(i < 0 || nums2[j] >= nums1[i])
            {
                nums1[k] = nums2[j];
                j--;
            } 

            else
            {
                if(i >= 0)
                {
                    nums1[k] = nums1[i];
                    i--;
                }
            }

            k--;
        }


    }
};