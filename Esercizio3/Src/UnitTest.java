package src;
import java.util.Comparator;
import static org.junit.Assert.*;
import org.junit.Before;
import org.junit.Test;


public class UnitTest {
    
    UnionFindSet<Integer> firstElem;
    UnionFindSet<Integer> secondElem;

    @Before 
    public void createStruct() {
        firstElem = new UnionFindSet<>(5);
        secondElem = new UnionFindSet<>(10);
    }

    @Test 
    public void testNewElement() {
        assertEquals(0, firstElem.GetRank());
        assertSame(firstElem, firstElem.GetParent());
    }

    @Test
    public void testUnion() {
        firstElem.Union(firstElem, secondElem);
        assertSame(secondElem, firstElem.GetParent());
        assertEquals(0, firstElem.GetRank());
        assertEquals(1, secondElem.GetRank());
        assertEquals(5, firstElem.GetValue());
        assertEquals(10, firstElem.GetParent().GetValue());
    }
}