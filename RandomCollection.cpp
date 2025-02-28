#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>


class RandomizedCollection {
    public:
        RandomizedCollection() {
            
        }
        
        bool insert(int val) {
            bool ret = true;
            if(_data.contains(val)){
                ret = false;
            }

            _vec.push_back(val);
            _data[val].insert(_vec.size() - 1);
        
            return ret;
        }
        
        bool remove(int val) {
            if (_data.find(val) == _data.end()) {
                return false;
            }

            int pos = *_data[val].begin();
            _data[val].erase(pos);

            int lastIndex = _vec.size() - 1;
            int lastVal = _vec[lastIndex];

            if (pos != lastIndex) {
                _vec[pos] = lastVal;
                _data[lastVal].erase(lastIndex);
                _data[lastVal].insert(pos);
            }

            _vec.pop_back();

            if (_data[val].empty()) {
                _data.erase(val);
            }

            return true;
        }
        
        int getRandom() {
            auto n = rand() % _vec.size();
            return _vec[n];
        }
    
    private:
        std::unordered_map<int, std::unordered_set<int>> _data;
        std::vector<int> _vec;

    };