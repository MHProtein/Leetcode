#include <random>
#include <unordered_map>
#include <vector>

class RandomizedSet {
    public:
        RandomizedSet() {
            
        }
        
        bool insert(int val) {
            if(_data.contains(val)){
                return false;
            }    

            _vec.push_back(val);
            _data.insert({val, _vec.size() - 1});
        
            return true;
        }
        
        bool remove(int val) {
            if(!_data.contains(val)){
                return false;
            }    

            int pos = _data[val];
            _data[_vec.back()] = pos;
            std::swap(_vec[pos], _vec.back());
            _vec.pop_back();
            _data.erase(val);     

            return true;
        }
        
        int getRandom() {
            auto n = rand() % _vec.size();
            return _vec[n];
        }
    
    private:
        std::unordered_map<int, int> _data;
        std::vector<int> _vec;

    };