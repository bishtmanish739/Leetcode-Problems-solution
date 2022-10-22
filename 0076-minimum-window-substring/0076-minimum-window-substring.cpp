class Solution {
public:
    string minWindow(string s, string t) {
        int matchcount=t.size();
        string ans="";
        unordered_map<char,int> tm;
        for(auto i:t){
            tm[i]++;
           // cout<<tm[i];
        }
         unordered_map<char,int> sm;
        int i=-1;
        int j=-1;
        int currmc=0;
        //cout<<matchcount<<endl;
       while(true){
           bool f1=true;
           bool f2=true;
           //accquire 
         // cout<<i<<" "<<s.length()<<endl;
           int n=s.length();
           while(i< n  && currmc<matchcount){
               i++;
               sm[s[i]]++;
              // cout<<s<<endl;
               if(tm.find(s[i])!=tm.end() && tm[s[i]]>=sm[s[i]]){
                   currmc++;
                   //cout<<currmc<<endl;
               }
               f1=false;
           }
           
           while(j<i && currmc==matchcount){
               string currs=s.substr(j+1, i-j);
              // cout<<currs<<endl;
               
               if(ans.length()==0 || currs.length()<ans.length()){
                   ans=currs;
               }
               j++;
               if(sm[s[j]]==1){
                   sm.erase(s[j]);
               }
               else{
                   sm[s[j]]--;
               }
               if(tm.find(s[j])!= tm.end() && tm[s[j]]> sm[s[j]]){
                currmc--;
               }
               f2=false;
               
           }
           if(f1 && f2){
           break; 
           }
           
           //release
       }
        return ans;
    }
};