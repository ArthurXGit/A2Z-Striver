
class Solution {
    public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        /*
            Approach 1 : Two Pointers 
            TC : O(M log M + N log N + M * N)
            SC : O(1)
        */
       
       set<int> st;
       for(int i = 0; i < nums1.size(); i++)
       {
           for(int j = 0; j < nums2.size(); j++)
           {
               if(nums1[i] == nums2[j]) 
               {
                   if(st.size() == 0 || st.find(nums1[i]) == st.end()) st.insert(nums1[i]);
                }
            }
        }
        
        
        vector<int> ans(st.begin() , st.end());  
        return ans;
        
        /*
            Approach 2 : Array + Hash Table
            TC : O(M * N)
            SC : O(1)
        */
        
        vector<int> hashtable(100000);

        int i {};
        int j {};

        while(i <= nums1.size() && j < nums2.size())
        {
            if(i == nums1.size() - 1 && nums1[i] != nums2[j])
            {
                i = 0;
                j++;
            }

            else if(nums1[i] == nums2[j]) 
            {
                hashtable[nums1[i]]++;
                i = 0;
                j++;
            }

            else i++;
        }

        
        vector<int> ans;

        for(int i = 0; i < hashtable.size(); i++)
        {
            if(hashtable[i] != 0) ans.emplace_back(i);
        }

        return ans;
    }
};