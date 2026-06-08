class Solution {
public:
    bool isAnagram(string s, string t) {
        bool ans=true;
       unordered_map<char,int> mp;
       for (auto it: s){
        mp[it]++;
       } 
       for (auto it: t){
        mp[it]--;
       }
       for (auto it: mp){
        if (it.second != 0){
            return false;
            break;
        }
       }
       return ans;
    }
};
