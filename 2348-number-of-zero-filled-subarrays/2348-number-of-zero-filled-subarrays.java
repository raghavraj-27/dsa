class Solution {
    public long zeroFilledSubarray(int[] nums) {
        int i = 0, n = nums.length;
        List<Long> li = new ArrayList<Long>();
        
        while(i < n) {
            int j = i, cnt = 0;
            while(j < n && nums[j] == 0) {
                cnt++;
                j++;
            }
            
            if(cnt == 0) {
                i++;
                continue;
            }
            li.add((long) cnt);
            i = j;
        }
        
        long ans = 0;
        for(Long val: li) {
            ans += (val * (val+1)) / 2;
        }
        
        return ans;
    }
}