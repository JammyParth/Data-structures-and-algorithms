class Solution {
public:
    int bestClosingTime(string customers) {
        //finding the best closing time by counting suffix values
        //if Y then add 1.
        //       Y  Y  N  Y
        //       1   1   0  1   closed   -> 3
        //       1   1   0   closed     -> 2
        //       1   1  closed 0      -> 2
        //       1    closed          -> 1
        //       3   2   1   1


        //prefix values
        //     0   1  2  3
        //      Y  Y  N  Y
        //      1  2  2  3
        //      3  2  1  1
    //total:    4  4  3  4
    //lowest total first value:  2nd index.

    //1 2 3 4 
    //1
    //5 5 5 5
    //if all values are same then close at nth time.
    int n = customers.size();
    vector<int> prefix(n , 0);
    vector<int> suffix(n , 0);
    int count = 0;
    if(customers[0] == 'N'){
        count++;
    }

    prefix[0] = count;
    for(int i = 1;i < n; i++){

        if(customers[i] == 'N'){
            count++;
        }

        prefix[i] = count;
    }

    count = 0;
    if(customers[n - 1] == 'Y'){
        count++;
    }
    suffix[n - 1] = count;

    for(int i = n - 2; i >= 0; i--){
        if(customers[i] == 'Y'){
            count++;
        }
        suffix[i] = count;
    }


    int mincost = suffix[0];
    int mincost_index = -1;


    for(int i = 0; i < n; i++){
        int cumcost = prefix[i] + (i + 1 < n ? suffix[i + 1] : 0);
        if(cumcost < mincost){
            mincost = cumcost;
            mincost_index = i;
        }
    }


    return mincost_index + 1;
    }
};



//YNYY
//1 1 2 3
// 3  2  2 1
//4  3  4  4

//