package src.unittest;
import java.util.ArrayList;
import java.util.Comparator;
import src.graph.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;


/* 
 *  Tests for: GetAdiacentNodes(), DeleteLink() are missing 
 */

public class UnitTest {
    public Graph<String,Integer> myHashmap; 
    public Graph<String,Integer> myHashmapDirect;
    public Graph<String,Integer> myHashmapNotDirect;

    @Before
    public void CreateStruct() throws GraphExceptions {
        myHashmap = new Graph<String, Integer>();
        myHashmapDirect = new Graph<String, Integer>(true);
        myHashmapNotDirect = new Graph<String, Integer>(false);
    }

    @Test
    public void CreateNullGraph() throws Exception{
        assertTrue(myHashmap instanceof Graph<?,?>);
    }

    @Test
    public void AddNodes() throws Exception{
        myHashmap.AddNode("Torino");
        myHashmap.AddNode("Milano");
        myHashmap.AddNode("Genova");
        assertTrue(myHashmap.HasNode("Torino"));
        assertTrue(myHashmap.HasNode("Milano"));
        assertTrue(myHashmap.HasNode("Genova"));
        assertFalse(myHashmap.HasNode("Venezia"));
    }

    @Test 
    public void AddLinks() throws Exception {
        myHashmap.AddNode("Torino");
        myHashmap.AddNode("Milano");
        myHashmap.AddNode("Genova");
        myHashmap.AddLink("Torino", "Milano", 150);
        myHashmap.AddLink("Torino", "Genova", 100);
        assertTrue(150 == myHashmap.GetWeight("Torino", "Milano"));
        assertTrue(100 == myHashmap.GetWeight("Torino", "Genova"));
        assertFalse(100000 == myHashmap.GetWeight("Torino", "Milano"));
    }

    @Test
    public void CheckForNodes() throws Exception {
        myHashmap.AddNode("Torino");
        assertTrue(myHashmap.HasNode("Torino"));
        assertFalse(myHashmap.HasNode("Genova"));
    }

    @Test
    public void CheckDeleteNode() throws Exception {
        myHashmap.AddNode("Torino");
        myHashmap.AddNode("Milano");
        myHashmap.AddNode("Genova");
        myHashmap.AddLink("Milano", "Torino", 300);
        myHashmap.DeleteNode("Milano");
        assertFalse(myHashmap.HasNode("Milano"));
        assertTrue(myHashmap.HasNode("Torino"));
        //TODO: Test if in the Milano node the node 'Torino' still exists or not. Shouldn't exists.
    }

    @Test
    public void CheckDeleteLink() {
        //ADD
    }

    @Test
    public void CheckNumberOfNodes() throws Exception {
        myHashmap.AddNode("Torino");
        myHashmap.AddNode("Milano");
        myHashmap.AddNode("Genova");

        assertTrue(3 == myHashmap.GetNumberOfNode());
        assertFalse(4 == myHashmap.GetNumberOfNode());
    }

    @Test
    public void CheckNumberOfLinks() throws Exception {
        myHashmap.AddNode("Torino");
        myHashmap.AddNode("Milano");
        myHashmap.AddNode("Genova");
        myHashmap.AddLink("Torino", "Milano", 150);
        myHashmap.AddLink("Torino", "Genova", 100);
        assertTrue(2 == myHashmap.GetNumberOfLinks());
        assertFalse(3 == myHashmap.GetNumberOfLinks());
    }

    @Test
    public void CheckGetNodes() throws Exception {
        myHashmap.AddNode("Torino");
        myHashmap.AddNode("Milano");
        myHashmap.AddNode("Genova");

        ArrayList<String> myNodes = myHashmap.GetNodes();

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
        assertTrue(myHashmapDirect.IsDirect() == true);
        assertTrue(myHashmapNotDirect.IsDirect() == false);
    }
}