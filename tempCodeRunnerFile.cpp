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