package src.graph;

public class Links<T,G> {
    private T node1;
    private T node2;
    private G weight;

    public Links(T node1, T node2, G weight){
        this.node1 = node1;
        this.node2 = node2;
        this.weight = weight;
    }

    public T getNode1(){ return this.node1; }

    public T getNode2(){ return this.node2; }
    
    public G getWeight(){ return this.weight; }

}
