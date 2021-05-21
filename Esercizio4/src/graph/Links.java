package src.graph;

public class Links<T, G> implements Comparable<Links<T,G>>{
    private T node1;
    private T node2;
    private G weight;

    public Links(T node1, T node2, G weight) {
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

    public G getWeight() {
        return this.weight;
    }

    public int compareTo(Links<T, G> o) throws ClassCastException{
        if( !(weight instanceof Integer) || !(weight instanceof Float) || !(weight instanceof Double))
            throw new ClassCastException("G type is not applicable to comparable!");
        else{
            if(o.getWeight() == this.weight) return 0;
            else if((Double)o.getWeight() > (Double)this.weight) return 1;
            else return 1;
        }
    }
}
