package src.graph;

public class Links<T, G>{
    private T node1;
    private T node2;
    private G weight;

    public Links(T node1, T node2, G weight) {
        this.node1 = node1;
        this.node2 = node2;
        this.weight = weight;
    }

    public T getNode1() {
        return this.node1;
    }

    public T getNode2() {
        return this.node2;
    }

    public G getWeight() {
        return this.weight;
    }

    /**
     * This method first chech if the weight var is an instance of a type in wich is possible to run a comparson
     * the if it is it compares the two elements otherwise it throws a classCastException
     * @param o the other to compare this element with
     * @return 0 if they are equals, 1 if o is smaller than this; -1 otherwise
     */
    public int compareTo(Links<T, G> o) throws ClassCastException{
        if(weight instanceof Byte){
            if(o.getWeight() == this.weight) return 0;
            else if((Byte)o.getWeight() > (Byte)this.weight) return -1;
            else return 1;
        }
        else if(weight instanceof Short){
            return (Short)o.getWeight() - (Short)this.weight;   
        }
        else if(weight instanceof Integer){
            if(o.getWeight() == this.weight) return 0;
            else if((Integer)o.getWeight() > (Integer)this.weight) return -1;
            else return 1;
        }
        else if(weight instanceof Long){
            if(o.getWeight() == this.weight) return 0;
            else if((Long)o.getWeight() > (Long)this.weight) return -1;
            else return 1;
        }
        else if (weight instanceof Float){
            if(o.getWeight() == this.weight) return 0;
            else if((Float)o.getWeight() > (Float)this.weight) return -1;
            else return 1;
        }
        else if(weight instanceof Double){
            if(o.getWeight() == this.weight) return 0;
            else if((Double)o.getWeight() > (Double)this.weight) return -1;
            else return 1;
        }  
        else throw new ClassCastException("G type is not applicable to comparable!");
    }
}
