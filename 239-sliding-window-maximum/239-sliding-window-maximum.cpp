class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        map<pair<int,int>,int> m;
        vector<int> ans;
        for(int i=0;i<k;i++){
            m[{nums[i],i}]=nums[i];
        }
        ans.push_back((--m.end())->second);
        int j=0;
        for(int i=k;i<nums.size();i++){
            m.erase({nums[j],j});
            m[{nums[i],i}]=nums[i];
               ans.push_back((--m.end())->second);
            j++;
        }
        return ans;
    }
};