class Solution {
    public long beautifulSubarrays(int[] nums) {
        long cnt = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int x = 0;
        
        for(int i=0; i<nums.length; i++) {
            x = x ^ nums[i];
            
            if(x == 0) cnt++;
            
            if(mp.containsKey(x)) {
                cnt += mp.get(x);
                mp.put(x, mp.get(x) + 1);
            } else {
                mp.put(x, 1);
            }
        }
        
        return cnt;
    }
}