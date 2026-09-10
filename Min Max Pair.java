import java.util.*;
 
public class Main {
    public static void main(String args[]){
        Scanner obj=new Scanner(System.in);
        int n=obj.nextInt();
        int arr[]=new int[n+1];
        int a=0,b=0;
        for(int i=1;i<=n;i++){
            arr[i]=obj.nextInt();
            
        }
        for(int i=1;i<=n;i++){
            if(i==arr[i]) a++;
            else if(i==arr[arr[i]]) b++;
            
        }
        System.out.println((b/2)+(1L*a*(a-1))/2);
        
    }
    
}
