package src.unittest;

import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;

import src.unionfindset.*;


public class UnitTest {
    
    public UnionFindSet<Integer> mySet;


    @Before 
    public void createStruct() {
        mySet = new UnionFindSet<Integer>();
       
        mySet.MakeSet(5);
        mySet.MakeSet(10);
        mySet.MakeSet(15);
        mySet.MakeSet(20);
    }


    @Test 
    public void MakeSet() {
        //without a union the father of the element should be the element itself, so by testing without union, 
        //all of the items should be the same
        assertEquals(5, mySet.FindSet(5).intValue());
        assertEquals(15, mySet.FindSet(15).intValue());
        assertEquals(10, mySet.FindSet(10).intValue());
        assertEquals(20, mySet.FindSet(20).intValue());
    }

    @Test
    public void testUnion() {
        mySet.Union(5,10);
        assertEquals(10, mySet.FindSet(5).intValue());
        assertEquals(10, mySet.FindSet(10).intValue());

        mySet.Union(15,20);
        assertEquals(20, mySet.FindSet(15).intValue());
        assertEquals(20, mySet.FindSet(20).intValue());

        mySet.Union(10, 20);
        assertEquals(20, mySet.FindSet(5).intValue());
        assertEquals(20, mySet.FindSet(15).intValue());
        assertEquals(20, mySet.FindSet(10).intValue());
        assertEquals(20, mySet.FindSet(20).intValue());
    }

    
}