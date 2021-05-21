package src.unittest;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Comparator;

import src.graph.*;
import src.kruskal.*;


public class UnitTest {
    public Graph<String, GraphNodes<String>> myGraph;
    public Graph<String, GraphNodes<String>> myGraphDirect;
    public Graph<String, GraphNodes<String>> myGraphNotDirect;

    @Before
    public void CreateStruct() throws GraphExceptions {
        myGraph = new Graph<String, GraphNodes<String>>();
        myGraphDirect = new Graph<String, GraphNodes<String>>(true);
        myGraphNotDirect = new Graph<String, GraphNodes<String>>(false);
    }

    @Test
    public void CreateNullGraph() throws Exception {
        assertTrue(myGraph instanceof Graph<?, ?>);
    }

    @Test
    public void AddNodes() throws Exception {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        myGraph.AddNode("Milano", new GraphNodes<String>());
        myGraph.AddNode("Genova", new GraphNodes<String>());
        assertTrue(myGraph.HasNode("Torino"));
        assertTrue(myGraph.HasNode("Milano"));
        assertTrue(myGraph.HasNode("Genova"));
        assertFalse(myGraph.HasNode("Venezia"));
    }

    @Test
    public void AddLinks() throws Exception {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        myGraph.AddNode("Milano", new GraphNodes<String>());
        myGraph.AddNode("Genova", new GraphNodes<String>());
        myGraph.AddLink("Torino", "Milano", (double) 150);
        myGraph.AddLink("Torino", "Genova", (double) 100);
        assertTrue(150 == myGraph.GetWeight("Torino", "Milano"));
        assertTrue(100 == myGraph.GetWeight("Torino", "Genova"));
        assertFalse(100000 == myGraph.GetWeight("Torino", "Milano"));
    }

    @Test
    public void CheckForNodes() throws Exception {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        assertTrue(myGraph.HasNode("Torino"));
        assertFalse(myGraph.HasNode("Genova"));
    }

    @Test
    public void CheckDeleteNode() throws Exception {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        myGraph.AddNode("Milano", new GraphNodes<String>());
        myGraph.AddNode("Genova", new GraphNodes<String>());
        myGraph.AddLink("Milano", "Torino", (double) 300);
        myGraph.DeleteNode("Milano");
        assertFalse(myGraph.HasNode("Milano"));
        assertTrue(myGraph.HasNode("Torino"));
    }

    @Test
    public void CheckDeleteLink() {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        myGraph.AddNode("Milano", new GraphNodes<String>());
        myGraph.AddNode("Genova", new GraphNodes<String>());
        try {
            myGraph.AddLink("Milano", "Torino", (double) 300);
            myGraph.DeleteLink("Milano", "Torino");
            ArrayList<Links<String>> tmpArrList = myGraph.GetLinks();
            assertTrue(tmpArrList.size() == 0);
        } catch (GraphExceptions e) {
            e.printStackTrace();
        }
    }

    @Test
    public void CheckNumberOfNodes() throws Exception {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        myGraph.AddNode("Milano", new GraphNodes<String>());
        myGraph.AddNode("Genova", new GraphNodes<String>());

        assertTrue(3 == myGraph.GetNumberOfNode());
        assertFalse(4 == myGraph.GetNumberOfNode());
    }

    @Test
    public void CheckNumberOfLinks() throws Exception {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        myGraph.AddNode("Milano", new GraphNodes<String>());
        myGraph.AddNode("Genova", new GraphNodes<String>());
        myGraph.AddLink("Torino", "Milano", (double) 150);
        myGraph.AddLink("Torino", "Genova", (double) 100);
        assertTrue(2 == myGraph.GetNumberOfLinks());
        assertFalse(3 == myGraph.GetNumberOfLinks());
    }

    @Test
    public void CheckGetNodes() throws Exception {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        myGraph.AddNode("Milano", new GraphNodes<String>());
        myGraph.AddNode("Genova", new GraphNodes<String>());

        ArrayList<String> myNodes = myGraph.GetNodes();

        // done because the order on insertion is not allways the order of output to
        // arrayList
        // to resolve this problem, the array list is first sorted and then checked by
        // using a comparator
        // defined into the comparator class into java.util.Comparator.
        Comparator<String> c = Comparator.comparing(String::toString);
        myNodes.sort(c);

        assertTrue("Torino" == myNodes.get(2));
        assertTrue("Milano" == myNodes.get(1));
        assertTrue("Genova" == myNodes.get(0));

        assertFalse("Genova" == myNodes.get(1));
        assertFalse("Napoli" == myNodes.get(2));
    }

    @Test
    public void CheckForDirect() throws Exception {
        assertTrue(myGraphDirect.IsDirect() == true);
        assertTrue(myGraphNotDirect.IsDirect() == false);
    }

    @Test
    public void CheckKruskal() throws Exception {
        myGraph.AddNode("Torino", new GraphNodes<String>());
        myGraph.AddNode("Milano", new GraphNodes<String>());
        myGraph.AddNode("Genova", new GraphNodes<String>());
        myGraph.AddLink("Milano", "Torino", (double) 300);

        Kruskal<String, GraphNodes<String>> myKruskal = new Kruskal<String, GraphNodes<String>>(myGraph);
        ArrayList<Links<String>> myArrayList = myKruskal.run();

        Links<String> l = myArrayList.get(0);
        assertTrue(l.getNode1() == "Milano");
        assertTrue(l.getNode2() == "Torino");
    }
}