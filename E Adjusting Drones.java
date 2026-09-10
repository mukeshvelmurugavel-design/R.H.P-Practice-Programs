import java.util.*;
public class Main {
    public static void main(String[] args) {
      Scanner sc=new Scanner(System.in);
      int n=sc.nextInt();
      
      while(n-- >0){
      
      int N=sc.nextInt();
      int k=sc.nextInt();
      int[] cnt=new int[N+N+N+1];
      for(int i=0;i<N;i++){
        int curr=sc.nextInt();
        cnt[curr]++;
        
      }
      int ans=Integer.MIN_VALUE;
      for(int val=1;val<=N+N;val++){
        int curr=val;
        while(cnt[curr]>k){
          cnt[curr+1]+=cnt[curr]-1;
          cnt[curr]=1;
          curr++;
        }
        int c=curr-val;
        ans=Math.max(ans,c);
      }
       System.out.println(ans); 
      }
    }
}