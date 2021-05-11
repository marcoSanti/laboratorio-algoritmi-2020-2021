package Src.UnionFindSet;

public class UnionFindSetElement<T> {

    private T value;
    private int rank;
    private UnionFindSetElement<T> parent; 
    private UnionFindSetElement<T> nextInList;

    public UnionFindSetElement(T value, UnionFindSetElement<T> newNextInList) {
        this.value = value;
        this.parent = this;
        this.nextInList = newNextInList;
        this.rank = 0;
    }

    
    public T GetValue() {  return this.value;  }

    public int GetRank() {  return this.rank;  }

    public UnionFindSetElement<T> GetParent() {  return this.parent;  }

    public UnionFindSetElement<T> GetNextInList() { return this.nextInList;  } 


    public void SetValue(T x) {  this.value = x;  }

    public void incrementRank() {  this.rank++;  }

    public void SetParent(UnionFindSetElement<T> newParent) {  this.parent = newParent;  }

    public void SetNextInList(UnionFindSetElement<T> newNextInList) {  this.nextInList = newNextInList;  }

    
}