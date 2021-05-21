package src.graph;

/**
 * This class is the rappresentation of a link between two nodes, where T is the
 * type of the key used to access the HashMap containing the nodes. The class
 * implements Comparable<> in order to make it possible to use the method sort()
 * on an ArrayList<Links<T>>
 */
public class Links<T> implements Comparable<Links<T>> {
    private T node1;
    private T node2;
    private double weight;

    public Links(T node1, T node2, double weight) {
        this.node1 = node1;
        this.node2 = node2;
        this.weight = weight;
    }

    public T getNode1() {
        return this.node1;
    }

    public T getNode2() {
        return this.node2;
    }

    public Double getWeight() {
        return this.weight;
    }

    @Override
    public int compareTo(Links<T> o) {

        if (this.weight == o.getWeight())
            return 0;
        else if (this.weight > o.getWeight())
            return 1;
        else
            return -1;

    }
}
