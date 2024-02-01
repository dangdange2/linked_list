#include <iostream>
#include <conio.h>
using namespace std;

class Shape
{
    Shape *next;
    string name;
public:
    Shape(string name){this-> name = name;}
    Shape* add(Shape* shape){ this->next = shape; return shape; }
    Shape* getNext() { return next; }
    string getName() { return name; }
};

class GraphicEditor
{
    Shape *pStart = NULL;
    Shape *pLast;
public:
    void add_Shape(int type)
    {

        if(type == 1)
        {
            if(pStart==NULL)
            {
                pStart = new Shape("Line");
                pLast = pStart;
            }
            else
            {
                pLast = pLast->add(new Shape("Line"));
            }
        }
        else if(type==2)
        {
            if(pStart==NULL)
            {
                pStart = new Shape("Circle");
                pLast = pStart;
            }
            else
            {
                pLast = pLast->add(new Shape("Circle"));
            }
        }
        else if(type==3)
        {
            if(pStart==NULL)
            {
                pStart = new Shape("Rect");
                pLast = pStart;
            }
            else
            {
                pLast = pLast->add(new Shape("Rect"));
            }
        }
    }

    void delete_Shape(int index)
    {
        Shape* pBefore = pStart;
        Shape* pDelete = pStart;
        Shape* pNext = pStart;
        for(int i=0; i<index-1; i++)
        {
            pBefore = pBefore->getNext();
        }


        for(int i=0; i<index+1; i++)
        {
            pNext = pNext->getNext();
        }
        for(int i=0; i<index; i++)
        {
            pDelete = pDelete->getNext();
        }
        delete pDelete;
        pBefore = pBefore->add(pNext);
    }

    void show()
    {
        Shape* pShow = pStart;
        int i=0;
        while(pShow!=pLast)
        {
            cout << i << pShow->getName() << endl;
            pShow = pShow->getNext();
            i++;
        }
        cout << i << pShow->getName() << endl;
    }
};

int main()
{
    GraphicEditor g;
    int select;
    while(1)
    {
        cout << "삽입  : 1, 삭제 : 2, 모두보기 : 3, 종료 : 4 >> ";
        cin >> select;
        if(select==1)
        {
            cout <<"선 : 1, 원 : 2, 사각형 : 3 >> ";
            cin >> select;
            g.add_Shape(select);
            system("cls");
        }
        else if(select==2)
        {
            g.show();
            cout << "삭제하고자 하는 도형의 인덱스 >> ";
            cin >> select;
            g.delete_Shape(select);
            system("cls");
        }
        else if(select==3)
        {
            g.show();
            _getch();
            system("cls");
        }
        else break;
    }
}
