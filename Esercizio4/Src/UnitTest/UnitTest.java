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

    @Test 
    public void AddLinks() {
        myHashmap.AddNode("Torino");
        myHashmap.AddNode("Milano");
        myHashmap.AddNode("Genova");
        myHashmap.AddLink("Torino", "Milano", 150);
        myHashmap.AddLink("Torino", "Genova", 100);
        assertTrue(150 == myHashmap.GetWeight("Torino", "Milano"));
        assertTrue(100 == myHashmap.GetWeight("Torino", "Genova"));
        assertFalse(100000 == myHashmap.GetWeight("Torino", "Milano"));
    }
}