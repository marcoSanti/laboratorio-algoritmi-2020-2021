package Src.Graph;
import java.util.HashMap;

/* 
 *  Our struct is made by two hashmaps:
 *  ToDos: recupero degli archi dei grafi O(N);
 *  Gestire l'isDirect
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

    /* 
     *  Add a node inside the hashmap that contains the nodes 
     *  This first hashmap contains keys and for every key one hashmap.
     *  The second hashmap contains keys and for evrery key one weight.
     */
    public void AddNode(T key) {
        myHashTable.put(key, new HashMap<T,G>());
    }

    /*
     *  Add a node inside the second hashmap that containts one key and the weight assosiated with that key. 
     */
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

    /*
     *  Return the weight of a link. 
     *  First we get a specific link from a node then we get the weight of the link.
     */
    public G GetWeight(T from, T to) {
        HashMap<T,G> tmpMap = myHashTable.get(from);
        return tmpMap.get(to);
    }

    public HashMap<T,G> GetAdiacentNodes(T key) {
        return myHashTable.get(key);
    }

    /*
     * Loop through the Hashmap and check if the various hashmaps contain the element assosiated with the give key
     */
    public void DeleteNode(T key) {
        myHashTable.remove(key);
        for(T i: myHashTable.keySet()) {
            HashMap<T,G> tmpMap = myHashTable.get(i);
            if(tmpMap.containsKey(key)) {
                tmpMap.remove(key);
            }
        }
    }

    public void DeleteLink(T from, T to) {
        myHashTable.get(from).remove(to);
    }

    public int GetNumberOfNode() {
        return myHashTable.size();
    }

    public HashMap<T,G>[] GetLinks() {
        int size = this.GetNumberOfLinks();
        HashMap<T,G>[] linkList = (HashMap<T,G>[])new Object[size];
        int k = 0;
        for(HashMap<T,G> i: myHashTable.values()) {
            linkList[k] = i;
            k++;
        }
        return linkList;
    }

    /*
     * For each node of the hashmap sum the number of links inside it
     */
    public int GetNumberOfLinks() {
        int sum = 0;
        for(T i: myHashTable.keySet()) {
            sum += myHashTable.get(i).size();
        } 
        return sum;
    }

    /*
     *  Loop throgh the hashmap and save keys inside an array 
     */
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