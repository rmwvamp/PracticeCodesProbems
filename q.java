static String fn(String x){
        Map<Character, Character> map= new HashMap<>();
        map.put('A','T');
        map.put('T','A');
        map.put('G','C');
        map.put('C','G');
        StringBuilder sb= new StringBuilder();
        for (int i= x.length()-1; i>=0; i--) sb.append(map.get(x.charAt(i)));
        return sb.toString();
    }