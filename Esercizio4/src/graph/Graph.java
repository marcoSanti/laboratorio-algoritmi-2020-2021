package src.graph;

import java.util.HashMap;
import java.util.ArrayList;

/* 
 *  This class requires two generic types:
 * T: The type of the node label
 * G: The type of the link label 
 */
public class Graph<T, G> {
    private HashMap<T, ArrayList<Links<T, G>>> myGraph;
    private boolean isDirect = true;

    /**
     * this is a constructor of the class Graph. if true is passed as paramether,
     * the Graph will then be direct
     * 
     * @param isDirect whether the Graph is direct (true) or not (false)
     */
    public Graph(boolean isDirect) {
        this();
        this.isDirect = isDirect;
    }

    /**
     * This method is a constructor that sets the value to the isDirect to false and
     * instantiates a HashMap to store the graph in memory
     */
    public Graph() {
        myGraph = new HashMap<T, ArrayList<Links<T, G>>>();
    }

    /**
     * This method adds a node to the GRaph
     * 
     * @param key The name of the node into the graph
     */
    public void AddNode(T key) {
        myGraph.put(key, new ArrayList<Links<T, G>>());
    }

    /**
     * This methods adds a connection between two nodes. if isDirect is false, then
     * a reverse link is also added to the graph
     * 
     * @param node1  the starting node
     * @param node2  the destination node
     * @param weight the weight of the connection
     */
    public void AddLink(T node1, T node2, G weight) throws GraphExceptions {
        ArrayList<Links<T, G>> nodeTmp = myGraph.get(node1);
        ArrayList<Links<T, G>> nodeTmp1 = myGraph.get(node2);

        if (nodeTmp == null || nodeTmp1 == null) {
            throw new GraphExceptions("Error: node does not exist in graph!");
        }

        nodeTmp.add(new Links<T, G>(node1, node2, weight));

        if (!isDirect) {
            nodeTmp1.add(new Links<T, G>(node2, node1, weight));
        }
    }

    /**
     * This method tells wheter a node exists into the graph.
     * 
     * @param node the node to search into the graph
     * @return true if a node is in the graph false otherwise
     */
    public boolean HasNode(T node) {
        return myGraph.containsKey(node);
    }

    /**
     * This method return the weight of the link between the two nodes
     * 
     * @param node1 the beginnning node
     * @param node2 the destination node
     * @return the weight of the link from node1 to node 2
     */
    public G GetWeight(T node1, T node2) throws GraphExceptions {
        ArrayList<Links<T, G>> myNode = myGraph.get(node1);

        if (myNode == null) {
            throw new GraphExceptions("Error: Node 1 does not exist into your graph!");
        }

        for (Links<T, G> link : myNode) {
            if (link.getNode2() == node2)
                return link.getWeight();
        }

        throw new GraphExceptions(
                "Error: node 2 does not exists in graph or a link does not eists between node1 and node2");
    }

    /**
     * This method return the adiacents nodes
     * 
     * @param node the node of interest
     * @return the hashtable of the node
     */
    public ArrayList<Links<T, G>> GetAdiacentNodes(T node) throws GraphExceptions {
        ArrayList<Links<T, G>> arrayListTmp = myGraph.get(node);

        if (arrayListTmp == null)
            throw new GraphExceptions("Error: the node does not exists into the graph");

        return arrayListTmp;
    }

    /**
     * This method deletes the node with name "node" and remove all links strarting
     * from node or arriving to node key
     * 
     * @param node the name of the node to be deleted
     */
    public void DeleteNode(T node) {
        myGraph.remove(node);

        for (T i : myGraph.keySet()) {

            ArrayList<Links<T, G>> arrayList = myGraph.get(i);

            /**
             * Since the list of link for each node is small, it is possible to immagine
             * that this for code is completed in a "constant" and small time. For bigger
             * list with more connections, a hashmap is maybe a better solution so that a
             * delete can be done in O(1) whatever the size will be
             */
            for (Links<T, G> link : arrayList) {
                if (link.getNode2() == node)
                    arrayList.remove(link);
            }
        }
    }

    /**
     * This method deletes a link from node1 to node2. This must be completed in two
     * steps with complexity O(n) otherwise if i delete wile i am reading, a
     * concurrentmodificationexception is thrown. So in the first for loop i retrive
     * all nodes to be deleted and in the second i delete them from the original
     * list. the complexity is O(2n) = O(n) so there is no change in the complexity.
     * The algoritm is run twice if the graph is not direct
     * 
     * @param node1 the starting node of the link
     * @param node2 the ending node of the link
     */
    public void DeleteLink(T node1, T node2) {
        ArrayList<Links<T, G>> arrayList = myGraph.get(node1);
        ArrayList<Links<T, G>> arrayListTmp = new ArrayList<Links<T, G>>();

        for (Links<T, G> link : arrayList) {
            if (link.getNode2() == node2)
                arrayListTmp.add(link);
        }
        for (Links<T, G> link : arrayListTmp) {
            arrayList.remove(link);
        }

        if (!isDirect) {
            arrayList = myGraph.get(node2);
            arrayListTmp = new ArrayList<Links<T, G>>();
            for (Links<T, G> link : arrayList) {
                if (link.getNode2() == node1)
                    arrayListTmp.add(link);
            }
            for (Links<T, G> link : arrayListTmp) {
                arrayList.remove(link);
            }
        }
    }

    /**
     * This method return the number of nodes into a Graph
     * 
     * @return the integer number of nodes
     */
    public int GetNumberOfNode() {
        return myGraph.size();
    }

    /**
     * This method returns All links into a graph. Given that N is the number of
     * links, then i can duoble loop into the hashmap to get all links
     * 
     *@return the arrayList containing all the links. Those links are not sorted.
     */
    public ArrayList<Links<T, G>> GetLinks() {
        ArrayList<Links<T, G>> myList = new ArrayList<Links<T, G>>();

        for (T i : myGraph.keySet()) {
            for (Links<T, G> j : myGraph.get(i)) {
                myList.add(j);
            }
        }

        return myList;
    }

    /**
     * this method returns the number of links into the Graph
     * 
     * @return an integer count of all links into the graph
     */
    public int GetNumberOfLinks() {
        int sum = 0;
        for (T i : myGraph.keySet()) {
            sum += myGraph.get(i).size();
        }
        return sum;
    }

    /**
     * This method return a list of keys to the hashTable
     * 
     * @return this method returns an ArrayList of all nodes into the graph
     */
    public ArrayList<T> GetNodes() {
        ArrayList<T> nodeList = new ArrayList<T>();
        for (T i : myGraph.keySet()) {
            nodeList.add(i);
        }
        return nodeList;
    }

    /**
     * This method return if the graph is direct or not
     * 
     * @return true if the fraph is direct or false otherwise
     */
    public boolean IsDirect() {
        return this.isDirect;
    }
}