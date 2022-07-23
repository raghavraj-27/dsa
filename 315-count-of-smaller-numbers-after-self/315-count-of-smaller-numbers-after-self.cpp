class Solution {
public:
    void merge(int low, int mid, int high, vector<pair<int, int>>& v, vector<int>& count, 
               vector<pair<int, int>>& temp) {
        int i=low, j=mid, k=low; 
        
        while(i <= mid-1 and j<=high) {
            if(v[i].first > v[j].first) {
                count[v[i].second] += high - j + 1;
                temp[k++] = v[i++];
            } else {
                temp[k++] = v[j++];
            }
        }
        
        while(i <= mid-1) {
            temp[k++] = v[i++];
        }
        while(j <= high) {
            temp[k++] = v[j++];
        }
        
        for(int i=low; i<=high; i++) {
            v[i] = temp[i];
        }
    }
    
    void mergeSort(int low, int high, vector<pair<int, int>>& v, vector<int>& count, 
                  vector<pair<int, int>>& temp) {
        if(low >= high) return;
        
        int mid = (low + high) >> 1;
        mergeSort(low, mid, v, count, temp);
        mergeSort(mid+1, high, v, count, temp);
        
        merge(low, mid+1, high, v, count, temp);
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v;
        
        for(int i=0; i<n; i++) {
            v.push_back({nums[i], i});
        }
        
        vector<int> count(n);
        vector<pair<int, int>> temp(n);
        mergeSort(0, n-1, v, count, temp);
        
        return count;
    }
};