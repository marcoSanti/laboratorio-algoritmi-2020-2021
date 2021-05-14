package Src.UnitTest;

import Src.Graph.*;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;


public class UnitTest {
    
    public Graph<String,Integer> myHasmap; 

    @Test
    public void CreateNullGraph() {
        myHasmap = new Graph<String, Integer>();
        assertTrue(myHasmap instanceof Graph<String,Integer>);
    }
}