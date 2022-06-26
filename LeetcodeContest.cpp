for (int tt=1; tt<=T; tt++){
            int n = sc.nextInt();
            int l = sc.nextInt();
            ArrayList<Integer> right = new ArrayList<>();
            ArrayList<Integer> left= new ArrayList<>();
            ArrayList<Pair> arr= new ArrayList<>();
            for (int i=1; i<=n; i++){
                arr.add(new Pair(sc.nextInt(), i));
                int dir= sc.nextInt();
                if (dir==0){
                    left.add(arr.get(i-1).x-0);
                }
                else {
                    right.add(l-arr.get(i-1).x);
                }
            }
            Collections.sort(arr);
            Collections.sort(left);
            Collections.sort(right);
            for (int i=0; i<left.size(); i++){
                arr.get(i).x= left.get(i);
            }
            for (int j=0; j<right.size(); j++){
                arr.get(n-1-j).x=right.get(j);
            }
            int i=0;
            int j=n-1;
            StringBuilder sb= new StringBuilder();
            while (i<=j){
                if (arr.get(i).x<arr.get(j).x){
                    sb.append(arr.get(i).y+" ");
                    i++;
                }
                else if (arr.get(i).x>arr.get(j).x){
                    sb.append(arr.get(j).y+" ");
                    j--;
                }
                else {
                    if (arr.get(i).y<=arr.get(j).y){
                        sb.append(arr.get(i).y+" ");
                        i++;
                    }
                    else {
                        sb.append(arr.get(j).y+" ");
                        j--;
                    }
                }
            }
            System.out.println("Case #"+tt+": "+ sb.toString());