class Solution {
public:
int f(int i, int j, string& a, string& b) {
    if(i < 0 or j < 0) return 0;
    if(a[i] != b[j]) return 1 + f(i-1, j-1, a, b);
    return max(f(i-1, j, a, b), f(i, j-1, a, b));
}
int findLUSlength(string a, string b) {
    if(a == b) return -1;
    return max(a.size(), b.size());
    // cout<<a.size()<<endl;
//     if(a.size() != b.size()) return max(a.size(), b.size());
//     if(a.size() == b.size() and a!=b) return a.size();
//     int ans = f(a.size()-1, b.size()-1, a, b);
//     if(ans == 0) return -1;
//     return ans;
// }
}
};