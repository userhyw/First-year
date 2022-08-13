#include "Link.h"
void init();//������Ϣ����
int main(void)
{
        GraphLink GLink;
         int select = -1;
         while(select != 1008611)
         {
                init();
                cin >> select;
                memset(visited, 0, sizeof(visited));//visited�����ظ�ʹ�û����
                system("cls");
                switch(select)
                {
                case 0:
                    {
                        char s[100];
                        cout << "�������ļ��ĵ�ַ��" << endl;
                        cin >> s;
                        bool f  = CreateGraphFromFileLink(s, GLink);
                        f ? cout << "�����ɹ���" << endl : cout << "�������ִ���" << endl;

                        break;
                    }
                case 1:
                    {
                        char v_m[100];
                        cout << "���뿪ʼ�ĵ��ֵ��";
                        cin >> v_m;
                        char *p = v_m;
                        cout << "DFS: " << endl;
                        while(*p)
                        {
                            int c = LocateVertexLink(GLink, *p);
                            DFS(GLink, c);
                            p++;
                        }

                        NEWLINE;
                        memset(visited, 0, sizeof(visited));//visited�����ظ�ʹ�û����
                        cout << "BFS: " << endl;
                        BFS(GLink, v_m);

                        break;
                    }
                case 2:
                    {
                        cout << "��ͼ�ߵ���ĿΪ��";
                        cout << GLink.ArcNum << endl;
                        break;
                    }
                case 3:
                    {
                        char s_a[100];
                        cout << "�����뿪ʼ�Ľڵ�ֵ��";
                        cin >> s_a;
                        csNode *Head = NULL;
                        FindCreat(GLink, Head, s_a);

                        cout << "�������ɭ�����£�" << endl;
                        FirstTravel(Head);

                        NEWLINE;
                        cout << "�������ɭ�����£�" << endl;
                        LastTravel(Head);

                        break;
                    }
                case 4:
                    {
                        char m_p[100];
                        csNode *Head;
                        cout << "���뿪ʼ�Ľڵ��ֵ: ";
                        cin >> m_p;

                        BFSForest(GLink, m_p, Head);

                        cout << "�������ɭ�����£�" << endl;
                        FirstTravel(Head);

                        NEWLINE;
                        cout << "�������ɭ�����£�" << endl;
                        LastTravel(Head);


                        break;
                    }
                case 5:
                    {
                        cout << "Prime: " << endl;
                        Prime(GLink);
                        break;
                    }
                case 6:
                    {
                        cout << "Krusal: " << endl;
                        Krusal(GLink);
                        break;
                    }
                case 7:
                    {
                        cout << "Dijkstra: " << endl;
                        char c;
                        cin >> c;
                        Dijkstra(GLink,c);
                        break;
                    }
                case 8:
                    {
                        cout << "Floyd :" << endl;
                        char c;
                        cin >> c;
                        Floyd(GLink, c);
                        break;
                    }
                case 9:
                    {
                        cout << "Top: " << endl;
                        Top(GLink);
                        break;
                    }
                case 10:
                    {
                        cout << "AOE: " << endl;
                        AOE(GLink);
                        break;
                    }
                case 77:
                    {
                        DestroyGraphLink(GLink);
                        cout << "ɾ����ϣ�" << endl;
                        break;
                    }
                default :
                    break;
                }
                system("pause");
                system("cls");
         }
    return 0;
}

//������Ϣ����
void init()
{
    cout << "0.��������ļ���ַ������ͼ" << endl;
    cout << "1.��ӡ��ͼ�����������ֱ�����" << endl;
    cout << "2.�����ͼ�еıߣ��򻡣�����Ŀ" << endl;
    cout << "3.�Ը�����ͼG��������v0������㷨��V0����������ȱ���ͼG�����������Ӧ��������������ɭ��" << endl;
    cout << "4.�Ը�����ͼG��������v0������㷨��V0����������ȱ���ͼG�����������Ӧ��������������ɭ��" << endl;
    cout << "5.ʵ��Prim�㷨��������и���ͼG����С������" << endl;
    cout << "6.ʵ��Kruskal�㷨��������и���ͼG����С������" << endl;
    cout << "7.ʵ��Dijkstra�㷨��������и���ͼGָ�����㵽���ඥ��֮������·��" << endl;
    cout << "8.ʵ��Floyd�㷨��������и���ͼG������֮������·��" << endl;
    cout << "9.����㷨������и���ͼG����������" << endl;
    cout << "10.����㷨������и���AOE���Ĺؼ�·��" << endl;
    cout << "77.ɾ����ǰͼ" << endl;
    cout << "����------1008611-----�˳�" << endl;
}





