package src.unionfindset;

import java.util.HashMap;

public class UnionFindSet<T> {

    private HashMap<T, UnionFindSetElement<T>> myHashMap = null; // arraylist o hashmap

    public UnionFindSet() {
        myHashMap = new HashMap<T, UnionFindSetElement<T>>();
    }

    /**
     * This method adds a new tree with a single element in the forest.
     * 
     * @param x the element to be added to the forest.
     */
    public void MakeSet(T x) {
        myHashMap.put(x, new UnionFindSetElement<T>(x));
    }

    /**
     * This mthod append the tree with the x elemet as father to the y tree granted
     * that the there are less or equals elements in the X tree than in the y tree,
     * otherwise it is the other way around.
     * 
     * @param x subtree to be appended
     * @param y subtree in with x will be appended
     */
    public void Union(T x, T y) throws UnionFindSetError {

        UnionFindSetElement<T> element1 = myHashMap.get(x);
        UnionFindSetElement<T> element2 = myHashMap.get(y);

        if (element1 == null || element2 == null) {
            throw new UnionFindSetError("Error: one of the item is not into the graph!");
        }

        Link(FindRapresentative(element1), FindRapresentative(element2));
    }

    /**
     * This method returns the root of the tree in with the X element is located.
     * 
     * @param x the element to look for
     * @return X if the element is not in a tree. X.parent otherwise
     */
    public T FindSet(T x) {
        return FindRapresentative(myHashMap.get(x)).GetValue();
    }

    /**
     * This method connets two different tree into a single one
     * 
     * @param x the first tree
     * @param y the second tree
     */
    private void Link(UnionFindSetElement<T> x, UnionFindSetElement<T> y) {
        if (x.GetRank() > y.GetRank()) {
            y.SetParent(x);
        } else {
            x.SetParent(y);
            if (x.GetRank() == y.GetRank()) {
                y.incrementRank();
                ;
            }
        }
    }

    /**
     * This method is a private method to be able to reuse this function in various
     * part of the code
     * 
     * @param x The UnionFindSet<T> element to work with
     * @return the parent of x
     */
    private UnionFindSetElement<T> FindRapresentative(UnionFindSetElement<T> x) {
        if (!x.equals(x.GetParent())) {
            x.SetParent(FindRapresentative(x.GetParent()));
        }
        return x.GetParent();
    }

    public int GetNumberOfNode() {
        return myHashMap.size();
    }
}