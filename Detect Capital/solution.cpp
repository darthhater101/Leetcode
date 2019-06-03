/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".\

Otherwise, we define that this word doesn't use capitals in a right way.

Result: Runtime: 0 ms, faster than 100.00% of C++ online submissions for Detect Capital.
        Memory Usage: 8.3 MB, less than 49.86% of C++ online submissions for Detect Capital.
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        for(int i = 0;i < word.length();i++) {
            if(islower(word[i]) && isupper(word[i + 1]))
                return false;
            if(isupper(word[i]) && isupper(word[i + 1]) && islower(word[i + 2]))
                return false;
        }
        return true;
    }
};
