class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {

        //approach : Two Pointers (solved this by taking an extra space)
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
    }
};
