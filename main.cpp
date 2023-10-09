#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class ManageProduct
{
private:
    static const int maxProducts = 50;
    string products[maxProducts];
    int count = 0;

public:
    void addProduct(const string &productName)
    {
        if (count < maxProducts)
        {
            products[count] = productName;
            count++;
        }
        else
        {
            cout << "Maximum product limit reached." << endl;
        }
    }
    const string *getProducts()
    {
        return products;
    }

    int getProductCount() const
    {
        return count;
    }
};




class OrderManager
{
private:
    string filename = "orders.csv";
    ofstream file;

public:
    OrderManager()
    {
        file.open(filename, ios::app); // Open the file in append mode in the constructor
        if (!file.is_open())
        {
            cout << "Failed to open the file for saving orders." << endl;
        }
    }


    void addOrder(const string &order)
    {
        file << order << endl;
        cout << "Order saved successfully!" << endl;
    }

    
    ~OrderManager()
    {
        if (file.is_open())
        {
            file.close(); // Close the file in the destructor
        }
    }
};




class Inventory
{
private:
    ManageProduct manageProduct;
    OrderManager orderManager;

public:
    void addProduct()
    {
        char userChoice;

        do
        {
            string productName;
            cout << "\nEnter the Product name: ";
            cin >> productName;
            manageProduct.addProduct(productName);

            cout << "\nDo you want to add more?\nPress 'y' for yes or 'n' for no: ";
            cin >> userChoice;
        } while (userChoice == 'y');

        cout << "\nThe products you entered are:\n";
        string order;
        const string * products = manageProduct.getProducts();
        int productCount = manageProduct.getProductCount();
        for (int i = 0; i < productCount; i++)
        {
            cout << i + 1 << ". " << products[i] << endl;
            order += products[i] + ",";
        }
         orderManager.addOrder(order);
    }
};

class Italian
{
public:
    void display()
    {
        cout << "\n\tItalian cuisine:" << endl;
        cout << "\n\tSR  Meal                           Price";
        cout << "\n\t1.  Pasta.                         150";
        cout << "\n\t2.  Pizza                          1200";
        cout << "\n\t3.  Italian Salad.                 150";
        cout << "\n\t4.  Arancini.                      150";
        cout << "\n\t5.  Focaccia.                      1500";
        cout << "\n\t6.  Italian Cheese.                1250";
        cout << "\n\t7.  Lasagna.                       1000";
        cout << "\n\t8.  Ossobuco.                      200";
        cout << "\n\t9.  Risotto.                       80";
        cout << "\n\t10. Truffles.                      250";
    }
};

class Chinese
{
public:
    virtual void display()
    {
        cout << endl;
        cout << "\n\tChinese cuisine:" << endl;
        cout << "\n\tSR  Meal                                      Price";
        cout << "\n\t1.  Maggi Manchurian.                         150";
        cout << "\n\t2.  Aloo Manchurian.                          1200";
        cout << "\n\t3.  Thicker Sweet Corn Soup Indian Style.     150";
        cout << "\n\t4.  Cheese Schezwan Sandwich.                 150";
        cout << "\n\t5.  Idli Manchurian.                          1500";
        cout << "\n\t6.  Chinese Chicken Cutlet .                  1250";
        cout << "\n\t7.  Chilli Chicken Open Toast.                1000";
        cout << "\n\t8.  Veg Noodle Soup.                          200";
        cout << "\n\t9.  Bread Manchurian.                         80";
        cout << "\n\t10. Chinese Mutton Cubes.                     250";
    }
};

class Cuisine : public Italian, public Chinese
{
public:
    void display()
    {
        Italian::display();
        Chinese::display();
    }
};

class MainMenu
{
public:
    void display()
    {
        cout << "\n\n";
        cout << "\t\tPress 1 to See the main menu.\n";
        cout << "\t\tPress 2 to Add items to buy.\n";
    }
};

int main()
{

    MainMenu mainMenu;
    mainMenu.display();
    Inventory inventory;
    Cuisine cuisine;

    int choice;
    cout << "\n\n\tWhere do you want to go now???";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\tYou are here to see main menu\n";
        cuisine.display();

        break;

    case 2:
        cout << "\n\tYou are here to add a Product\n";
        inventory.addProduct();
        break;

    default:
        cout << "\n\tEnter one of the specific options given above";
        break;
    }

    return 0;
}