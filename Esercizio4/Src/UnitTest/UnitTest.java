package Src.UnitTest;

import Src.Graph.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;


public class UnitTest {
    public Graph<String,Integer> myHashmap; 

    @Before
    public void CreateStruct() {
        myHashmap = new Graph<String, Integer>();
    }

    @Test
    public void CreateNullGraph() {
        assertTrue(myHashmap instanceof Graph<?,?>);
    }

    @Test
    public void AddNodes() {
        myHashmap.AddNode("Torino");
        myHashmap.AddNode("Milano");
        myHashmap.AddNode("Genova");
        assertTrue(myHashmap.HasNode("Torino"));
        assertTrue(myHashmap.HasNode("Milano"));
        assertTrue(myHashmap.HasNode("Genova"));
        assertFalse(myHashmap.HasNode("Venezia"));
    }


}