#include <vector>
#include <iostream>

class Solution {
    public:
        int hIndex(std::vector<int>& citations) {
            int n = citations.size();
            std::vector<int> citationBuckets(n + 1, 0);

            for (size_t i = 0; i < n; ++i)
            {
                ++citationBuckets[std::min(citations[i], n)];
            }
            
            int cumulative = 0;

            for (int i = n; i >= 0; --i)
            {
                cumulative += citationBuckets[i];
                if(cumulative >= i)
                    return i;
            }
            
            return 0;
        }
    };

int main(){
    Solution sol;
    std::vector<int> v{3,0,6,1,5};
    std::cout << sol.hIndex(v) << std::endl;
}