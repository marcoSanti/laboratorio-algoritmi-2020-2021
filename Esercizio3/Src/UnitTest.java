package src;
import java.util.Comparator;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;


public class UnitTest {
    
    UnionFindSet<Integer> mySet;

    @Before 
    public void createStruct() {
        mySet = new UnionFindSet();
        mySet.MakeSet(5);
        mySet.MakeSet(10);
        mySet.MakeSet(15);
    }

    @Test 
    public void testNewElement() {
        assertEquals(15, mySet.myList.GetValue().intValue());
        assertEquals(10, mySet.myList.GetNextInList().GetValue().intValue());
        assertEquals(5, mySet.myList.GetNextInList().GetNextInList().GetValue().intValue());
    }

    @Test
    public void testUnion() {
        mySet.Union(mySet.myList, mySet.myList.GetNextInList());
        mySet.Union(mySet.myList, mySet.myList.GetNextInList().GetNextInList());
        assertSame(mySet.myList.GetParent(), mySet.myList.GetNextInList().GetParent());
        assertSame(mySet.myList.GetParent(), mySet.myList.GetNextInList().GetNextInList().GetParent());
    }

    @Test
    public void flattensTree() {
        mySet.myList.GetNextInList().SetParent(mySet.myList);
        mySet.myList.GetNextInList().GetNextInList().SetParent(mySet.myList.GetNextInList());
        mySet.FindSet(mySet.myList.GetNextInList().GetNextInList());
        assertSame(mySet.myList, mySet.myList.GetNextInList().GetParent());
        assertSame(mySet.myList, mySet.myList.GetNextInList().GetNextInList().GetParent());
    } 
}