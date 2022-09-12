//https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
public class Solution {
    public int[] MinOperations(string boxes) {
        //the number of operations is equal to the some of: length-1 minus each ball's index
        
        //int[] balls = boxes.ToCharArray();
        int[] balls = new int[boxes.Length];
        
        for(int b = 0; b < balls.Length; b++)
        {
            int totalMoves = 0;
            for(int i = 0; i < balls.Length; i++ )
            {
                //if(balls[i] == 1)
                if(boxes[i] == '1')
                {
                    totalMoves += Math.Abs(b-i);
                    //balls[i] = 1;
                }
                /*else
                {
                    balls[i] = 0;
                }*/
            }

            balls[b] = totalMoves;
        }
        
        return balls;
    }
}