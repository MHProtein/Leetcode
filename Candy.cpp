#include <iostream>
#include <vector>

class Solution {
    public:
        int candy(std::vector<int>& ratings) {
            int peak = 0;
            int increase = 0;
            int decrease = 0;
            int count = 1;
            for(int i = 0; i != ratings.size() - 1; ++i){
                if(ratings[i + 1] > ratings[i]){
                    decrease = 0;
                    ++increase;
                    count += increase + 1;       
                    peak = increase;
                }
                else if(ratings[i + 1] == ratings[i]){
                    peak = 0;
                    increase = 0;
                    count += 1;
                    decrease = 0;
                }
                else{
                    increase = 0;
                    ++decrease;
                    count += decrease + 1;
                    if(peak >= decrease){
                        --count;
                    }
                    //12345621   we dont have to give the peak bonus candies
                    //12654321   we need to gave the peak bonus candies

                }
            }
            return count;
        }
    };