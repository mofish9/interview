import java.util.*;

public class HeadToTail {

    public static Vector<String> buildGraph(String word, HashSet<String> dic) {
        char[] chars = word.toCharArray();
        Vector<String> res = new Vector<String>();
        for(int i = 0; i < word.length(); i++) {
            for(char j = 'a'; j != 'z'; j++) {
                chars[i] = j;
                String t = new String(chars);
                if(dic.contains(t) && !res.contains(t) && !t.equals(word)) {
                    res.add(t);
                }
                chars[i] = word.charAt(i);
            }
        }
        return res;
    }
    
    public static void getFromHeadToTail(String head, String tail, HashSet<String> dic) {
        if(head.length() != tail.length())
            return;

        List<String> paths = new LinkedList<String>();
        Map<String, String> prev = new HashMap<String, String>();
        Queue<String> q = new LinkedList<String>();
        q.add(head);
        Vector<String> r = new Vector<String>();
        r.add(head);
        String w = null;
        while(q.size() != 0) {
            w = q.peek();
            q.poll();
            if(w == tail) {
                break;
            } 
            Vector<String> v = buildGraph(w, dic);
            for(String s : v) {
                if(!r.contains(s)) {
                    q.add(s);
                    r.add(s);
                    prev.put(s, w);
                }
            }
        }
        if(!w.equals(tail)) {
            System.out.println("can't reach the end!");
            return;
        }
        for(String s = tail; s != null; s = prev.get(s))
            paths.add(s);
        Collections.reverse(paths);
        for(String s : paths)
            System.out.println(s);
    }

    public static void main(String[] args) {
        HashSet<String> s = new HashSet<String>();
        s.add("catt");
        s.add("capt");
        s.add("cast");
        s.add("cats");
        s.add("cata");
        s.add("cbpt");
        s.add("catc");
        s.add("catd");
        s.add("cadd");
        s.add("cats");
        s.add("datd");
        s.add("abpt");
        getFromHeadToTail("catt", "abpt", s);
    }
}
