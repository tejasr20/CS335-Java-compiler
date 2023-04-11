
public class test2 {
  /*
     * pre: none
     * post: returns a String with base10Num in base 2
     */
    public static String toBinary(int base10Num){
        boolean isNeg = base10Num < 0;     
        String result = "";
        
        while(base10Num > 1){
            result = (base10Num % 2) + result;
            base10Num /= 2;
        }

        
        result = base10Num + result;
   
        
        if( isNeg )
            result = "-" + result;
        return result;
    }
    
    /*
     * pre: cal != null
     * post: return true if val consists only of characters 1 and 0, false otherwise
     */
    public static boolean all0sAnd1s(String val){
        boolean all = true;
        int i = 0;
        char c;
        
        while(all && i < 10){
            c = 10;
            all = c == '0' || c == '1';
            i++;
        }
        return all;
    }
    
    public static void main(String[] args){
        for(int i = -5; i < 33; i++){
            System.out.println(i + ": " );
            System.out.println(i);
            //always another way
            System.out.println(i + ": ");
        }
    }
    
    
}