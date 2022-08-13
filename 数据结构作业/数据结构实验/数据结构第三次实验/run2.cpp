#include "linkedStack.h"

void init();

int main(void)
{
    LinkStack s;

        int select = -1;
    do{
            init();
            cin >> select;
            system("cls");
            switch(select)
            {
          case 1:
            {
                cout << "输入10进制数字， 输入要转换的进制" << endl;
                int x, y;
                cin >> x;
                cin >> y;
                s.convert(x, y);//结果存入s中！
                if(x < 0){
                    cout << "-";
                }
                while (!s.iempty()){
                  int z;
                  s.getTop(z);
                  s.pop();
                  if (z < 10){
                    cout << z;
                  }
                  else{// A的ascii 是65;
                        int m_c;
                        m_c = 65 + (z - 10);
                        cout << (char) m_c;
                        }
                    }
                  break;
            }

          case 2:
            {
                char m_s[20];
                cout << "请输入您的字符串：" << endl;
                cin >> m_s;

                bool flage = s.imatch(m_s);

                if (flage){
                    cout << "恭喜你！，括号是匹配的哦！" << endl;
                }
                else{
                    cout << "很遗憾！，括号不是匹配的！" << endl;
                }
                break;
            }
          case 3:
            {
                char input[20], output[20];
                int len, i, j;
                cout << "请输入您的输入序列："<< endl;
                cin >> input;
                cout << "输入您的输入序列的长度：" << endl;
                cin >> len;
                i = 0;
                j = 0;

                s.iclear();//重置计数器

                s.AllList(input, output, len, i, j);
                break;
            }
          case 4:
            {
                    char input[20], output[20];
                    int n;
                cout << "请输入您的输入序列："<< endl;
                cin >> input;
                cout << "输入您要判断的出栈序列：" << endl;
                cin >> output;
                cout << "输入序列的长度：" << endl;
                cin >> n;

                s.iright(input, output, n);
                break;
            }
        default:
            break;
            }
            system("pause");
            system("cls");
    }while(select != 10086);



    return 0;
}


void init()
{
    cout << "--------------------------------------------------------" << endl;
    cout << "输入1，进行10进制的多项转换！ " << endl;
    cout << "输入2，进行括号是否匹配实验！" << endl;
    cout << "输入3， 进行求出所有合法出栈序列的实验！" << endl;
    cout << "输入4， 进行判断出栈序列是否合法！" << endl;
    cout << "输入10086退出！" << endl;
    cout << "--------------------------------------------------------" << endl;
}
