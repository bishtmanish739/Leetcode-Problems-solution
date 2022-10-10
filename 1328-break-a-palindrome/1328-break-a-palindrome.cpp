class Solution {
public:
    string breakPalindrome(string palindrome) {
        int i=0;
        int n=palindrome.length();
        if(n<=1){
            return "";
        }
        int count=0;
        while(i<n){
            if(palindrome[i]=='a'){
                count++;
            }
            i++;
        }
        if( count==n){
            palindrome[n-1]='b';
            return palindrome;
        }
       
        
        i=0;
        while(i<n && palindrome[i]=='a'){
            i++;
        }
       if(n%2 ==1 && count==n-1){
           palindrome[n-1]='b';
            return palindrome;
       }
        
        palindrome[i]='a';
        return palindrome;
    }
};