package src.unittest;
import java.util.ArrayList;
import java.util.Comparator;
import src.graph.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;
import src.kruskal.*;
import src.unionfindset.*;


/* 
 *  Tests for: GetAdiacentNodes(), DeleteLink() are missing 
 */

public class UnitTest {
    public Graph<String,Integer> myGraph; 
    public Graph<String,Integer> myGraphDirect;
    public Graph<String,Integer> myGraphNotDirect;

    @Before
    public void CreateStruct() throws GraphExceptions {
        myGraph = new Graph<String, Integer>();
        myGraphDirect = new Graph<String, Integer>(true);
        myGraphNotDirect = new Graph<String, Integer>(false);
    }

    @Test
    public void CreateNullGraph() throws Exception{
        assertTrue(myGraph instanceof Graph<?,?>);
    }

    @Test
    public void AddNodes() throws Exception{
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
        myGraph.AddLink("Torino", "Milano", 150);
        myGraph.AddLink("Torino", "Genova", 100);
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
        myGraph.AddLink("Milano", "Torino", 300);
        myGraph.DeleteNode("Milano");
        assertFalse(myGraph.HasNode("Milano"));
        assertTrue(myGraph.HasNode("Torino"));
        //TODO: Test if in the Milano node the node 'Torino' still exists or not. Shouldn't exists.
    }

    @Test
    public void CheckDeleteLink() {
        //ADD
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
        myGraph.AddLink("Torino", "Milano", 150);
        myGraph.AddLink("Torino", "Genova", 100);
        assertTrue(2 == myGraph.GetNumberOfLinks());
        assertFalse(3 == myGraph.GetNumberOfLinks());
    }

    @Test
    public void CheckGetNodes() throws Exception {
        myGraph.AddNode("Torino");
        myGraph.AddNode("Milano");
        myGraph.AddNode("Genova");

        ArrayList<String> myNodes = myGraph.GetNodes();

        //done because the order on insertion is not allways the order of output to arrayList
        //to resolve this problem, the array list is first sorted and then checked by using a comparator
        //defined into the comparator class into java.util.Comparator.
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
        myGraph.AddLink("Milano", "Torino", 300);
        
        Kruskal<String, Integer> myKruskal = new Kruskal<String, Integer>(myGraph, Comparator.comparing(Integer::intValue));
        myKruskal.begin();
        UnionFindSet<String> myNodes = myKruskal.getMstNodes();
        ArrayList<Links<String, Integer>> myArrayList = myKruskal.getMstLinks();
        Links<String, Integer> l = myArrayList.get(0);
        assertTrue(l.getNode1()=="Milano");
        assertTrue(l.getNode2()=="Torino");
    }
}