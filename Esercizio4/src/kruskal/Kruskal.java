package src.kruskal;

import src.graph.*;
import src.unionfindset.*;
import java.util.ArrayList;
import java.util.Collections;

public class Kruskal<T> {

    private Graph<T> myGraph = null;
    private UnionFindSet<T> myUnionFindSet = null;
    private ArrayList<Links<T>> graphLinks = null;

    private ArrayList<Links<T>> mstGraphLinks = null;

    /**
     * This method instantiates the kruskal algorith class
     * 
     * @param myGraph The graph where to calculathe the MST
     * @param c       the comparator used to sort the links. It must be a comparator
     *                for the type of data the weight of the links are expressed in
     */
    public Kruskal(Graph<T> myGraph) {
        this.myGraph = myGraph;
        this.myUnionFindSet = new UnionFindSet<T>();
        this.mstGraphLinks = new ArrayList<Links<T>>();
    }

    /**
     * This method executes the Kruskal algoritm
     * 
     * @return return the list of links that generates the MST graph
     */
    public ArrayList<Links<T>> run() {
        // add nodes to the unionfindset
        for (T e : myGraph.GetNodes()) {
            myUnionFindSet.MakeSet(e);
        }

        // getting all the links and sorting them with the smallest weight first
        graphLinks = myGraph.GetLinks();
        Collections.sort(graphLinks);

        for (Links<T> l : graphLinks) {
            if (myUnionFindSet.FindSet(l.getNode1()) != myUnionFindSet.FindSet(l.getNode2())) {

                mstGraphLinks.add(new Links<T>(l.getNode1(), l.getNode2(), l.getWeight()));

                if (!myGraph.IsDirect()) {
                    mstGraphLinks.add(new Links<T>(l.getNode2(), l.getNode1(), l.getWeight()));
                }

                myUnionFindSet.Union(l.getNode1(), l.getNode2());
            }
        }

        return this.mstGraphLinks;
    }

    public UnionFindSet<T> getMstNodes() {
        return this.myUnionFindSet;
    }

}
