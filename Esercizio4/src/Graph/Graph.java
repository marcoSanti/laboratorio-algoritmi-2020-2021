package src.Graph;
import java.util.HashMap;

public class Graph<T, G> {
    private HashMap<T, Link<T, G>> myHashTable;

    public Graph() {
        myHashTable = new HashMap<T, Link<T, G>>();
    }

    public void AddNode(T key) {
        myHashTable.put(key, null);
    }

    public void AddLink(T from, T to, G weight) {
        myHashTable.put(from, new Link<T, G>(to, weight, myHashTable.get(from)));
    }
}