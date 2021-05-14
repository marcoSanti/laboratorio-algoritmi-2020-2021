package Src.Graph;
import java.util.HashMap;

/* 
 *  Our struct is made by two hashmaps:
 *  ToDos: recupero degli archi dei grafi O(N);
 *  Gestire l'isDirect
 *  UnitTest
 */
public class Graph<T, G> {
    private HashMap<T, HashMap<T, G>> myHashTable;
    private boolean isDirect = true;

    public Graph(boolean isDirect) {
        this.isDirect = isDirect;
    }

    public Graph() {
        myHashTable = new HashMap<T, HashMap<T,G>>();
    }

    public void AddNode(T key) {
        myHashTable.put(key, new HashMap<T,G>());
    }

    public void AddLink(T from, T to, G weight) {
        HashMap<T,G> tmpMap = myHashTable.get(from);
        tmpMap.put(to, weight);
        if(!isDirect) {
            tmpMap = myHashTable.get(to);
            tmpMap.put(from, weight);
        }
    }
    /* 
     *  Returns true if node with the specified key exists, false otherwise 
     */
    public boolean HasNode(T key) {
        return myHashTable.containsKey(key);
    }

    public G GetWeight(T from, T to) {
        HashMap<T,G> tmpMap = myHashTable.get(from);
        return tmpMap.get(to);
    }

    public HashMap<T,G> GetAdiacentNodes(T key) {
        return myHashTable.get(key);
    }

    /*
     * Loop through the HashTable for the other nodes 
     */
    public void DeleteNode(T key) {
        myHashTable.remove(key);
    }

    public void DeleteLink(T from, T to) {
        myHashTable.get(from).remove(to);
    }

    public int GetNumberOfNode() {
        return myHashTable.size();
    }

    /*
     * Loop through the keys
     */
    public int GetNumberOfLinks() {
        int sum = 0;
        for(T i: myHashTable.keySet()) {
            sum += myHashTable.get(i).size();
        } 
        return sum;
    }

    public T[] GetNodes() {
        T[] nodeList = (T[])new Object[myHashTable.size()];
        int k = 0;
        for(T i: myHashTable.keySet()) {
            nodeList[k] = i;
            k++;
        } 
        return nodeList;
    }

    public boolean IsDirect() {
        return this.isDirect;
    }
}