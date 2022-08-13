package Second2_1;
import java.util.Scanner;
class Person{
    String ID;
    String Name;
    String Email;

    public void SetInf(){
        System.out.println("请分别输入此人的ID、Name、Email：");
        Scanner read = new Scanner(System.in);
        ID = read.nextLine();
        Name = read.nextLine();
        Email = read.nextLine();
    }

    public String toString(){
        return "此人的ID为：" + ID + "/n"
                + "此人的Name为：" + Name + "\n"
                + "此人的Email为：" + Email + "\n";
    }
}

class Student extends Person{
    String ClassRoom;

    public String toString(){
        return "该学生的ID为：" + this.ID + "/n"
                + "该学生的Name为：" + this.Name + "\n"
                + "该学生的Email为：" + this.Email + "\n"
                + "该学生的ClassRoom为：" + this.ClassRoom + "\n";
    }
    public void SetInf(){
        System.out.println("请分别输入该学生的ID、Name、Email、Classroom：");
        Scanner read = new Scanner(System.in);
        this.ID = read.nextLine();
        this.Name = read.nextLine();
        this.Email = read.nextLine();
        this.ClassRoom = read.nextLine();
    }

}

class Employee extends Person{

    public String toString(){
        return "该雇员的ID为：" + this.ID + "/n"
                + "该雇员的Name为：" + this.Name + "\n"
                + "该雇员的Email为：" + this.Email + "\n";
    }
    public void SetInf(){
        System.out.println("请分别输入该雇员的ID、Name、Email：");
        Scanner read = new Scanner(System.in);
        this.ID = read.nextLine();
        this.Name = read.nextLine();
        this.Email = read.nextLine();
    }
}

class Faculty extends Employee{
    String MainCourse;
    String ProInf;

    public String toString(){
        return "该教师的ID为：" + this.ID + "/n"
                + "该教师的Name为：" + this.Name + "\n"
                + "该教师的Email为：" + this.Email + "\n"
                + "该教师的MainCourse为：" + this.MainCourse + "\n"
                + "该教师的ProInf为：" + this.ProInf + "\n";
    }

    public void SetInf(){
        System.out.println("请分别输入该教师的ID、Name、Email、MainCourse、ProInf：");
        Scanner read = new Scanner(System.in);
        this.ID = read.nextLine();
        this.Name = read.nextLine();
        this.Email = read.nextLine();
        this.MainCourse = read.nextLine();
        this.ProInf = read.nextLine();
    }
}

class Staff extends Employee{
    String JobInf;

    public String toString(){
        return "该职员的ID为：" + this.ID + "/n"
                + "该职员的Name为：" + this.Name + "\n"
                + "该职员的Email为：" + this.Email + "\n"
                + "该职员的JobInf为：" + this.JobInf + "\n";
    }

    public void SetInf(){
        System.out.println("请分别输入该职员的ID、Name、Email、JobInf：");
        Scanner read = new Scanner(System.in);
        this.ID = read.nextLine();
        this.Name = read.nextLine();
        this.Email = read.nextLine();
        this.JobInf = read.nextLine();
    }
}

public class Second02 {
    public static void main(String[] args) {

    }
}
