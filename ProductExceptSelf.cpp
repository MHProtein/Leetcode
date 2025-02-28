#include <iostream>
#include <vector>


class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {

        int n = nums.size();
        std::vector<int> products(n, 1);
        // std::vector<int> prefix(n, 1);
        // std::vector<int> suffix(n, 1);
        // for (size_t i = 1; i < n; ++i)
        // {
        //     prefix[i] = prefix[i - 1] * nums[i - 1];
        // }

        // for (int i = n - 2; i >= 0; --i)
        // {
        //     suffix[i] = suffix[i + 1] * nums[i + 1];
        // }
        
        // for (size_t i = 0; i < n; ++i)
        // {
        //     products[i] = prefix[i] * suffix[i];
        // }

        int temp = 1;

        //prefix
        for (size_t i = 1; i < n; ++i)
        {
            temp *= nums[i - 1];
            products[i] *= temp;
        }
        temp = 1;
        for (int i = n - 2; i >= 0; --i)
        {
            temp *= nums[i + 1];
            products[i] *= temp;
        }
        
        return products;
    }
};

int main(){
    Solution sol;
    std::vector<int> vec{1,2,3,4};
    auto ans = sol.productExceptSelf(vec);

    for (auto &&i : ans)
    {
        std::cout << i << std::endl;
    }
    
}