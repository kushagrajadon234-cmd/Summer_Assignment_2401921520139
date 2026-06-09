class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char,int> mp1, mp2;

        for (char ch : s1) {
            mp1[ch]++;
        }

        int k = s1.size();

        for (int i = 0; i < k; i++) {
            mp2[s2[i]]++;
        }

        if (mp1 == mp2) return true;

        int l = 0;

        for (int r = k; r < s2.size(); r++) {
            mp2[s2[r]]++;

            mp2[s2[l]]--;
            if (mp2[s2[l]] == 0) {
                mp2.erase(s2[l]);
            }

            l++;

            if (mp1 == mp2) return true;
        }

        return false;
    }
};
