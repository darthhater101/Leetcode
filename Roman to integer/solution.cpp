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
