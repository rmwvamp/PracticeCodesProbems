import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.Iterable;
import java.math.BigInteger;
import java.util.*;

public class qjava {

  public static boolean check(String input) {
    if (input == null || input.isEmpty()) {
      return true;
    }

    Stack<Character> stack = new Stack<>();
    for (int i = 0; i < input.length(); i++) {
      char current = input.charAt(i);

      // for (char current: input) {

      if (current == '(' || current == '[') {
        stack.push(current);
      } else if (current == ')' || current == ']') {
        if (stack.isEmpty()) return false;

        char lastChar = stack.peek();

        if (
          (current == ')' && lastChar != '(') ||
          (current == ']' && lastChar != '[')
        ) {
          return false;
          // return true;

        }

        stack.pop();
      }
    }

    return stack.isEmpty();
    // return true;

  }

  public static void main(String[] args) {
    // // String input="()[](hello)[]()";
    // // if(check("()[](hello)[]()"))
    // // if(check("(1[2(3)4]5)"))
    // if((!check("([)]")))
    // {
    //     System.out.println("YES");
    // }
    // else
    // {
    //     System.out.println("NO");
    // }
    // // if(check('(1[2(3)4]5)');
    // // // String s1="([)]";
    // // if(!check('([)]');

    byte a = 127;

    byte b = ++a;

    System.out.println(b);
  }
  //     public static void main(String[] args) throws FileNotFoundException {
  //         Scanner sc= new Scanner(System.in);
  // //        int T=sc.nextInt();
  //         int T=1;
  //         for (int tt=1; tt<=T; tt++){
  //             int n = sc.nextInt();
  //             int q = sc.nextInt();
  //             Pair arr[]= new Pair[n];
  //             for (int i=0; i<n; i++) arr[i]=new Pair(sc.nextLong(), sc.nextLong());
  //             Arrays.sort(arr);
  //             StringBuilder sb= new StringBuilder();
  //             for (int i=0; i<q; i++){
  //                 int ans =0;
  //                 long x= sc.nextLong();
  //                 long y= sc.nextLong();
  //                 long z= sc.nextLong();
  //                 int xx= bs(arr,(int)x);
  //                 for (int j=xx; j<n; j++){
  //                     if (arr[j].x>x+z) break;
  //                     else {
  //                         ans+=isInside(x,y,x+z,y,x,y+z,arr[j].x, arr[j].y );
  //                     }
  //                 }
  //                 sb.append(ans+"\n");
  //             }
  //             System.out.print(sb);
  //         }
  //     }
  //     static int bs (Pair arr[], int tar){
  //         int ans =arr.length;
  //         int lo=0;
  //         int hi=arr.length-1;
  //         while (lo<=hi){
  //             int mid=(lo+hi)/2;
  //             if (arr[mid].x>=tar){
  //                 ans=mid;
  //                 hi=mid-1;
  //             }
  //             else lo=mid+1;
  //         }
  //         return ans;
  //     }
  //     static long area(long x1, long y1, long x2, long y2,
  //                        long x3, long y3)
  //     {
  //         return Math.abs((x1*(y2-y3) + x2*(y3-y1)+
  //                 x3*(y1-y2)));
  //     }
  //     static class Pair implements Comparable<Pair>{
  //         long x, y;
  //         private static final int hashMultiplier = BigInteger.valueOf(new Random().nextInt(1000) + 100).nextProbablePrime().intValue();
  //         public Pair(long x, long y){
  //             this.x = x;
  //             this.y = y;
  //         }
  //         public boolean equals(Object o) {
  //             if (this == o) return true;
  //             if (o == null || getClass() != o.getClass()) return false;

  //             CF1.Pair pii = (CF1.Pair) o;

  //             if (x != pii.x) return false;
  //             return y == pii.y;
  //         }
  //     //    public int hashCode() {
  //     //        return hashMultiplier * x + y;
  //     //    }
  //         public int compareTo(Pair o){
  //             if (this.x==o.x) return Long.compare(this.y,o.y);
  //             else return Long.compare(this.x,o.x);
  //         }
  //         // this.x-o.x is ascending
  //     }
  //     static int isInside(long x1, long y1, long x2,
  //                             long y2, long x3, long y3, long x, long y)
  //     {
  //         long A = area (x1, y1, x2, y2, x3, y3);
  //         long A1 = area (x, y, x2, y2, x3, y3);
  //         long A2 = area (x1, y1, x, y, x3, y3);
  //         long A3 = area (x1, y1, x2, y2, x, y);
  //         if (A == A1 + A2 + A3) return 1;
  //         else return 0;
  //     }
}
