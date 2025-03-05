#include <iostream>
#include <vector>

class Solution {
    public:
        int maxProfit(std::vector<int>& prices) {
            int max = 0;
            for(int i = 0; i != prices.size() - 1; ++i){
                int temp = prices[i + 1] - prices[i];
                if(temp > 0)
                    max += temp;
            }
            return max;
        }
    };