class Solution {
public:
    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
            return true;
        else
            return false;
    }
    int solveTab(int n, vector<vector<int>>& a) {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for(int curr = n - 1; curr >= 0; curr--){
            for(int prev = curr - 1; prev >= -1; prev--){
                // include
                int take = 0;
                if (prev == -1 || check(a[curr], a[prev]))
                    take = a[curr][2] + nextRow[curr + 1];

                // exclude
                int notTake = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(take, notTake);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    int maxHeight(vector<vector<int>>& cuboids) {
        // step1: sort all dimensions for every cuboid

        for(auto &a : cuboids){
            sort(a.begin(), a.end());
        }

        // step2: sort all cuboids basis on w or l
        sort(cuboids.begin(), cuboids.end());

        // step3: use LIS Logic
        return solveTab(cuboids.size(), cuboids);
    }
};

// 1304