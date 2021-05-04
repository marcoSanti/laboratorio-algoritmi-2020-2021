package src;
import java.util.Comparator;
import static org.junit.Assert.assertArrayEquals;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertSame;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;


public class UnitTest {
    
    UnionFindSet<Integer> firstElem;

    @Before 
    public void createStruct() {
        firstElem = new UnionFindSet<>(5);
    }

    @Test 
    public void testNewElement() {
        assertEquals(0, firstElem.GetRank());
        assertSame(firstElem, firstElem.GetParent());
    }
}