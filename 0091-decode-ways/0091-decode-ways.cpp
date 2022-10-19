class Solution {
public:
        long long int dp[1000]={0};
        long long int numDecodings1(string s,int index) {
        if( s.length() ==index ){
            return 1;
        }
            
        if(s[index]=='0' ){
            return 0;
        }
        if(s.length()-1==index ){
            return 1;
        }
    
        if(dp[index]!=-1){
            return dp[index];
        }
      
       long long int way1=numDecodings1(s,index+1);
        string k=s.substr(index,2);
       //  cout<<index <<" "<<index +1<<"->"<<k<<endl;
        
            long long int way2=0;
       
        
      long long int l= stoi(k);
        if(l<=26){
           // cout<<"djflsakj" <<endl;
           way2= numDecodings1(s,index+2);
        }
        return  dp[index]=way1+way2;
        
    }
    int numDecodings(string s) {
       for(int i=0;i<1000;i++){
           
               dp[i]=-1;
           
       }
        
    
        int k= numDecodings1(s,0)  ;
       
        return k;
        
    }
};