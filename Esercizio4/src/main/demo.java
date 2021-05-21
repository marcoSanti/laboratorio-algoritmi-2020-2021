package src.main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

import src.graph.*;
import src.kruskal.*;

public class demo {

    public static Graph<String, Float> ReadFromFile(String fileName) throws IOException, GraphExceptions {
        Graph<String, Float> myGraph = new Graph<String, Float>();
        BufferedReader myBF = new BufferedReader(new FileReader(fileName));
        String[] parts;
        String row;
        while ((row = myBF.readLine()) != null) {
            parts = row.split(",");
            if (!myGraph.HasNode(parts[0])) {
                myGraph.AddNode(parts[0]);
            }
            if (!myGraph.HasNode(parts[1])) {
                myGraph.AddNode(parts[1]);
            }
            myGraph.AddLink(parts[0], parts[1], Float.valueOf(parts[2]));
        }
        myBF.close();
        return myGraph;
    }

    public static void main(String[] args) {
        Graph<String, Float> myGraphWithCities = null;
        try {
            myGraphWithCities = ReadFromFile(args[0]);
        } catch (Exception e) {
            e.printStackTrace();
        }

        Kruskal<String, Float> myKruskal = null;
        try {
            myKruskal = new Kruskal<String, Float>(myGraphWithCities);
        } catch (Exception e) {
            e.printStackTrace();
        }

        ArrayList<Links<String, Float>> mstLinks = myKruskal.run();

        double somma = 0;
        for (Links<String, Float> l : mstLinks) {
            somma += l.getWeight();
        }
        System.out.printf("Somma totale archi: %.3f Km\n", somma / 1000);
        System.out.println("Numero Nodi: " + myKruskal.getMstNodes().GetNumberOfNode());
        System.out.println("Numero Archi: " + mstLinks.size());

    }
}