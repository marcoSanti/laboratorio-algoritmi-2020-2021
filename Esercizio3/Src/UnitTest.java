package test;
import lib.*;
import org.junit.*;
import static org.junit.Assert.assertEquals;

public class UnitTest {
    
    @Test 
    public void testNoRank() {
        UnionFindSet firstElem = new UnionFindSet();
        assertEquals(0, firstElem.GetRank());
    }
}