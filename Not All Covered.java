public class Not_All_Covered {
    public static void main(String[] args) {
       Scanner obj=new Scanner(System.in);
       int n=obj.nextInt();
       int m=obj.nextInt();
       int arr[]=new int[n+2];
       while(m-->0){
           int p=obj.nextInt();
           int q=obj.nextInt();
           arr[p]++;
           arr[q+1]--;
       }
       int min=200005;
       for(int i=1;i<=n;i++){
           arr[i]+=arr[i-1];
           min=Math.min(arr[i],min);
           
       }
       System.out.println(min);
    
}
}