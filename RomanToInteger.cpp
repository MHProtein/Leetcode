#include <vector>
#include <string>
#include <unordered_map>


class Solution {
    public:
    
        std::unordered_map<char, int> lookUp{
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},      
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };
    
        int romanToInt(std::string s) {
    
            int result = 0;
            
            for(int i = 0; i < s.size() - 1; ++i){
                if(lookUp[s[i]] < lookUp[s[i + 1]]){
                    result -= lookUp[s[i]];
                }else{
                    result += lookUp[s[i]];
                }
            }
            return result + lookUp[s[s.size() - 1]];   
        }
    };