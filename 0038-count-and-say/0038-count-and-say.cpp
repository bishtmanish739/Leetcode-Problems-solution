class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string p=countAndSay(n-1);
        string ans="";
        int i=0;
        while(i<p.length()){
            char c=p[i];
            int count=0;
            while(i<p.length() && p[i]==c){
                count++;
                i++;
            }
            if(i==p.length() || p[i]!=c){
                ans+=to_string(count);
                ans+=c;
                
            }
        }
        return ans;
        
    }
};