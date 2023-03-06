class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> store_missing;
        
        int j=0;
        int required = k;
        for(int i=1; store_missing.size()<k; i++)
        {
            if(j<arr.size())
            {
                if(arr[j] != i)
                    store_missing.push_back(i);
                else
                    j++;
            }
            else
                store_missing.push_back(i);
        }
        
        return store_missing[k-1];
    }
};