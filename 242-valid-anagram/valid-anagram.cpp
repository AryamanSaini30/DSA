class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        int freq[26] = {0};

        for(int i = 0; i < s.size(); i++){
            freq[s[i] - 'a'] += 1;
        }

        for(int i = 0; i < t.size(); i++){
            freq[t[i] - 'a'] -= 1;
        }

        for(int f : freq){
            if(f != 0) return false;
        }
        return true;
    }
};