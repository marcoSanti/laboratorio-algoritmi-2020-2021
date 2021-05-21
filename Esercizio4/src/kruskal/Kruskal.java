package src.kruskal;

import src.graph.*;
import src.unionfindset.*;
import java.util.ArrayList;

public class Kruskal<T, G>{

    private Graph<T, G> myGraph = null;
    private UnionFindSet<T> myUnionFindSet = null;
    private ArrayList<Links<T, G>> graphLinks = null;

    private ArrayList<Links<T, G>> mstGraphLinks = null;

    /**
     * This method instantiates the kruskal algorith class
     * 
     * @param myGraph The graph where to calculathe the MST
     * @param c       the comparator used to sort the links. It must be a comparator
     *                for the type of data the weight of the links are expressed in
     */
    public Kruskal(Graph<T, G> myGraph) {
        this.myGraph = myGraph;
        this.myUnionFindSet = new UnionFindSet<T>();
        this.mstGraphLinks = new ArrayList<Links<T, G>>();
    }

    /**
     * This method executes the Kruskal algoritm
     * 
     * @return return the list of links that generates the MST graph
     */
    public ArrayList<Links<T, G>> run() {
        // add nodes to the unionfindset
        for (T e : myGraph.GetNodes()) {
            myUnionFindSet.MakeSet(e);
        }

        // getting all the links and sorting them with the smallest weight first.
        //If the data type is not allowed for sorting, an exeption is raised and the process is stopped
        graphLinks = myGraph.GetLinks();
        graphLinks.sort(Links::compareTo); 

        for (Links<T, G> l : graphLinks) {
            if (myUnionFindSet.FindSet(l.getNode1()) != myUnionFindSet.FindSet(l.getNode2())) {

                mstGraphLinks.add(new Links<T,G>(l.getNode1(), l.getNode2(), l.getWeight()));

                if (!myGraph.IsDirect()) {
                    mstGraphLinks.add(new Links<T, G>(l.getNode2(), l.getNode1(), l.getWeight()));
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
