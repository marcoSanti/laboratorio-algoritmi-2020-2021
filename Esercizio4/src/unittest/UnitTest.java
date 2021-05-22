package src.unittest;

import java.util.ArrayList;
import java.util.Comparator;
import src.graph.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import src.kruskal.*;

/* 
 *  Tests for: GetAdiacentNodes(), DeleteLink() are missing 
 */

public class UnitTest {
    public Graph<String, Float> myGraph;
    public Graph<String, Float> myGraphDirect;
    public Graph<String, Float> myGraphNotDirect;

    @Before
    public void CreateStruct() throws GraphExceptions {
        myGraph = new Graph<String, Float>();
        myGraphDirect = new Graph<String, Float>(true);
        myGraphNotDirect = new Graph<String, Float>(false);
    }

    @Test
    public void CreateNullGraph() throws Exception {
        assertTrue(myGraph instanceof Graph<?,?>);
    }

    @Test
    public void AddNodes() throws Exception {
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");
        assertTrue(myGraph.HasNode("Torino"));
        assertTrue(myGraph.HasNode("Milano"));
        assertTrue(myGraph.HasNode("Genova"));
        assertFalse(myGraph.HasNode("Venezia"));
    }

    @Test
    public void AddLinks() throws Exception {
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");
        myGraph.AddLink("Torino", "Milano", (float) 150);
        myGraph.AddLink("Torino", "Genova", (float) 100);
        assertTrue(150 == myGraph.GetWeight("Torino", "Milano"));
        assertTrue(100 == myGraph.GetWeight("Torino", "Genova"));
        assertFalse(100000 == myGraph.GetWeight("Torino", "Milano"));
    }

    @Test
    public void CheckForNodes() throws Exception {
        myGraph.AddNode("Torino");
        assertTrue(myGraph.HasNode("Torino"));
        assertFalse(myGraph.HasNode("Genova"));
    }

    @Test
    public void CheckDeleteNode() throws Exception {
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");
        myGraph.AddLink("Milano", "Torino", (float) 300);
        myGraph.DeleteNode("Milano");
        assertFalse(myGraph.HasNode("Milano"));
        assertTrue(myGraph.HasNode("Torino"));
    }

    @Test
    public void CheckDeleteLink() {
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");
        try {
            myGraph.AddLink("Milano", "Torino", (float) 300);
            myGraph.DeleteLink("Milano", "Torino");
            ArrayList<Links<String, Float>> tmpArrList = myGraph.GetLinks();
            assertTrue(tmpArrList.size() == 0);
        } catch (GraphExceptions e) {
            e.printStackTrace();
        }
    }

    @Test
    public void CheckNumberOfNodes() throws Exception {
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");

        assertTrue(3 == myGraph.GetNumberOfNode());
        assertFalse(4 == myGraph.GetNumberOfNode());
    }

    @Test
    public void CheckNumberOfLinks() throws Exception {
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");
        myGraph.AddLink("Torino", "Milano", (float) 150);
        myGraph.AddLink("Torino", "Genova", (float) 100);
        assertTrue(2 == myGraph.GetNumberOfLinks());
        assertFalse(3 == myGraph.GetNumberOfLinks());
    }

    @Test
    public void CheckGetNodes() throws Exception {
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");

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
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");
        myGraph.AddLink("Milano", "Torino", (float) 300);

        Kruskal<String, Float> myKruskal = new Kruskal<String, Float>(myGraph);
        ArrayList<Links<String, Float>> myArrayList = myKruskal.run();

        Links<String, Float> l = myArrayList.get(0);
        assertTrue(l.getNode1() == "Milano");
        assertTrue(l.getNode2() == "Torino");
    }

    /**
     * This test check for an error generated if the Graph is of a type wich cannot be 
     * used to run the kruskal algoritm
     */
    @Test
    public void CheckKruskalError(){
        try{
            Graph<String,String> testGraphError = new Graph<String, String>();
            testGraphError.AddNode("Torino");
            testGraphError.AddNode("Genova");
            testGraphError.AddNode("Milano");
            testGraphError.AddLink("Torino", "Genova", "AB");
            testGraphError.AddLink("Torino", "Milano", "BC");
            testGraphError.AddLink("Milano", "Genova", "CD");

            Kruskal<String, String> errorKTest = new Kruskal<String, String>(testGraphError);
            errorKTest.run();
        }catch (Exception e){
            assertTrue(e instanceof ClassCastException);
        }
    }
}