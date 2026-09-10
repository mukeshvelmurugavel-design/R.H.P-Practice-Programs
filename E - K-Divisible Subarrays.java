import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		int N=sc.nextInt();
		int K=sc.nextInt();
		Map<Integer,Integer> map=new HashMap<>();
		int dp[]=new int[N+1];
		map.put(0, 0);
		int rem=0;
		for(int i=1;i<=N;i++) {
			int curr=sc.nextInt();
			rem=(rem+curr)%K;
			if(map.containsKey(rem)) {
				dp[i]=Math.max(dp[i-1],dp[map.get(rem)]+1);
			}
			else {
				dp[i]=dp[i-1];
			}
			map.put(rem, i);
		}
		System.out.println(dp[N]);
	}
}
