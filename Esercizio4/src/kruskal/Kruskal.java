package src.kruskal;

import src.graph.*;
import src.unionfindset.*;
import java.util.ArrayList;
import java.util.Comparator;

public class Kruskal<T, G> {

    private Graph<T, G> myGraph = null;
    private UnionFindSet<T> myUnionFindSet = null;
    private ArrayList<Links<T, G>> graphLinks = null;

    // ask why this is done like this with this type
    private Comparator<? super Links<T, G>> c = null;

    private ArrayList<Links<T, G>> mstGraphLinks = null;

    /**
     * This method instantiates the kruskal algorith class
     * 
     * @param myGraph The graph where to calculathe the MST
     * @param c       the comparator used to sort the links. It must be a comparator
     *                for the type of data the weight of the links are expressed in
     */
    public Kruskal(Graph<T, G> myGraph, Comparator c) {
        this.myGraph = myGraph;
        this.myUnionFindSet = new UnionFindSet<T>();
        this.c = c;
        this.mstGraphLinks = new ArrayList<Links<T, G>>();
    }

    public void begin() {
        // add nodes to the unionfindset
        for (T e : myGraph.GetNodes()) {
            myUnionFindSet.MakeSet(e);
        }

        // getting all the links and sorting them with the smallest weight first
        graphLinks = myGraph.GetLinks();
        graphLinks.sort(c);

        for (Links<T, G> l : graphLinks) {
            if (myUnionFindSet.FindSet(l.getNode1()) != myUnionFindSet.FindSet(l.getNode2())) {

                mstGraphLinks.add(new Links<T, G>(l.getNode1(), l.getNode2(), l.getWeight()));

                if (!myGraph.IsDirect()) {
                    mstGraphLinks.add(new Links<T, G>(l.getNode2(), l.getNode1(), l.getWeight()));
                }

                myUnionFindSet.Union(l.getNode1(), l.getNode2());
            }
        }
    }

    public ArrayList<Links<T, G>> getMstLinks() {
        return this.mstGraphLinks;
    }

    public UnionFindSet<T> getMstNodes() {
        return this.myUnionFindSet;
    }

}
