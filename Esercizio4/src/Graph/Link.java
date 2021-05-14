package Src.Graph;

public class Link<T, G> {
    private G weight;
    private T link;
    private Link<T,G> next;

    public Link(G weight, T link, Link<T,G> next) {
        this.weight = weight;
        this.link = link;
        this.next = next;
    }

    public T getLink() {
        return this.link;
    }

    public G getWeight() {
        return this.weight;
    }
}
