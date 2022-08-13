package Second1_5;

class Fruit{};
class Apple extends Fruit{};
class Orange extends Fruit{};
class GD extends Apple{};
class MT extends Apple{};

public class Second01 {
    public static void main(String[] args) {
        Fruit fruit = new GD();
        Orange orange = new Orange();

        System.out.println(fruit instanceof  Fruit);//true
        System.out.println(fruit instanceof  Orange);//false
        System.out.println(fruit instanceof  Apple);//ture
        System.out.println(fruit instanceof  GD);//ture
        System.out.println(fruit instanceof  MT);//false

    }
}
