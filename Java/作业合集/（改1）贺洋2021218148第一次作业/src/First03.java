import java.util.Scanner;
public class First03 {
    public static void main(String[] args){
        double Tmp;//Tmp表示温度

        System.out.println("请输入摄氏温度，我们将把其转为华氏温度并输出：");
        Scanner sc = new Scanner(System.in);

        Tmp = sc.nextInt();

        Tmp = (9/5.) * Tmp + 32;//小数点不要忘记，不然前面的计算会变为int类型，导致结果的小数位完全丢失

        System.out.print("该温度对应的华氏温度为：");
        System.out.println(Tmp + "℉");

    }
}
