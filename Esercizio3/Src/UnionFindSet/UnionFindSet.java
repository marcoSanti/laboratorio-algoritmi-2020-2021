package Src.UnionFindSet;


public class UnionFindSet<T> {

    private UnionFindSetElement<T> myList;

    public UnionFindSet() {
        myList = null;
    }

    public void MakeSet(T x) {
        myList = new UnionFindSetElement<T>(x, myList);
    }

    public void Union(T x, T y) {
    
        UnionFindSetElement<T> tmpList1 = myList;
        UnionFindSetElement<T> tmpList2 = myList;
        
        while(tmpList1 != null && tmpList1.GetValue() != x){
            tmpList1 = tmpList1.GetNextInList();
        }

        while(tmpList2 != null && tmpList2.GetValue() != x){
            tmpList2 = tmpList2.GetNextInList();
        }

        if(tmpList1==null || tmpList2==null) throw new Error("Error: item 1 or 2 is not in list");

        /*chiedere se si trova un elemento non nella lista se 
        lanciare errore o lanciare un makeset e farlo funzionare comunque */

        Link(FindDad(tmpList1), FindDad(tmpList2));
    }

    
    public UnionFindSetElement<T> FindSet(T x){
        UnionFindSetElement<T> tmpList = myList;

        while(tmpList != null && tmpList.GetValue() != x){
            tmpList = tmpList.GetNextInList();
        }

        return FindDad(tmpList);
    }


    private void Link(UnionFindSetElement<T> x, UnionFindSetElement<T> y) {
        if (x.GetRank() > y.GetRank()) {
            y.SetParent(x);
        } else {
            x.SetParent(y);
            if (x.GetRank() == y.GetRank()) {
                y.SetRank(y.GetRank() + 1);
            }
        }
    }

    private UnionFindSetElement<T> FindDad(UnionFindSetElement<T> x) {
        if (x != x.GetParent()) {
            x.SetParent(FindDad(x.GetParent()));
        }
        return x.GetParent();
    }
}