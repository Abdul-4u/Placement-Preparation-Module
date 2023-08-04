class StockSpanner {
public:
// first value of pair=array element
// second value of pair=index of array element
// there is no need to store elements in array
stack<pair<int,int>>s;
int i=-1;
    StockSpanner() {
        
    }
    int next(int p) {
        int ans;
           // stack is empty
           // hence no smaller element
           if(s.empty())ans = -1;

           // if condition is true
           // then we find the NGE of given price
           else if(s.top().first>p){
               ans = s.top().second;
           }
           else{

               // pop the element till NGE of price
               while(!s.empty() && s.top().first<=p)s.pop();

               if(s.empty())ans = -1;
               else ans = s.top().second;
           }
           s.push({p,++i});

       // difference of INDEX of price and INDEX of NGE
       return i-ans;
    }
};