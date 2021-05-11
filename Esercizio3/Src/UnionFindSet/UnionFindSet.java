package Src.UnionFindSet;


public class UnionFindSet<T> {

    private UnionFindSetElement<T> myList;

    public UnionFindSet() {
        myList = null;
    }

    /**
     * This method adds a new tree with a single element in the forest.
     * @param x the element to be added to the forest.
     */
    public void MakeSet(T x) {
        myList = new UnionFindSetElement<T>(x, myList);
    }

    /**
     * This mthod append the tree with the x elemet as father to the y tree granted that the 
     * there are less or equals elements in the X tree than in the y tree, otherwise it is the other way around.
     * @param x subtree to be appended
     * @param y subtree in with x will be appended
     */
    public void Union(T x, T y) {
    
        UnionFindSetElement<T> tmpList1 = myList;
        UnionFindSetElement<T> tmpList2 = myList;
        
        while(tmpList1 != null && tmpList1.GetValue() != x){
            tmpList1 = tmpList1.GetNextInList();
        }

        while(tmpList2 != null && tmpList2.GetValue() != y){
            tmpList2 = tmpList2.GetNextInList();
        }

        if(tmpList1==null || tmpList2==null) throw new Error("Error: item 1 or 2 is not in list");

        /*chiedere se si trova un elemento non nella lista se 
        lanciare errore o lanciare un makeset e farlo funzionare comunque */

        Link(FindDad(tmpList1), FindDad(tmpList2));
    }

    /**
     * This method returns the root of the tree in with the X element is located.
     * @param x the element to look for
     * @return X if the element is not in a tree. X.parent otherwise
     */
    public T FindSet(T x){
        UnionFindSetElement<T> tmpList = myList;

        while(tmpList != null && tmpList.GetValue() != x){
            tmpList = tmpList.GetNextInList();
        }

        return FindDad(tmpList).GetValue();
    }


    private void Link(UnionFindSetElement<T> x, UnionFindSetElement<T> y) {
        if (x.GetRank() > y.GetRank()) {
            y.SetParent(x);
        } else {
            x.SetParent(y);
            if (x.GetRank() == y.GetRank()) {
                y.incrementRank();;
            }
        }
    }

    private UnionFindSetElement<T> FindDad(UnionFindSetElement<T> x) {
        if ( !x.equals(x.GetParent()) ) {
            x.SetParent(FindDad(x.GetParent()));
        }
        return x.GetParent();
    }
}