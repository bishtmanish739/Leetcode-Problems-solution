
class cmp {
public:
    bool operator() (pair<int,string >& p1, pair<int,string > &p2) {
        //cout<<p1.second<<" "<<p1.first<<endl<<p2.second<<" "<<p2.first<<endl;
         if(p1.first> p2.first){
             
            return false;
        }
        else if(p1.first< p2.first){
            return true;
        }
        
        if(p1.first==p2.first){
            string s1=p1.second;
            string s2=p2.second;
            vector<string> v;
            v.push_back(s1);
            v.push_back(s2);
            sort(v.begin(),v.end());
            if(v[0]==p1.second){
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
     
     
    static bool cmpt(pair<int,string > &p1, pair<int,string >& p2 ){
        if(p1.first> p2.first){
            return true;
        }
        if(p1.first==p2.first){
            string s1=p1.second;
            string s2=p2.second;
            vector<string> v;
            v.push_back(s1);
            v.push_back(s2);
            sort(v.begin(),v.end());
            if(v[0]==p1.second){
                return true;
            }
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
          map<string,int> m;
        for(int i=0;i<words.size();i++){
            m[words[i]]++;
        }
        priority_queue<pair<int,string >,vector<pair<int,string>>,cmp > pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        vector<string  > ans;
        
        while(pq.size()>0 && k>0){
           
            int f=pq.top().first;
           ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
       // sort(ans.begin(),ans.end());
        return ans;
        
    }
};