/* 
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Given a roman numeral, convert it to an integer. Input is guaranteed to be within the range from 1 to 3999.

Result: Runtime: 20 ms, faster than 75.58% of C++ online submissions for Roman to Integer.
        Memory Usage: 10.5 MB, less than 67.41% of C++ online submissions for Roman to Integer.
*/
class Solution {
public:
    
    int romanToInt(string s) {
        if(s.empty()) return 0;
        
        unordered_map<char, int> roman {
        { 'I' , 1 },
        { 'V' , 5 },
        { 'X' , 10 },
        { 'L' , 50 },
        { 'C' , 100 },
        { 'D' , 500 },
        { 'M' , 1000 }
    };
        
        int number = roman[s.back()];
        
        for(int i = 0;i < s.size() - 1;i++) {
            if(roman[s[i]] < roman[s[i + 1]]) {
                number -= roman[s[i]];
            } else {
                number += roman[s[i]];
            }
        }
        
        return number;
    } 
};
