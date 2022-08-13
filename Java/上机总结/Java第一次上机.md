# Java数据类型

## 基本数据类型

1. 基本数据类型：数值型、字符型、布尔型

2. 数值型：1.. 整数类型：byte、short、int、 long； 2.. 浮点类型：float、 double；

3. 字符型：char（占两个字节）---联系Unicode码；

4. 布尔型：boolean（一个字节）-----ture / false；

## 引用数据类型

1. 类：class；

2. 接口：interface；

3. 数组：[]；

# jdk环境变量配置、以及环境变量作用详解

1. PATH环境变量。作用是指定命令搜索路径，在命令行下面执行命令如javac编译java程序时，它会到PATH变量所指定的路径中查找看是否能找到相应的命令程序。我们需要把jdk安装目录下的bin目录增加到现有的PATH变量中，bin目录中包含经常要用到的可执行文件如javac/java/javadoc等待，设置好PATH变量后，就可以在任何目录下执行javac/java等工具了
   ————————————————
   版权声明：本文为CSDN博主「若依不弃」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
   原文链接：https://blog.csdn.net/weixin_42213903/article/details/84017675

2. JAVA_HOME环境变量。它指向jdk的安装目录，Eclipse/NetBeans/Tomcat等软件就是通过搜索JAVA_HOME变量来找到并使用安装好的jdk

3. CLASSPATH是什么？它的作用是什么？
   ??它是javac编译器的一个环境变量。它的作用与import、package关键字有关。当你写下improt java.util.*时，编译器面对import关键字时，就知道你要引入java.util这个package中的类；但是编译器如何知道你把这个package放在哪里了呢？所以你首先得告诉编译器这个package的所在位置；如何告诉它呢？就是设置CLASSPATH啦 ? 如果java.util这个package在c:/jdk/ 目录下，你得把c:/jdk/这个路径设置到CLASSPATH中去！当编译器面对import java.util.*这个语句时，它先会查找CLASSPATH所指定的目录，并检视子目录java/util是否存在，然后找出名称吻合的已编译文件（.class文件）。如果没有找到就会报错！CLASSPATH有点像c/c++编译器中的INCLUDE路径的设置哦，是不是？当c/c++编译器遇到include 这样的语句，它是如何运作的？哦，其实道理都差不多！搜索INCLUDE路径，检视文件！当你自己开发一个package时，然后想要用这个package中的类；自然，你也得把这个package所在的目录设置到CLASSPATH中去！CLASSPATH的设定，对JAVA的初学者而言是一件棘手的事。所以Sun让JAVA2的JDK更聪明一些。你会发现，在你安装之后，即使完全没有设定CLASSPATH，你仍然能够编译基本的JAVA程序，并且加以执行。
   ??事实上JDK 5.0默认就会到当前工作目录(上面的.设置)，以及JDK的lib目录(这里假设是C:\Program Files\Java\jdk1.8.0_191\lib)中寻找Java程序。所以如果Java程序是在这两个目录中，则不必设置Classpath变量也可以找得到，将来如果Java程序不是放置在这两个目录时，则可以按以下方法设置Classpath
   ————————————————
   版权声明：本文为CSDN博主「若依不弃」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
   原文链接：https://blog.csdn.net/weixin_42213903/article/details/84017675



# 基础知识错误

1. 对于 == 符号的理解错误：== 符号返回的是一个bool值，故而当需要多个条件同时成立时需要使用 && 符号将其连接起来。


