package src.unionfindset;

public class UnionFindSetElement<T> {

    private T value;
    private int rank;
    private UnionFindSetElement<T> parent; 

    public UnionFindSetElement(T value) {
        this.value = value;
        this.parent = this;
        this.rank = 0;
    }

    
    public T GetValue() {  return this.value;  }

    public int GetRank() {  return this.rank;  }

    public UnionFindSetElement<T> GetParent() {  return this.parent;  }


    public void SetValue(T x) {  this.value = x;  }

    public void incrementRank() {  this.rank++;  }

    public void SetParent(UnionFindSetElement<T> newParent) {  this.parent = newParent;  }
    
}