class Solution {
    public:
        int lengthOfLastWord(string s) {
            int length = 0;
            bool begin = false;
            for(int i = s.size() - 1; i >= 0; --i){
                if(begin && s[i] == ' ')
                    return length;
                else if(begin)
                    ++length;
                
                if(!begin && s[i] != ' ')
                {
                    begin = true;
                    ++length;
                }
            }
            return length;
        }
    };