#include <iostream>
#include <string.h>
#include <iomanip>
#include <vector>
using namespace std;

class Product{
	private:
		string id;
		string prodname;
		int price;
		int qty;
		
	public:
		Product(string i, string n, int p, int q=0){
			id = i;
			prodname = n;
			price = p;
			qty = q;
		}
		
		void displayProducts(){
			cout << setw(10) << id << setw(15) << fixed << prodname << setw(10) << price << endl;
		}
		
		string getId(){ return id; }
        string getName() { return prodname; }
        int getPrice() { return price; }
        int getQuantity() {return qty; }
		
};

class ShoppingCart{	
	public:
		vector<Product> cart;
		vector<Product> productList;
		int total=0;
		int overall = 0;
				
		ShoppingCart(vector<Product> pl){
			productList = pl;
		}
		
		void addProducts(){
			string id;
			char choice;
			int qty;
			
			do{
				cin.ignore();				
				cout << "Enter ID of the product you want to add in the cart: ";
					cin >> id;
				cout << "Enter quantity: ";
					cin >> qty;
				
				bool found = false;
				for (int i = 0; i < productList.size(); i++){
					if (productList[i].getId() == id){
						cart.push_back(Product(productList[i].getId(),productList[i].getName(),productList[i].getPrice(), qty));
						cout << "\nProduct added successfully!" << endl;
						found = true;
						break;
					}
				}
				
				if (!found) {
					cout << "\nProduct not found!" << endl;
				}
				
				while (true) {
					cout << "Do you want to add another product? [Y/N]: ";
					cin >> choice;	
					
					if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n'){
						break;
					} else{
						cout << "Invalid input. Please enter either 'Y' or 'N' only" << endl << endl;
					}
						
				}	
				
			} while (choice == 'Y' || choice =='y');
			
		}
		
		bool displayProducts(){
			total = 0;
			char option;
			bool orderConfirmed = false;
			
			cout << "	--------- S H O P P I N G   C A R T ---------" << endl << endl;
		
			if (cart.empty()) {
				cout << "	Cart is empty" << endl;
				
			} else{
				
				cout << setw(10) << "ID" << setw(13) << "NAME" << setw(15) << "PRICE" << setw(13) << "QUANTITY" << endl << endl;
				for (int i=0; i < cart.size(); i++){
					cout << setw(10) << cart[i].getId() << setw(15) << fixed << cart[i].getName() << setw(13) << cart[i].getPrice() << setw(13) << cart[i].getQuantity() << endl;
					total += (cart[i].getPrice()*cart[i].getQuantity());
					overall += total;
				}
				cout << "\n	---------------------------------------------" << endl << endl;
				
				while (true){
					cout << "	Do you want to check out all the products? [Y/N]: "; 
					cin >> option;	
						
					if (option == 'Y' || option == 'y' || option == 'N' || option == 'n'){
						break;
					} else{
						cout << "	Invalid input. Please enter either 'Y' or 'N' only" << endl << endl;
					}
				}
			
				if (option == 'Y' || option == 'y'){
					
					cout << "\n\n	----- C O N F I R M E D   O R D E R / S -----" << endl << endl;
					cout << setw(10) << "ID" << setw(13) << "NAME" << setw(15) << "PRICE" << setw(13) << "QUANTITY" << endl << endl;
				
					for (int i=0; i < cart.size(); i++){
						cout << setw(10) << cart[i].getId() << setw(15) << fixed << cart[i].getName() << setw(13) << cart[i].getPrice() << setw(13) << cart[i].getQuantity() << endl;
					}
					cout << "\n	---------------------------------------------" << endl << endl;
					cout << "	Total: " << overall << endl << endl;
					cout << "	---------------------------------------------" << endl << endl;
					orderConfirmed = true;
				} else{
					cout << "	Checkout Cancelled.";
				} 	
			}
		
			cout << endl;
			system("PAUSE");
			system("CLS");
			return orderConfirmed;
		}
		
		void reserCart(){
			cart.clear();
			total = 0;
		}
		
		int getTotal() { return total; }
};

class Order{
	private:
		static vector<ShoppingCart> orderList;
		ShoppingCart cart;
		
	public:
		
		Order(ShoppingCart s) : cart(s){
			orderList.push_back(cart);
		}	
		
		void displayOrder(){
			cout << "	---------- O R D E R   L I S T --------------" << endl;
			
			if (orderList.empty()){
				cout << "	No orders available." << endl;
				return;
				
			} else{
					for (int j = 0; j < orderList.size(); j++){
						cout << "\n	Order ID: " << j+1 << endl; 
						cout << "	Total Amount: "  << orderList[j].getTotal() << endl;
						cout << "	Order Details: " << endl << endl; 
						cout << setw(10) << "ID" << setw(15) << "NAME" << setw(15) << "PRICE" << setw(13) << "QUANTITY" << endl << endl;
						
						for (int i=0; i < orderList[j].cart.size(); i++){ 
							cout << setw(10) << orderList[j].cart[i].getId() << setw(20) << fixed << orderList[j].cart[i].getName() << setw(10) << orderList[j].cart[i].getPrice() << setw(13) << orderList[j].cart[i].getQuantity() << endl;
					}	
					cout << "\n	--------------------------" << endl;
				}                                   
			
				cout << "	---------------------------------------------" << endl << endl;
			}
		}
			
		 
};

vector<ShoppingCart> Order::orderList;

int main(){
	vector<Product> productList = {
        Product("1", "Keychain", 50),
        Product("2", "Plushie", 500),
        Product("3", "Standee", 200),
        Product("4", "Acrylic Pin", 70),
        Product("5", "Button Pin", 40),
        Product("6", "Sticker", 30)
    };
	ShoppingCart s(productList);
	Order *o = nullptr;
	
	int choice;
	do{
		cout << "----- SHOP MENU -----" << endl << endl;
		cout << "[1] View Products" << endl;
		cout << "[2] View Shopping Cart" << endl;
		cout << "[3] View Orders" << endl ;
		cout << "[4] Exit"<< endl << endl;
		cout << "Enter the number: ";
			cin >> choice;
		
		system("CLS");
		
		switch(choice){
			case 1:
				cout << "	----- C A T A L O G U E -----" << endl << endl;
				cout << setw(10) << "ID" << setw(12) << "NAME" << setw(15) << "PRICE" << endl << endl;
				for (auto product : productList){
					product.displayProducts();
				}
				cout << "\n	-----------------------------" << endl << endl;
				s.addProducts();
				system("PAUSE");
				system("CLS");
				break;
			case 2: 
				if (s.displayProducts()){
					o = new Order(s);
					s.reserCart();
				}
				break;
			case 3: 
				o->displayOrder();
				system("PAUSE");
				system("CLS");
				break;
			case 4:
				cout << "Exiting...";
				exit(0);
				break;
			default:
				cout << "Invalid choice. Please try again";
		}
	} while (choice != 4);
	
}