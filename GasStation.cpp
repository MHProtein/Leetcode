#include <iostream>
#include <vector>


class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int canCompleteIndicator = 0;
        int currentFuel = 0;
        int begin = 0;
        int n = gas.size();
        for(int i = 0; i != n; ++i){
            currentFuel += gas[i] - cost[i];
            canCompleteIndicator += gas[i] - cost[i];
            if(currentFuel < 0){
                currentFuel = 0;
                begin = i + 1; 
            }
        }
        return canCompleteIndicator < 0 ? -1 : begin;
    }
};


int main(){
    Solution sol;
    std::vector<int> gas{1,2,3,4,5};
    std::vector<int> cost{3,4,5,1,2};
    auto ans = sol.canCompleteCircuit(gas, cost);

    std::cout << ans << std::endl;
}