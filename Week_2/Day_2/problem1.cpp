class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        int l=0;
        unordered_map<char,int> mp;
        for (int r=0;r<n;r++){
            mp[s[r]]++;
            while (mp[s[r]]>1){
                mp[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};
