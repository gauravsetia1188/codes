class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        // hash the jewels
        // traverse the stones
        
        unordered_set<char> s;
        for(auto i : jewels) {
            s.insert(i);
        }
        
        int ans = 0;
        for(auto i : stones) {
            if(s.count(i))
                ans++;
        }
        return ans;
    }
};
