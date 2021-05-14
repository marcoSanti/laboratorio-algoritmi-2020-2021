package Src.Graph;
import java.util.HashMap;
import java.util.ArrayList;

/* 
 *  Our struct is made by two hashmaps:
 *  ToDos: recupero degli archi dei grafi O(N);
 *  Gestire l'isDirect
 */
public class Graph<T, G> {
    private HashMap<T, HashMap<T, G>> myHashTable;
    private boolean isDirect = true;

    /**
     * this is a constructor of the class Graph. if true is passed as paramether, 
     * the Graph will then be direct
     * @param isDirect whether the Graph is direct (true) or not (false)
     */
    public Graph(boolean isDirect) {
        this();
        this.isDirect = isDirect;
    }

    /**
     * This method is a constructor that sets the value to the isDirect to false and instantiates
     * a HashMap to store the graph in memory
     */
    public Graph() {
        myHashTable = new HashMap<T, HashMap<T,G>>();
    }

    /* 
     *  Add a node inside the hashmap that contains the nodes 
     *  This first hashmap contains keys and for every key one hashmap.
     *  The second hashmap contains keys and for evrery key one weight.
     */
    /**
     * This method adds a node to the GRaph
     * @param key The name of the node into the graph
     */
    public void AddNode(T key) {
        myHashTable.put(key, new HashMap<T,G>());
    }

    /*
     *  Add a node inside the second hashmap that containts one key and the weight assosiated with that key. 
     */
    /**
     * This methods adds a connection between two nodes. if isDirect is false, then a reverse link is
     * also added to the graph
     * @param node1 the starting node
     * @param node2 the destination node
     * @param weight the weight of the connection
     */
    public void AddLink(T node1, T node2, G weight) {
        HashMap<T,G> tmpMap = myHashTable.get(node1);
        tmpMap.put(node2, weight);
        if(!isDirect) {
            tmpMap = myHashTable.get(node2);
            tmpMap.put(node1, weight);
        }
    }
    /* 
     *  Returns true if node with the specified key exists, false otherwise 
     */
    /**
     * This method tells wheter a node exists into the graph.
     * @param node the node to search into the graph
     * @return true if a node is in the graph false otherwise
     */
    public boolean HasNode(T node) {
        return myHashTable.containsKey(node);
    }

    /*
     *  Return the weight of a link. 
     *  First we get a specific link from a node then we get the weight of the link.
     */
    /**
     * This method return the weight of the link between the two nodes
     * @param node1 the beginnning node
     * @param node2 the destination node
     * @return the weight of the link from node1 to node 2
     */
    public G GetWeight(T node1, T node2) {
        return myHashTable.get(node1).get(node2);
    }

    /**
     * This method return the adiacents nodes
     * @param node the node of interest
     * @return the hashtable of the node
     */
    public HashMap<T,G> GetAdiacentNodes(T node) {
        return myHashTable.get(node);
    }

    /*
     * Loop through the Hashmap and check if the various hashmaps contain the element assosiated with the give key
     */
    /**
     * This method deletes the node with name "node" and remove all links strarting from node or
     * arriving to node key
     * @param node the name of the node to be deleted
     */
    public void DeleteNode(T node) {
        myHashTable.remove(node);
        for(T i: myHashTable.keySet()) {
            HashMap<T,G> tmpMap = myHashTable.get(i);
            if(tmpMap.containsKey(node)) {
                tmpMap.remove(node);
            }
        }
    }

    /**
     * This method deletes a link from node1 to node2
     * @param node1 the starting node of the link
     * @param node2 the ending node of the link
     */
    public void DeleteLink(T node1, T node2) {
        myHashTable.get(node1).remove(node2);
    }

    /**
     * This method return the number of nodes into a Graph
     * @return the integer number of nodes
     */
    public int GetNumberOfNode() {
        return myHashTable.size();
    }

    /**  CONTROLLARE CHE QUESTO NON FUNZIONA TROPPO BENE CHE IN REALTà DA PROBLEMI: SALVO SOLO LA DESTINAZIONE MA NON L'ORIGINE. SERVE ARRAYLIST CON STRUTTURA CHE SALVA IL FROM, IL TO E IL WEIGHT
     * This method return an ArrayList containing all links of the 
     * @return an arraylist containig all elements
     */
    public ArrayList<HashMap<T,G>> GetLinks() {

        ArrayList<HashMap<T,G>> linkList = new ArrayList<HashMap<T,G>>();

        int k = 0;
        for(HashMap<T,G> i: myHashTable.values()) {
            linkList.add(i);
            k++;
        }
        return linkList;
    }

    /*
     * For each node of the hashmap sum the number of links inside it
     */
    /**
     * this method returns the number of links into the Graph
     * @return an integer count of all links into the graph
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

     /**
      * This method return all nodes
      * @return this method returns an ArrayList of all nodes into the graph
      */
    public ArrayList<T> GetNodes() {
        ArrayList<T> nodeList = new ArrayList<T>();
        for(T i: myHashTable.keySet()) {
            nodeList.add(i);
        } 
        return nodeList;
    }

    

    public boolean IsDirect() {
        return this.isDirect;
    }
}