class Solution {
public:
    bool canJump(vector<int>& arr) {
        int farthest = 0;
        for(int i=0; i<arr.size(); i++){
            if(i > farthest){
                return 0;
            }
            farthest = max(farthest , i+arr[i]);
        
        if(farthest >= arr.size()-1)
        return true;
        
           }     
               
              return true;
    }
};