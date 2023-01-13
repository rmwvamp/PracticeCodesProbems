import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;
 
public class questioninjava{
   



//   static int findMinCharacters(String searchWord, String resultWord) {
//     int p = 0;
//     int q = 0;
//     while (p < searchWord.length()) {
//       if (searchWord.charAt(p) == resultWord.charAt(q)) {
//         q += 1;
//         if (q == resultWord.length()) {
//           return 0;
//         }
//       }
//       p += 1;
//     }
//     return (resultWord.length() - q);
//   }

  public static void main(String[] args) throws Exception {
    Scanner sc = new Scanner( System.in);
    long b = sc.nextLong();
    b--;
    long a=2;
    long mod=1000000007L;
    long res=1;
    while (b>0){
        if ((b&1)== 1){
            res= (res * a % mod)%mod;
        }
        a=(a%mod * a%mod)%mod;
        b=b>>1;
    }
    System.out.println(res);
  
}

static void dfs (ArrayList<Integer> graph[], int node, int k,Map<Integer,Integer> map, ArrayList<Integer> path){
        path.add(node);
        if (graph[node].size()==0){
            if (path.size()>k){
                map.put(path.get(path.size()-k-1),0);
            }
        }
        else {
            for (int y: graph[node]) dfs(graph,y,k,map,path);
        }
        path.remove(path.size()-1);
    }
    public static int countMaxOperations(String s, String t) {
        int sLength = s.length();
        Map<Character, Integer> freqS = new HashMap<>();

        for (int i = 0; i < sLength; i++) {
            char current = s.charAt(i);

            int count = freqS.getOrDefault(current, 0);
            freqS.put(current, count + 1);
        }

        int tLength = t.length();
        Map<Character, Integer> freqT = new HashMap<>();

        for (int i = 0; i < tLength; i++) {
            char current = t.charAt(i);

            int count = freqT.getOrDefault(current, 0);
            freqT.put(current, count + 1);
        }

        int result = Integer.MAX_VALUE;

        for (char key : freqT.keySet()) {
            int currentCount = freqS.getOrDefault(key, 0);
            int requiredCount = freqT.get(key);

            result = Math.min(result, currentCount / requiredCount);
        }

        return result == Integer.MAX_VALUE ? -1 : result;
    }


    public static void main(String[] args) {
 
        FastScanner sc=new FastScanner();
//      hamare saath shree raghunath to kis baat ki chinta...
     

        String s=sc.toString();
        String t=sc.toString();
        int res=countMaxOperations(s, t);
        System.out.println(res);

 
        // for (int tt=1; tt<=T; tt++){
        //     int n = sc.nextInt();
        //     int ans []= new int [n+1];
        //     boolean done []= new boolean [n+1];
        //     int ranges[][]= new int [n+1][2];
        //     Pair arr[]= new Pair[n];
        //     for (int i=1; i<=n; i++){
        //         int x = sc.nextInt();
        //         if (x==0){
        //             ranges[i][0]=i+1;
        //             ranges[i][1]=n;
        //             arr[i-1]= new Pair(i,ranges[i][1]-ranges[i][0]+1, ranges[i][0]);
        //         }
        //         else {
        //             ranges[i][0]=i/(x+1)+1;
        //             ranges[i][1]=i/x;
        //             arr[i-1]= new Pair(i,ranges[i][1]-ranges[i][0]+1,ranges[i][0]);
        //         }
        //     }
        //     Arrays.sort(arr);
        //     dfs(0,arr,done,ans,ranges,1);
        //     StringBuilder sb= new StringBuilder();
        //     for (int i=1; i<=n; i++){
        //         sb.append(ans[i]+" ");
        //     }
        //     System.out.println(sb.toString());
        // }
    }
    static void dfs(int in, Pair arr[], boolean done[], int ans[], int ranges[][], int i){
        if (in==arr.length) return;
        int str=arr[in].x;
        ans[str]=i;
        dfs(in+1,arr,done,ans,ranges,i+1);
    }
    static boolean fn = false;
    static class SegmentTree{
        int nodes[];
        int arr[];
        int lazy[];
        public SegmentTree(int n, int arr[]){
            nodes = new int [4*n+1];
            lazy= new int [4*n+1];
            this.arr=arr;
            build(1,1,n);
        }
        private void build (int v, int l , int r){
            if (l==r) {
                nodes[v]=arr[l-1];}
            else {
                int m=(l+r)/2;
                build(2*v,l,m);
                build(2*v+1,m+1,r);
                nodes[v]=Math.min(nodes[2*v], nodes[2*v+1]);
            }
        }
        private void push(int v) {
            nodes[v*2] += lazy[v];
            lazy[v*2] += lazy[v];
            nodes[v*2+1] += lazy[v];
            lazy[v*2+1] += lazy[v];
            lazy[v] = 0;
        }
        private void update(int v, int l, int r, int x, int y, int add) {
            if (l>y || r<x) return;
            if (l>=x && y>=r) {
                nodes[v]+=add;
                lazy[v]+=add;
            }
            else {
                push(v);
                int mid =(l+r)/2;
                update(2*v,l,mid,x,y,add);
                update(2*v+1,mid+1,r,x,y,add);
                nodes[v]=Math.min(nodes[v*2], nodes[v*2+1]);
            }
        }
        private int query(int v, int l, int r, int x, int y){
            if (l>y || r<x) return Integer.MAX_VALUE;
            if (l>=x && r<=y) return nodes[v];
            else {
                int m = (l+r)/2;
                push(v);
                return Math.min(query(2*v+1,m+1,r,x,y),query(2*v,l,m,x,y));
            }
        }
    }
 
