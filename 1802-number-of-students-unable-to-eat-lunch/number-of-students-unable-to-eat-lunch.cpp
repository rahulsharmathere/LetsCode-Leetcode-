class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();//same for sandwich
        //0 or 1
        int ind=0;//sandwich index
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(students[i]);
        }
        int done=0;
        while(!q.empty()){
            int need=q.front();
            int have=sandwiches[ind];
            if(need==have){
                q.pop();
                ind++;
                done=0;
            }else{
                q.pop();
                q.push(need);
                done++;
            }
            if(done==q.size())break;
        }
        return q.size();
    }
};