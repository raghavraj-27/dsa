class Solution {
public:
vector<vector<string>> ans; 

bool checkPalindrome(int start, int end, string str) {
    while(start <= end)
        if(str[start++] != str[end--])
            return false;
    return true;
}

void makePartition(int ind, string s, vector<string>& v) 
{
    if(ind>=s.size()) {
        ans.push_back(v);
    }

    for(int i=ind; i<s.size(); i++) 
    {
        if(checkPalindrome(ind, i, s))
        {
            string str = s.substr(ind, i-ind+1); 
            // for(int p=ind; p<=i; p++)
            //     str += s[p];
            v.push_back(str); 
            makePartition(i+1, s, v); 
            v.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> v;
    makePartition(0, s, v);
    return ans;
}
};