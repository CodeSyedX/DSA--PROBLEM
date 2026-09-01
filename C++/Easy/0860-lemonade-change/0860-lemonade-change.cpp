class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int ten = 0;
        int five = 0 ;
        for( int i =0 ; i < n ;  i++){
            if(bills[i] == 5){
                five++;
            }
            else if(bills[i] == 10){
                if(five >= 1){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                  if(ten >= 1 && five >= 1){
                      ten--;
                      five--;
                }
                else if(five >= 3){
                    five = five-3;
                }
              
                else{
                    return false;
                }
            }
        }
        return true;
    }
};