public class UnionFindSet<T> {
    private T value;
    private int rank;
    private UnionFindSet<T> parent;

    public UnionFindSet(T x) {
        this.value = x;
        this.rank = 0;
        this.parent = this;
    }

    public T GetValue() {
        return this.value;
    }

    public int GetRank() {
        return this.rank;
    }

    public UnionFindSet<T> GetParent() {
        return this.parent;
    }

    public void SetValue(T x) {
        this.value = x;
    }

    public void SetRank(int rank) {
        this.rank = rank;
    }

    public void SetParent(UnionFindSet<T> newParent) {
        this.parent = newParent;
    }

    public void Union(UnionFindSet<T> x, UnionFindSet<T> y) {
        Link(FindSet(x), FindSet(y));
    }

    public void Link(UnionFindSet<T> x, UnionFindSet<T> y) {
        if(x.GetRank() > y.GetRank()) {
            y.SetParent(x);
        } else {
            x.SetParent(y);
            if(x.GetRank() == y.GetRank()) {
                y.SetRank(y.GetRank() + 1);
            }
        }
    }

    public UnionFindSet<T> FindSet(UnionFindSet<T> x) {
        if(x != x.GetParent()) {
            x.SetParent(FindSet(x.GetParent()));
        }
        return x.GetParent();
    }
}