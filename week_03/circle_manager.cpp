#include <iostream>
#include <string>
using namespace std;

class Circle
{
    int radius;
    string name;

public:
    void setCircle(string name, int radius)
    {
        this->name = name;
        this->radius = radius;
    } // constructor
    double getArea()
    {
        return 3.14 * radius * radius;
    } // return Area of circle (3.14 * r^2)
    string getName()
    {
        return name;
    } // return Name of circle
};

class CircleManager
{
    Circle *p; // Circle Array pointer
    int size;  // Array size
public:
    CircleManager(int size); // constructor to generate Circle Array
    ~CircleManager();
    void searchByName(); // Input name from user and output Area
    void searchByArea(); // Input area from user and output name of circle larger than area
};

CircleManager::CircleManager(int size)
{
    p = new Circle[size];
    this->size = size;
    string _name;
    int _radius;
    for (int i = 0; i < size; i++)
    {
        cin >> _name >> _radius;
        (p + i)->setCircle(_name, _radius);
    }
}

CircleManager::~CircleManager()
{
    delete[] p;
}

void CircleManager::searchByName()
{
    // string class == 으로 비교가능
    string search_name;
    bool flag = false;
    int i = 0;
    cin >> search_name;
    for (int i = 0; i < size; i++)
    {
        if ((p + i)->getName() == search_name)
        {
            flag = true;
            //존재할 경우 다음 출력
            cout << search_name << " Area is " << (p + i)->getArea() << endl;
        }
    }
    if (!flag)
        cout << search_name << " does not exist" << endl;
}

void CircleManager::searchByArea()
{
    int search_area;
    bool flag = false;
    int i = 0;
    cin >> search_area;
    for (int i = 0; i < size; i++)
    {
        if ((p + i)->getArea() >= search_area)
        {
            flag = true;
            //존재할 경우 :
            cout << (p + i)->getName() << " Area is " << (p + i)->getArea() << ',';
        }
    }
    if (!flag)
        cout << "circle that is bigger than " << search_area << " does not exist.";
}

int main(void)
{

    CircleManager *pManager;
    int size;
    cin >> size;
    if (size <= 0)
    {
        cout << "Array size must be positive !" << endl;
        return 0;
    }

    pManager = new CircleManager(size);
    pManager->searchByName();
    pManager->searchByArea();
    delete pManager;

    return 0;
}