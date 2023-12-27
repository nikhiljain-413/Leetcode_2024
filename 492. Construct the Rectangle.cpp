class Solution {
public:
    vector<int> constructRectangle(int area) {
        // int diff = INT_MAX;
        int num1,num2;
        for(int i=1;i<=sqrt(area);i++){
            if(area%i==0){
                num2 = i;
                num1 = area/i;
            }
        }
        return {num1, num2};
    }
};