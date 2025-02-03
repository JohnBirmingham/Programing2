import <iostream>;
import <vector>;

int getInt(const std::string& prompt) {
	int input;
	while (true) {
		std::cout << prompt;
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter an integer.\n";
		}
		else {
			std::cin.ignore();
			return input;
		}
	}
}

class Bank {
public:
	Bank()
	void SaveFileInfo() {

	}
	void GetFileInfo() {

	}
	double CheckBalance() {

	}
	void Deposit() {

	}
	void WidthDraw() {

	}
private:
	double amount;
};

int menu() {
	std::cout << "Menu:" << std::endl;
	std::cout << "1. Check Balance" << std::endl;
	std::cout << "2. Deposit Money" << std::endl;
	std::cout << "3. WidthDraw Money" << std::endl;
	std::cout << "4. Bank" << std::endl;

	getInt("Enter your choice: ");
}
void 
	
int main() {
	std::cout << "Welcome to the bank"
}