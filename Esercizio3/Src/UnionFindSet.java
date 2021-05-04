package src;

public class UnionFindSet<T> {

    public UnionFindSetElement<T> myList;

    public UnionFindSet() {
        myList = null;
    }

    public void MakeSet(T x) {
        /*
         *  La testa della lista e' sempre l'ultimo elemento che e' stato aggiunto
         */
        myList = new UnionFindSetElement<T>(x, myList);
    } 

    public void Union(UnionFindSetElement<T> x, UnionFindSetElement<T> y) {
        Link(FindSet(x), FindSet(y));
    }

    private void Link(UnionFindSetElement<T> x, UnionFindSetElement<T> y) {
        if(x.GetRank() > y.GetRank()) {
            y.SetParent(x);
        } else {
            x.SetParent(y);
            if(x.GetRank() == y.GetRank()) {
                y.SetRank(y.GetRank() + 1);
            }
        }
    }

    public UnionFindSetElement<T> FindSet(UnionFindSetElement<T> x) {
        if(x != x.GetParent()) {
            x.SetParent(FindSet(x.GetParent()));
        }
        return x.GetParent();
    }
}