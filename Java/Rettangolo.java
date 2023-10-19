
/**
 * All'interno di questo codice avviene instanziamento della classe Rettangolo, con i suoi attributi e metodi
 * 
 * @author antonio
 * @version 19/10
 */

import java.math.RoundingMode;
import java.text.DecimalFormat;


public class Rettangolo
{
    //attributi
    private float base = 0;
    private float altezza = 0;
    
    private static final DecimalFormat df = new DecimalFormat("0.00");

    //costruttore
    public Rettangolo (float base, float altezza){
        setBase(base);
        setAltezza(altezza);
    }
    
    //getter
    public float getBase(){return base;}
    public float getAltezza(){return altezza;}
    
    //setter
    public void setBase(float base){this.base = base;}
    public void setAltezza(float altezza){this.altezza = altezza;}
    
    //metodi
    public float calculateArea(){
        float area = getBase() * getAltezza();
        return area;
    }
    public float calculatePerimeter(){
        float perimetro = (getBase()*2) + (getAltezza()*2);
        return perimetro;
    }
    public String toString(){return "Il rettangolo di base: " + df.format(base) + ", e di altezza: " + df.format(altezza) + ". Ha un perimetro pari a: " + df.format(calculatePerimeter()) + ", e ha un area pari a: " +  df.format(calculateArea());}
}
