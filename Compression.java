import java.util.*;
public class Compression {
    public static void main(String args[]){
    Scanner obj=new Scanner(System.in);
    Set<Integer> set=new TreeSet<>();
    int n=obj.nextInt();
    for(int i=0;i<n;i++){
      set.add(obj.nextInt());
    }
    System.out.println(set.size());
    for(int i:set){
      System.out.print(i+" ");
    }
  }

}