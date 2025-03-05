#include <vector>
#include <string>
#include <unordered_map>

class Solution {
    public:
        std::string intToRoman(int num) {
            std::string ans;
            int temp = 0;
            int denom = 1000;
    
            while(denom != 0){
                temp = num / denom * denom;
                num %= denom;
                denom /= 10;
    
                if(temp == 0)
                    continue;
    
                if(temp >= 1000){
                    ans.append(temp / 1000, 'M');
                }
                else if(temp == 900){
                    ans += "CM";
                }
                else if(500 <= temp && temp < 900){
                    ans.append(1, 'D');
                    ans.append((temp - 500) / 100, 'C');
                }
                else if(400 <= temp && temp < 500){
                    ans.append((500 - temp) / 100, 'C');
                    ans.append(1, 'D');
                }
                else if(100 <= temp && temp < 400){
                    ans.append(temp / 100, 'C');
                }
                else if(90 <= temp && temp < 100){
                    ans.append((100 - temp) / 10, 'X');
                    ans.append(1, 'C');
                }
                else if(50 <= temp && temp <= 80){
                    ans.append(1, 'L');
                    ans.append((temp - 50) / 10, 'X');
                }
                else if(40 <= temp && temp < 50){
                    ans.append((50 - temp) / 10, 'X');
                    ans.append(1, 'L');
                }
                else if(20 <= temp && temp < 40){
                    ans.append(temp / 10, 'X');
                }
                else if(9 <= temp && temp <= 10){
                    ans.append((10 - temp), 'I');
                    ans.append(1, 'X');
                }
                else if(5 <= temp && temp < 9){
                    ans.append(1, 'V');
                    ans.append(temp - 5, 'I');
                }
                else if(temp == 4)
                    ans += "IV";
                else
                    ans.append(temp, 'I');
            }
            return ans;
        }
    };
    