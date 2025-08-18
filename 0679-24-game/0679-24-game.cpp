class Solution {
public:

    double epsilon = 0.01; //taking the error margin.

    bool solve(vector<double> cards){

        //base condition

        if(cards.size() == 1){
            return abs(cards[0] - 24) <= epsilon;
        }

        for(int i = 0; i < cards.size(); i++){
            for(int j = 0; j < cards.size(); j++){
                
                if(i == j){
                    continue;
                }

                vector<double> temp;

                for(int k = 0; k < cards.size(); k++){
                    if(k != i && k != j){
                        temp.push_back(cards[k]); 
                        //storing the values other than 2 selected in temp.
                    }
                }

                double a = cards[i];
                double b = cards[j];

                vector<double> operations = {a+b , a*b , a-b, b-a};

                if(b > 0.0){
                    operations.push_back(a / b);  //checking if denominator != 0
                }

                if(a > 0.0){
                    operations.push_back(b / a); //checking if denominator != 0
                }



                //backtracking
                for(double val : operations){
                    temp.push_back(val);
                    if(solve(temp) == true) return true;
                    temp.pop_back();
                }
            }
        }


        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        int n = cards.size();

        vector<double> nums;

        for(int i = 0; i< n; i++){
            nums.push_back((double)cards[i]);
        }

        return solve(nums);
    }
};