
/* 
n -> size of chessbaord ( n x n matrix)
k - number of obstacles
(x,y) - queen's position 
2d vector obs - all the obstacle positions
*/



int queensAttack(int n, int k, int x, int y, vector<vector<int>> obs) {
    
    int attackcount = 0;
    int left = y - 1;
    int right= n - y;
    int up = n - x, down = x - 1;

    int upleft = min(up,left),upright = min(up,right);
    int  downleft = min(down,left),downright = min(down,right);
    
    for(int i = 0;i<obs.size();i++){

        if(x < obs[i][0] && y == obs[i][1]){
            up = min(up,obs[i][0] - x -1);
        }

        else if(x > obs[i][0] && y == obs[i][1]){
            down = min(down,x - obs[i][0] -1);
        }   

        else if(x == obs[i][0] && y > obs[i][1]){
            left = min(left,y-obs[i][1]-1);
        }

        else if(x == obs[i][0] && y < obs[i][1]){
            right = min(right,obs[i][1]-y-1);
        }

        else if(x < obs[i][0] && y > obs[i][1]){
            if(abs(x - obs[i][0]) == abs(y-obs[i][1])){
                upleft = min(upleft,obs[i][0]-x-1);
            }
        }

        else if(x < obs[i][0] && y < obs[i][1]){
            if(abs(x - obs[i][0]) == abs(y-obs[i][1])){
                upright = min(upright,obs[i][0]-x-1);
            }
        }
        else if(x > obs[i][0] && y > obs[i][1]){
            if(abs(x - obs[i][0]) == abs(y-obs[i][1])){
                downleft = min(downleft,y-obs[i][1]-1);
            }
        }

        else if(x > obs[i][0] && y < obs[i][1]){
            if(abs(x - obs[i][0]) == abs(y-obs[i][1])){
                downright = min(downright,obs[i][1]-y-1);
            }
        }
    }
    
    attackcount = (up + down + left + right + upleft + upright + downleft +  downright); 
    return attackcount;
}
