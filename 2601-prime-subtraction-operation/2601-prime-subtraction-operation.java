class Solution {
    ArrayList<Integer> v = new ArrayList<Integer>();
    Solution() {
        int n = 1000;
        boolean[] prime = new boolean[1001];
        for(int i=0; i<prime.length; i++) {
            prime[i] = true;
        }
        // memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n; p++) {
            if (prime[p] == true) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        
        for (int p = 2; p <= n; p++) {
            if (prime[p]) {
                v.add(p);
            }
        }
    }
    boolean isSorted(int[] nums) {
        for(int i=1; i<nums.length; i++) {
            if(nums[i] <= nums[i-1]) return false;
        }
        return true;
    }
    public boolean primeSubOperation(int[] nums) {
        int n = nums.length;
        // System.out.println(v.size());
        for(int i=0; i<n; i++) {
            int prime = 0;
            for(int j=0; j < v.size() && v.get(j) < nums[i]; j++) {
                if(i == 0) prime = v.get(j);
                else {
                    if(nums[i] - v.get(j) > nums[i-1]) {
                        prime = v.get(j);
                    }
                }
            }
            
            if(prime == nums[i]) continue;
            nums[i] = nums[i] - prime;
        }
        
        return isSorted(nums);
    }
}