    static class LPair{
        long x,y;
        LPair(long x , long y){
            this.x=x;
            this.y=y;
        }
    }
    static long prime(long n){
        for (long i=3; i*i<=n; i+=2){
            if (n%i==0) return i;
        }
        return -1;
    }
    static long factorial (int x){
        if (x==0) return 1;
        long ans =x;
        for (int i=x-1; i>=1; i--){
            ans*=i;
            ans%=mod;
        }
        return ans;
    }
    static boolean killMePls = false;
//    public static void main(String[] args) throws Exception {
//        Thread.UncaughtExceptionHandler h = new Thread.UncaughtExceptionHandler() {
//            public void uncaughtException(Thread t, Throwable e) {killMePls = true;}
//        };
//        Thread t = new Thread(null, ()->A(args), "", 1<<28);
//        t.setUncaughtExceptionHandler(h);
//        t.start();
//        t.join();
//        if(killMePls) throw null;
//    }
    static long mod =1000000007L;
    static long power2 (long a, long b){
        long res=1;
        while (b>0){
            if ((b&1)== 1){
                res= (res * a % mod)%mod;
            }
            a=(a%mod * a%mod)%mod;
            b=b>>1;
        }
        return res;
    }
 
    static boolean []sieveOfEratosthenes(int n){
        boolean prime[] = new boolean[n+1];
        for(int i=0;i<=n;i++)
            prime[i] = true;
 
        for(int p = 2; p*p <=n; p++)
        {
            if(prime[p] == true)
            {
                for(int i = p*p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        return prime;
    }
    static void sort(int[] a){
        ArrayList<Integer> l=new ArrayList<>();
        for (int i:a) l.add(i);
        Collections.sort(l);
        for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }
    static void sortLong(long[] a){
        ArrayList<Long> l=new ArrayList<>();
        for (long i:a) l.add(i);
        Collections.sort(l);
        for (int i=0; i<a.length; i++) a[i]=l.get(i);
    }
    static long gcd (long n, long m){
        if (m==0) return n;
        else return gcd(m, n%m);
    }
 
    static class Pair implements Comparable<Pair>{
        int x,y,z;
        private static final int hashMultiplier = BigInteger.valueOf(new Random().nextInt(1000) + 100).nextProbablePrime().intValue();
        public Pair(int x, int y, int z){
            this.x = x;
            this.y = y;
            this.z=z;
        }
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
 
            Pair pii = (Pair) o;
 
            if (x != pii.x) return false;
            return y == pii.y;
        }
        public int hashCode() {
            return hashMultiplier * x + y;
        }
        public int compareTo(Pair o){
//            if (this.x==o.x) return Integer.compare(this.y,o.y);
//            else return Integer.compare(this.x,o.x);
            if (this.z==o.z)  return Integer.compare(this.y,o.y);
            else return Integer.compare(this.z,o.z);
        }
        // this.x-o.x is ascending
    }
    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }
        long nextLong() {
            return Long.parseLong(next());
        }
    }
}


public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            int k = sc.nextInt();
            ArrayList<Integer> graph[]= new ArrayList[n+1];
            for (int i=1; i<=n; i++) graph[i]=new ArrayList<>();
            for (int i=0; i<n-1; i++) {
                int x= sc.nextInt();
                int y = sc.nextInt();
                graph[x].add(y);
            }
            Map<Integer, Integer> map= new HashMap<>();
            ArrayList<Integer> path= new ArrayList<>();
            dfs(graph,1,k,map,path);
            ArrayList<Integer> ans= new ArrayList<>();
            for (int x: map.keySet()) ans.add(x);
            Collections.sort(ans);
            for (int y: ans){
                System.out.print(y+" ");
            }
}
static void dfs (ArrayList<Integer> graph[], int node, int k,Map<Integer,Integer> map, ArrayList<Integer> path){
    path.add(node);
    if (graph[node].size()==0){
        if (path.size()>k){
            map.put(path.get(path.size()-k-1),0);
        }
    }
    else {
        for (int y: graph[node]) dfs(graph,y,k,map,path);
    }
    path.remove(path.size()-1);
}



