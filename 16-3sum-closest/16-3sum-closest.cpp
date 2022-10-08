class Solution {
public:
   
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int ans=INT_MAX-100000;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=  nums[i]+nums[j]+nums[k];
               // cout<<sum<<endl;
                if(sum==target){
                    return target;
                    
                }
                if(sum>target){
                    if(abs(ans-target)>abs(sum-target)){
                        ans=sum;
                    }
                    k--;
                }
                else{
                    if(abs(ans-target)>abs(sum-target)){
                        ans=sum;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};