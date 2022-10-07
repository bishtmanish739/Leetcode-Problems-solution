class Solution {
public:
   vector<vector<int> > ans;
    void solve(int idx,vector<int> &curr,int k,int n){
        if(curr.size()==k){
            ans.push_back(curr);
            return ;
        }
        
        for(int i=idx;i<=n;i++){
            curr.push_back(i);
            solve(i+1,curr,k,n);
            curr.pop_back();
        }
    }
  void subsets(int n,int k,vector<int>& curr){
    
      if(curr.size()==k){
          ans.push_back(curr);
          return ;
      }
        if(n<=0){
          return ;
      }
       curr.push_back(n);
      subsets(n-1,k,curr);
      curr.pop_back();
      subsets(n-1,k,curr);
     
      return ;
      
  }
    vector<vector<int>> combine(int n, int k) {
       vector<int>current;
       // solve(1,current,k,n);
        subsets(n,k,current);
        return ans;
    }
};