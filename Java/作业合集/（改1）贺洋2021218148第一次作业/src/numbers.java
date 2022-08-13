public class numbers {
    public static void main(String[] args) {
        int [] a = new int[500];
        int j = 0;
        for (int i = 0; i < 500; i++){
            if (i%3 == 0 && i%5 == 0 && i%7 == 0){
                a[j] = i;
                j++;
            }
        }

        for(int i = 0; i < a.length; i++){
            System.out.println(a[i]);
        }
    }
}
