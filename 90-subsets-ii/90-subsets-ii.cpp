class Solution {
public:
    set<vector<int> > v;
     vector<vector<int>> ans;
    void subsets(vector<int>& nums,vector<int> output,vector<vector<int>> &ans,int n){
       if(n<0){
           if(v.find(output)==v.end()){
               ans.push_back(output);
               v.insert(output);
           }
           
           return ;
       }
        subsets(nums,output,ans,n-1);
       output.push_back(nums[n]);
       subsets(nums,output,ans,n-1);
      
       return ;
       
   }
    vector<vector<int>> subsets(vector<int>& nums) {
      
        int n=nums.size()-1;
        vector<int> output;
        subsets(nums,output,ans,n);
        return ans;
        
    }
    void solve(vector<int> &nums,int start,int n,vector<int> &curr){
     ans.push_back(curr);
        for(int i=start;i<n;i++){
            if(i>start && nums[i-1]==nums[i]){
                continue;
            }
             curr.push_back(nums[i]);
            solve(nums,i+1,n,curr);
            curr.pop_back();
            
           
        }
        
        return ;
        
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>  curr;
        solve(nums,0,n,curr);
        return ans;
       return  subsets(nums);
       
    }
};