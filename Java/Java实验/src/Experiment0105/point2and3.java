package Experiment0105;

public class point2and3 {
    public static void main(String[] args) {
        //实例化两个二维变量
        Point2D p2d1 = new Point2D(1,0);
        Point2D p2d2 = new Point2D(0,1);

        //实例化两个三维变量
        Point3D p3d1 = new Point3D(1,0,0);
        Point3D p3d2 = new Point3D(0,1,1);

        //创造两个用于记录点之间的距离的变量
        double d1, d2;
        d1 = disTance(p2d1,p2d2);
        d2 = disTance(p3d1,p3d2);

        //输出点之间的距离在控制台
        System.out.printf("p2d1与p2d2的距离为：%.3f\n", d1);
        System.out.printf("p3d1与p3d2的距离为：%.3f\n", d2);

        //对点进行平移
        p2d1.offset(1, 1);
        p3d1.offset(1,1,1);
        d1 = disTance(p2d1,p2d2);
        d2 = disTance(p3d1,p3d2);

        //输出点之间的距离在控制台
        System.out.println("p2d1, p3d1都平移一个长度后：");
        System.out.printf("p2d1与p2d2的距离为：%.3f\n", d1);
        System.out.printf("p3d1与p3d2的距离为：%.3f\n", d2);
    }

//创建父类二维点               //解决方法有二：1.在类前面加上static，2.把这些方法拿到point2and3外面去实现
private static class Point2D//main是静态方法，这些类都是point2and3成员，静态方法只能访问静态成员。
{
    //成员变量x和y
    private int x, y;

    //无参构造器，一定要有
    Point2D(){}

    //构造函数实现二维点的初始化
    Point2D(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
    //成员函数实现二维点的平移
    public void offset(int a, int b)
    {
        this.x += a;
        this.y += b;
    }

}

//三维点直接继承二维点
private static class Point3D extends Point2D {
        //创建三维点的成员变量
    private int x, y, z;
    Point3D(){}//同上

    //构造函数实现三维点的初始化
    Point3D(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    //传入父类对子类初始化
    Point3D(Point2D p, int z)
    {
        this.x = p.x;
        this.y = p.y;
        this.z = z;
    }

    //成员函数实现三维点的平移
    public void offset(int a, int b, int c)
    {
        this.x += a;
        this.y += b;
        this.z += c;
    }

}

//函数实现二维点之间的距离
static double disTance(Point2D p1, Point2D p2)
{
    double d;
    d = Math.sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    return d;
}

//函数实现三维点之间的距离
static double disTance(Point3D p1, Point3D p2)
{
    double d;
    d = Math.sqrt((double)(p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) + (p1.z - p2.z) * (p1.z - p2.z));
    return d;
}

}
