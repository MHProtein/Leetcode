#include <iostream>
#include <vector>

class Solution {
    public:
        int trap(std::vector<int>& height) {
            int count = 0;
            int left = 0;
            int right = height.size() - 1;
            int leftMax = height[left];
            int rightMax = height[right];
            while(left < right){
                if(leftMax < rightMax){
                    ++left;
                    leftMax = std::max(leftMax, height[left]);
                    count += leftMax - height[left];
                }
                else{
                    --right;
                    rightMax = std::max(rightMax, height[right]);
                    count += rightMax - height[right];
                }
            }
            return count;
        }
    };