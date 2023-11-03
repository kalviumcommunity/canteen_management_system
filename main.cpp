#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

class ManageProduct
{
private:
    static const int maxProducts = 50;
    string products[maxProducts];
    static int count;
    vector<string> menu = {
        "Pasta - Price: 150",
        "Pizza - Price: 1200",
        "Italian Salad - Price: 150",
        "Arancini - Price: 150",
        "Focaccia - Price: 1500",
        "Italian Cheese - Price: 1250",
        "Lasagna - Price: 1000",
        "Ossobuco - Price: 200",
        "Risotto - Price: 80",
        "Truffles - Price: 250",
        "Maggi Manchurian - Price: 150",
        "Aloo Manchurian - Price: 1200",
        "Thicker Sweet Corn Soup Indian Style - Price: 150",
        "Cheese Schezwan Sandwich - Price: 150",
        "Idli Manchurian - Price: 1500",
        "Chinese Chicken Cutlet - Price: 1250",
        "Chilli Chicken Open Toast - Price: 1000",
        "Veg Noodle Soup - Price: 200",
        "Bread Manchurian - Price: 80",
        "Chinese Mutton Cubes - Price: 250"};

public:
    void addProduct(const int &productNumber)
    {
        if (count < maxProducts)
        {
            products[count] = menu[productNumber - 1];
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

int ManageProduct::count = 0;

class OrderManager
{
private:
    string filename = "orders.csv";
    ofstream file;

public:
    void addOrder(const string &order)
    {
        file.open(filename, ios::app); 
        if (!file.is_open())
        {
            cout << "Failed to open the file for saving orders." << endl;
        }
        file << order << endl;
        cout << "Order saved successfully!" << endl;
        if (file.is_open())
        {
            file.close(); 
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
        cout << "Enter your name: ";
        string customerName;
        cin >> customerName;

        string order = customerName + ": "; 

        do
        {
            int productNumber;
            cout << "\nEnter the Product number from menu: ";
            cin >> productNumber;

            if (productNumber > 0 && productNumber <= 20)
            {
                manageProduct.addProduct(productNumber);
            }
            else
            {
                cout << "Please provide a valid number" << endl;
            }

            cout << "\nDo you want to add more?\nPress 'y' for yes or 'n' for no: ";
            cin >> userChoice;
        } while (userChoice == 'y');

        cout << "\nThe products you entered are:\n";
        const string *products = manageProduct.getProducts();
        int productCount = manageProduct.getProductCount();

        for (int i = 0; i < productCount; i++)
        {
            cout << i + 1 << ". " << products[i] << endl;
            order += products[i] + ",";
        }
        orderManager.addOrder(order);
    }
};

class Cuisine
{
public:
    vector<string> virtual display() = 0;
};

class Italian : public Cuisine
{
public:
    vector<string> display() override
    {
        cout << "\n\tItalian cuisine:" << endl;
        vector<string> menu;
        menu.push_back("Pasta - Price: 150");
        menu.push_back("Pizza - Price: 1200");
        menu.push_back("Italian Salad - Price: 150");
        menu.push_back("Arancini - Price: 150");
        menu.push_back("Focaccia - Price: 1500");
        menu.push_back("Italian Cheese - Price: 1250");
        menu.push_back("Lasagna - Price: 1000");
        menu.push_back("Ossobuco - Price: 200");
        menu.push_back("Risotto - Price: 80");
        menu.push_back("Truffles - Price: 250");

        return menu;
    }
};

class Chinese : public Cuisine
{
public:
    vector<string> display() override
    {
        cout << "\n\tChinese cuisine:" << endl;
        vector<string> menu;
        menu.push_back("Maggi Manchurian - Price: 150");
        menu.push_back("Aloo Manchurian - Price: 1200");
        menu.push_back("Thicker Sweet Corn Soup Indian Style - Price: 150");
        menu.push_back("Cheese Schezwan Sandwich - Price: 150");
        menu.push_back("Idli Manchurian - Price: 1500");
        menu.push_back("Chinese Chicken Cutlet - Price: 1250");
        menu.push_back("Chilli Chicken Open Toast - Price: 1000");
        menu.push_back("Veg Noodle Soup - Price: 200");
        menu.push_back("Bread Manchurian - Price: 80");
        menu.push_back("Chinese Mutton Cubes - Price: 250");

        return menu;
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
    // Italian italian;
    // Chinese chinese;

    int choice;
    cout << "\n\n\tWhere do you want to go now???";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\tYou are here to see main menu\n";
        Cuisine *cuisinePtr[2];
        int choice;
        cout << "\n\tChoose a cuisine:\n";
        cout << "\n\t1. Italian\n";
        cout << "\n\t2. Chinese\n";
        cout << "\n\tEnter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cuisinePtr[0] = new Italian;
            vector<string> display = cuisinePtr[0]->display();
            for (int i = 0; i < display.size(); i++)
            {
                cout << i + 1 << ". " << display[i] << endl;
            }
        }
        else if (choice == 2)
        {
            cuisinePtr[1] = new Chinese;
            vector<string> display = cuisinePtr[1]->display();
            for (int i = 0; i < display.size(); i++)
            {
                cout << i + 11 << ". " << display[i] << endl;
            }
        }
        else
        {
            cout << "Invalid choice.\n";
        }

        // Deallocate memory
        for (int i = 0; i < 2; i++) {
                if (cuisinePtr[i]) {
                    delete cuisinePtr[i];
                }
        }

        
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