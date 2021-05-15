package Src.Graph;

public class Links<T,G> {
    public T node1;
    public T node2;
    public G weight;

    public Links(T node1, T node2, G weight){
        this.node1 = node1;
        this.node2 = node2;
        this.weight = weight;
    }
}
