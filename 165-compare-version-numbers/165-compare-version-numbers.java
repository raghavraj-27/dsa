class Solution {
    public int compareVersion(String version1, String version2) {
        
        int numa = 0, numb = 0;
        int i=0,j=0;
        while(i < version1.length() || j < version2.length()){
            
            while(i < version1.length() && version1.charAt(i) != '.'){
                numa = numa*10 + version1.charAt(i)-'0';
                i++;
            }
            
            while(j < version2.length() && version2.charAt(j) != '.'){
                numb = numb*10 + version2.charAt(j)-'0';
                j++;
            }
            
            if(numa < numb)
                return -1;
            if(numa > numb)
                return 1;
            
            numa = 0; numb = 0;
            i++;j++;
        }
        
        return 0;
    }
}