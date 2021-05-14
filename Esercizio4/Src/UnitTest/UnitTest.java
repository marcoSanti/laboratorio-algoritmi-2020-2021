package Src.UnitTest;
import java.util.HashMap;
import Src.Graph.*;
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
        myHashmapDirect = new Graph<String, Integer>(false);
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
        assertFalse(myHashmap.HasNode("Torino"));
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
        String[] myNodes = new String[3];
        myNodes = myHashmap.GetNodes();
        assertTrue("Torino" == myNodes[0]);
        assertTrue("Milano" == myNodes[1]);
        assertTrue("Genova" == myNodes[2]);
        assertFalse("Genova" == myNodes[0]);
        assertFalse("Napoli" == myNodes[2]);
    }

    @Test
    public void CheckForDirect() throws Exception {
        assertTrue(myHashmapDirect.IsDirect() == true);
        assertTrue(myHashmapNotDirect.IsDirect() == false);
    }
}