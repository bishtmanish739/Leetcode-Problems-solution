class Solution {
public:
      vector<vector<int>> ans;
  
    void solve(vector<int>& candidates, int target,int start,int n,vector<int> &curr){
        if(target==0){
           
            ans.push_back(curr);
          
            
            return ;
        }
        for(int i=start;i<n;i++){
            if(candidates[i]>target){
                return ;
            }
            if(i>start && candidates[i]==candidates[i-1]){
                continue;
            }
            curr.push_back(candidates[i]);
            solve(candidates,target-candidates[i],i+1,n,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>curr;
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
       
        solve(candidates,target,0,n,curr);
        
        return ans;
    }
};