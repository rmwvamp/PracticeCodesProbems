import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class code {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long b = sc.nextLong();
    if ((b & 1) == 1) b++;
    b /= 2;
    long a = 2;
    long mod = 1000000007L;
    long res = 1;
    while (b > 0) {
      if ((b & 1) == 1) {
        res = (res * a % mod) % mod;
      }
      a = (a % mod * a % mod) % mod;
      b = b >> 1;
    }
    System.out.println(res);
  }
}
