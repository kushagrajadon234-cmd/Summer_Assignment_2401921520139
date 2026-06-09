class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        
        if (p.size() > s.size()) return ans;

        unordered_map<char,int> mp1, mp2;

        for (char c : p) {
            mp1[c]++;
        }

        int l = 0;

        for (int i = 0; i < p.size(); i++) {
            mp2[s[i]]++;
        }

        if (mp1 == mp2) {
            ans.push_back(0);
        }

        for (int i = p.size(); i < s.size(); i++) {
            mp2[s[i]]++;

            mp2[s[l]]--;
            if (mp2[s[l]] == 0) {
                mp2.erase(s[l]);
            }

            l++;

            if (mp1 == mp2) {
                ans.push_back(l);
            }
        }

        return ans;
    }
};
