#include <vector>

class Solution {
    public:
        int jump(std::vector<int>& nums) {
            int target = nums.size() -1;
            int near = 0;
            int far = nums[near];
            int count = 1;

            while(far >= target){
                int tempFar = far;
                int tempNear = near;
                for (int i = near; i < far; ++i)
                {
                    int temp = i + nums[i];
                    if(temp > far){
                        tempFar = temp;
                        tempNear = i;
                    }
                }
                ++count;
            }
            return count;
        }
    };