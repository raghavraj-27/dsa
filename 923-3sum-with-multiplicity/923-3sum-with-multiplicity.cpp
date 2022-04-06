class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        long res = 0, n = arr.size();
        for(int i=0; i<n; i++) {
            vector<int> count(101, 0);
            for(int j=i+1; j<n; j++) {
                int k = target - arr[i] - arr[j];
                if(k>=0 and k<101 and count[k] > 0) {
                    res += count[k];
                    res %= 1000000007;
                }
                count[arr[j]]++;
            }
        }
        return (int)res;
    }
};