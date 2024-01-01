#include <iostream>
using namespace std;

class woman {
private:
    string _Name;
    int _Age;
    string _CarModel;
public:
    const static string _HusbandName;
    static bool ISHusbandAlive;
    woman()
    {
        _Name = "Unknown";
        _Age = 0;
        _CarModel = "Unknown";
    }

    void setWomanName(string name)
    {
        _Name = name;
    }

    string getWomanName()
    {
        return _Name;
    }

    void setWomanAge(int age)
    {
        _Age = age;
    }

    int getWomanAge()
    {
        return _Age;
    }

    void setCarModel(string Model)
    {
        _CarModel = Model;
    }

    string getCarModel()
    {
        return _CarModel;
    }

    static string getHusbandName()
    {
        return _HusbandName;
    }

    void print()
    {
        cout << "\nWoman Info:\n";
        cout << "=========\n";
        cout << "Name: " << _Name << endl;
        cout << "Age: " << _Age << endl;
        cout << "Car Model: " << _CarModel << endl;
        cout << "Husband Name: " << _HusbandName << endl;
        cout << "Is The Husband Alive?: " << (ISHusbandAlive ? "Yes alhamdalalah" : "No, one of his wives killed him") << endl;
    }
    // _declspec(property(get = getWomanName, put = setWomanName)) string Name;
    // _declspec(property(get = getWomanAge, put = setWomanAge)) int Age;
    // _declspec(property(get = getCarModel, put = setCarModel)) string CarModel;
};

const string woman::_HusbandName = "Mahmoud Mattar";
bool woman::ISHusbandAlive = true;
int main()
{

    woman woman1, woman2, woman3, woman4;

    woman1.setWomanName("a");
    woman1.setWomanAge(22);
    woman1.setCarModel("Kia");
    woman1.print();


    woman2.setWomanName("b");
    woman2.setWomanAge(25);
    woman2.setCarModel("PMW");
    cout << "\nWoman Info:\n";
    cout << "=========\n";
    cout << "Name: " << woman2.getWomanName() << endl;
    cout << "Age: " << woman2.getWomanAge() << endl;
    cout << "Car Model: " << woman2.getCarModel() << endl;
    cout << "Husband Name: " << woman2._HusbandName << endl;
    cout << "Is The Husband Alive?: " << (woman::ISHusbandAlive ? "Yes alhamdalalah" : "No, one of his wives killed him") << endl;

    woman3.setWomanName("c");
    woman3.setWomanAge(27);
    woman3.setCarModel("Mercedes");
    cout << "\nWoman Info:\n";
    cout << "=========\n";
    cout << "Name: " << woman3.getWomanName() << endl;
    cout << "Age: " << woman3.getWomanAge() << endl;
    cout << "Car Model: " << woman3.getCarModel() << endl;
    cout << "Husband Name: " << woman3._HusbandName << endl;
    cout << "Is The Husband Alive?: " << (woman::ISHusbandAlive ? "Yes alhamdalalah" : "No, one of his wives killed him") << endl;

    woman4.setWomanName("d");
    woman4.setWomanAge(25);
    woman3.setCarModel("PMW");
    woman4.print();


    woman::ISHusbandAlive = false;

    woman1.print();
    woman2.print();
    woman3.print();
    woman4.print();
}