class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int p1 = 0; 

        for(int p2=0 ; p2< arr.size() ; p2++){

            if(arr[p2] != 0){
                
                swap(arr[p1],arr[p2]);
                p1++;
            }
        }
    }
    
        
};