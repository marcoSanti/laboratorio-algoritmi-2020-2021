package src.graph;

import java.util.ArrayList;

/**
 * This class is the base implementation of a generic node. In order to create a
 * custom node, you need to extend this class, adding all the variables and
 * method required to store the information inside your custom node. In this
 * class only the ArrayList and the getter for the array list are implemented.
 * If you do not need to store more variables, but just need the list of links,
 * you can directly use this class without expaning it into another one.
 */
public class GraphNodes<T> {
    private ArrayList<Links<T>> linkList;

    public GraphNodes() {
        linkList = new ArrayList<Links<T>>();
    }

    public ArrayList<Links<T>> getLinkList() {
        return this.linkList;
    }

}
