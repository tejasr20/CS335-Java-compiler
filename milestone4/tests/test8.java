public class test8 {
    public static void main(String[] args) {
        // Using a for loop
        for (int i = 1; i <= 10; i++) {
			for(int j=0;j<10;j++)
			{
				System.out.println(i);
				if(i==7) break;
				if(i==1) continue;
			}
            
        }
        
        // Using a while loop
        int j = 1;
        while (j <= 10) {
            System.out.println(j);
            j++;
        }
    }
}

