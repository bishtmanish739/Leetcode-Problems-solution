class MyCalendarThree {
public:
    map<int,int> m;
    int maxx=0;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        if(m.find(start)!=m.end()){
            m[start]++;
        }
        else{
            m[start]=1;
        }
         if(m.find(end)!=m.end()){
            m[end]--;
        }
        else{
            m[end]=-1;
        }
        
        int count=0;
        for(auto i:m){
            count+=(i.second);
            maxx=max(count,maxx);
        }
        
        return maxx;
        
    }
    
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */