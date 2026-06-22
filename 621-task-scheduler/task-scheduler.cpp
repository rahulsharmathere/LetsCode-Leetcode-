class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // array of CPU tasks ["A","A","A","B","B"]
        // n is the coolout time
        // an interval can be idle or complete one task
        //::: A gap of at least 'n' intervals between two tasks with same label is necessary

        //return min no. of CPU intervals to complete all tasks

        int m=tasks.size();
        vector<int>map(26,0);//freq
        for(auto it:tasks){
            map[it-'A']++;
        }
        priority_queue<int>pq;//frequency of each character
        for(int i=0;i<map.size();i++){
            if(map[i]>0){
                pq.push(map[i]);
            }
        }

        int time=0;
        while(!pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){

                    int freq=pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);

                }
            }
            for(int f:temp){
                if(f>0){
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time+=temp.size();
            }
            else{
                time+=n+1;
            }
        }        
        return time;



    }
};