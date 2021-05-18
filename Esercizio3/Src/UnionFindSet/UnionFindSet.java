package Src.UnionFindSet;

import java.util.HashMap;

public class UnionFindSet<T> {

    private HashMap<T,UnionFindSetElement<T>>  myHashMap=null; //arraylist o hashmap

    public UnionFindSet() {
        myHashMap = new HashMap<T,UnionFindSetElement<T>>();
    }

    /**
     * This method adds a new tree with a single element in the forest.
     * @param x the element to be added to the forest.
     */
    public void MakeSet(T x) {
        myHashMap.put(x, new UnionFindSetElement<T>(x));
    }

    /**
     * This mthod append the tree with the x elemet as father to the y tree granted that the 
     * there are less or equals elements in the X tree than in the y tree, otherwise it is the other way around.
     * @param x subtree to be appended
     * @param y subtree in with x will be appended
     */
    public void Union(T x, T y) throws Error {
        
        UnionFindSetElement<T> element1 = myHashMap.get(x);
        UnionFindSetElement<T> element2 = myHashMap.get(y);

        if(element1==null || element2==null) throw new Error("Error: item 1 or 2 is not in list");

        Link(FindDad(element1), FindDad(element2));
    }

    /**
     * This method returns the root of the tree in with the X element is located.
     * @param x the element to look for
     * @return X if the element is not in a tree. X.parent otherwise
     */
    public T FindSet(T x){
        return FindDad(myHashMap.get(x)).GetValue();
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