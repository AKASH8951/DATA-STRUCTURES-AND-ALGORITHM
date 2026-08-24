class Car {
public:
    int idx;
    int distSq;

    Car(int idx , int distSq) {
        this -> idx = idx;
        this -> distSq = distSq;
    }

    bool operator < (const Car &obj) const {
        return this -> distSq > obj.distSq;
    }
};
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector <Car> cars;

        // Calculate distance of every point
        for(int i = 0 ; i < points.size() ; i++) {
            int x = points[i][0];
            int y = points[i][1];

            int distSq = x * x + y * y;

            cars.push_back(Car(i , distSq));
        }

        // Build min heap
        priority_queue<Car> pq(cars.begin() , cars.end());

        vector <vector<int>> ans;

        // Get k closest points
        for(int i = 0 ; i <k ; i++) {
            int idx = pq.top().idx;

            ans.push_back(points[idx]);

            pq.pop();
        }

        return ans;
    }
};