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
                cout << "����10�������֣� ����Ҫת���Ľ���" << endl;
                int x, y;
                cin >> x;
                cin >> y;
                s.convert(x, y);//�������s�У�
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
                  else{// A��ascii ��65;
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
                cout << "�����������ַ�����" << endl;
                cin >> m_s;

                bool flage = s.imatch(m_s);

                if (flage){
                    cout << "��ϲ�㣡��������ƥ���Ŷ��" << endl;
                }
                else{
                    cout << "���ź��������Ų���ƥ��ģ�" << endl;
                }
                break;
            }
          case 3:
            {
                char input[20], output[20];
                int len, i, j;
                cout << "�����������������У�"<< endl;
                cin >> input;
                cout << "���������������еĳ��ȣ�" << endl;
                cin >> len;
                i = 0;
                j = 0;

                s.iclear();//���ü�����

                s.AllList(input, output, len, i, j);
                break;
            }
          case 4:
            {
                    char input[20], output[20];
                    int n;
                cout << "�����������������У�"<< endl;
                cin >> input;
                cout << "������Ҫ�жϵĳ�ջ���У�" << endl;
                cin >> output;
                cout << "�������еĳ��ȣ�" << endl;
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
    cout << "����1������10���ƵĶ���ת���� " << endl;
    cout << "����2�����������Ƿ�ƥ��ʵ�飡" << endl;
    cout << "����3�� ����������кϷ���ջ���е�ʵ�飡" << endl;
    cout << "����4�� �����жϳ�ջ�����Ƿ�Ϸ���" << endl;
    cout << "����10086�˳���" << endl;
    cout << "--------------------------------------------------------" << endl;
}
