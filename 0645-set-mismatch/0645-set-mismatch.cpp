class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        for(int i=0;i<nums.size();i){
            if(nums[i]!=i+1 && nums[i]!=nums[nums[i]-1]){
                int curr=nums[i];
                swap(nums[curr-1],nums[i]);
            }
            else{
                i++;
            }
        }
        
        
    
    vector<int > ans(2,0);
    for(int i=0;i<nums.size();i++){
      //  cout<<nums[i];
        if(nums[i]!=i+1){
           ans[0]=nums[i];
            ans[1]=i+1;
        }
    }
    return ans;
    }
};