class Solution {
public:
    int strStr(string haystack, string needle) {
        string comb = needle + "#" + haystack;
        int pre = 0, suff = 1;
        int n = comb.length();
        vector<int> lps(n, 0);
        while (suff < n) {
            if (comb[pre] == comb[suff]) {
                pre++;
                lps[suff] = pre;
                suff++;
            } else {
                if (pre != 0) {
                    pre = lps[pre - 1];
                } else
                    suff++;
            }
            if (lps[suff-1] == needle.size()) {
                return suff-2*needle.size()-1;
                break;
            }
        }
        return -1;
    }
};
