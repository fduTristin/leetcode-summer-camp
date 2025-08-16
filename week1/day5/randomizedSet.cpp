#include <unordered_map>
#include <vector>
#include <random>

using namespace std;

class RandomizedSet
{
private:
    unordered_map<int, int> indices;
    vector<int> nums;

public:
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (indices.find(val) != indices.end())
        {
            return false;
        }
        else
        {
            nums.push_back(val);
            indices[val] = nums.size() - 1;
            return true;
        }
    }

    bool remove(int val)
    {
        if (indices.find(val) != indices.end())
        {
            int index = indices[val];
            int last = nums.back();
            nums[index] = last;
            indices[last] = index;
            nums.pop_back();
            indices.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom()
    {
        int r = rand() % nums.size();
        return nums[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */