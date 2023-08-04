class LFUCache {
public:
     int capacity ;
     int minFreq; 
     unordered_map<int,pair<int,int>>keyVal;
     unordered_map<int,list<int>>freqList;
     unordered_map<int,list<int>::iterator>pos;
      
      void updateFreq(int key){
          // find the curr freq : 

          int curr_freq = keyVal[key].second;

          // as now the key will shift to a new freq 

          freqList[curr_freq].erase(pos[key]);
          // incremenet the useAge freq of the key 
          keyVal[key].second++;

          // add the key to the new freq list 
          freqList[curr_freq + 1].push_back(key);
           // update the iterator val 
          pos[key] = -- freqList[curr_freq + 1].end();
            
           // update the minFreq 
           if(freqList[minFreq].empty()) minFreq++;

      }


    LFUCache(int capacity) {
     this->capacity = capacity;
     minFreq = 0;   
    }
    
    int get(int key) {
        // if not found in the keyVal return  -1 
        if(keyVal.find(key)==keyVal.end())
        {
            return -1;
        }
         
         // update the freq 
         updateFreq(key);

         // return the value 

         return keyVal[key].first;

    }
    
    void put(int key, int value) {
        // boundary case check if capacity  == 0 
        if(capacity == 0) return;

        // if key is found then we updte it with new val and we perform the same logic of updates as we 
        //  did with the GET call 

        if(keyVal.find(key)!=keyVal.end()){
             keyVal[key].first = value;
             updateFreq(key);
             return;
        }


        // deletion  case when the cache is full 
        if(keyVal.size() == capacity){
             
             // find the least freqUsed Key : first element in the list of minFreq 

              int delKey = freqList[minFreq].front();

              // erase it from keyval 
              keyVal.erase(delKey);
              // erase it from pos 
              pos.erase(delKey);

              // remove it from FreqList 
              freqList[minFreq].pop_front();
        }

        // creation part 

        keyVal[key] = {value , 1};

        freqList[1].push_back(key);

        pos[key] = --freqList[1].end();

        minFreq = 1;

    }
};
