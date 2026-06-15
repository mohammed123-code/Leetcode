class Solution {
    public int[] asteroidCollision(int[] asteroids) 
    {
         Stack<Integer>st= new Stack<>();

         for( int i=0;i<asteroids.length;i++)
         {
            // postive guy just push it inside the stack
            if( asteroids[i]>0)
            {
                st.push( asteroids[i]);
            }
            else   // negative guy
            {
                // remove the smaller psotives from top of stack
                // that are lesser in magnitude compared to the negative guy
                while(  st.size()>0 && st.peek()>0 
                       &&  st.peek()< Math.abs(asteroids[i]) )
                {
                    st.pop();
                }

                // current negative asteroid will be pushed when stack is empty or
                // it has a negative element at top
                if( st.size()==0 || st.peek()<0 )
                    st.push( asteroids[i]);

                // current element is neagtive and top is  postive and same magnitude
                if( st.size()>0 && st.peek()== Math.abs(asteroids[i]))
                    st.pop();    // pop out the postive top
            }
         }

         int n= st.size();
         int ans[]= new int[n];
         int i= n-1;
         while(st.size()>0)
         {
            ans[i]= st.pop();
            i--;
         }
        return ans;
    }
}