import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
    public static void FindSubSequence(char[] arr)
    {
        int dp[][]=new int[600][600];
        int n=arr.length;
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        
        for(int sublen=2;sublen<=n;sublen++)
        {
            for(int i=0;i<n-sublen+1;i++)
            {
                int j=i+sublen-1;
                if(arr[i]==arr[j]& sublen==2)
                    dp[i][j]=2;
                else if(arr[i]==arr[j])
                {
                    dp[i][j]=2+Math.max(dp[i][j-1],dp[i+1][j]);
                }
                else
                     dp[i][j]=Math.max(dp[i][j-1],dp[i+1][j]);
                
            }
        }
       System.out.println(dp[0][n-1]);
    }
    
    
    
    
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		String chaska=sc.nextLine();
		char[] arr=chaska.toCharArray();
		FindSubSequence(arr);
	}
}
