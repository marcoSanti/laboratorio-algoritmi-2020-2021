package src.main;
import java.io.BufferedReader;
import java.io.FileReader;
import src.graph;
import src.kruskal;
import src.links;

public class demo {

    public static Graph<String,Integer> ReadFromFile(String fileName) {
        Graph<String, Integer> myGraph = new Graph<String, Integer>();
        BufferedReader myBF = new BufferedReader(new FileReader(fileName));
        String[] parts; 
        while((row = myBF.readLine() != null)) {
            parts = row.split(",");
            if(!myGraph.hasNode(parts[0])) {
                myGraph.AddNode(parts[0]);
            }
            if(!myGraph.hasNode(parts[1])) {
                myGraph.AddNode(parts[1]);
            }
            myGraph.AddLink(parts[0], parts[1], Integer.valueOf(parts[2]));
        }
        return myGraph;
    }

    public static void main(String[] args) {
        Graph<String, Integer> myGraphWithCities = ReadFromFile(args[0]);
        Kruskal<String, Integer> myKruskal = new Kruskal(myGraphWithCities, Comparator.comparing(Integer::intValue));
        myKruskal.begin();
        int somma = 0;
        for(Links<String,Integer> l: myKruskal.getMstLinks()) {
            somma += l.getWeight().intValue();
        }
        System.out.println("Valore somma: " + somma);

    }
}