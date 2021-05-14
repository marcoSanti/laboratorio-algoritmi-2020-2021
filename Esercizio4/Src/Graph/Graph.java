package Src.Graph;
import java.util.HashMap;

public class Graph<T, G> {
    private HashMap<T, Link<T, G>> myHashTable;

    public Graph() {
        myHashTable = new HashMap<T, Link<T, G>>();
    }

    public void AddNode(T key) {
        myHashTable.put(key, new Link<T,G>(null, null, null));
    }

    public void AddLink(T from, T to, G weight) {
        myHashTable.put(from, new Link<T, G>(weight, to, myHashTable.get(from)));
    }
    /* 
     *  Returns true if node with the specified key exists, false otherwise 
     */
    public boolean HasNode(T key) {
        return myHashTable.containsKey(key);
    }
}