/*
242. Valid Anagram
Solved
Easy
Topics
Companies
Given two strings s and t, return true if t is an 
anagram
 of s, and false otherwise.

 

Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

*/


class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(&s[0], &s[s.size()]);
        std::sort(&t[0], &t[t.size()]);
        return s==t;
    }
};

//Or another way    
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        // Initialize a vector of size 26 (for each letter in the alphabet) with all elements set to 0
        std::vector<int> freq(26, 0);
        for (int i=0; i<s.size(); i++) {
            int num_s = s[i] -'a';
            int num_t = t[i] -'a';
            freq[num_s]++;
            freq[num_t]--;
        }
        
        std::sort(freq.begin(), freq.end());
        if (freq[0]!=0) return false;
        return true;
    }
};


/*
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); i++) {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }

        for (const int c : freq) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};
*/

/