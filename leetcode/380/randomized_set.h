#pragma once

#include <vector>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

class RandomizedSet {
private:
    std::vector<int> data_;
    std::unordered_map<int, int> index_;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        data_.reserve(1000);
        index_.reserve(1000);
        srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = index_.find(val);
        if (it != index_.end()) {
            return false;
        }
        data_.push_back(val);
        index_.insert(std::make_pair(val, data_.size()-1));
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = index_.find(val);
        if (it == index_.end()) {
            return false;
        }
        data_[it->second] = data_.back();
        index_[data_.back()] = it->second;
        data_.pop_back();
        index_.erase(it);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return data_[rand() % data_.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */