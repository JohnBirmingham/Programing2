import <iostream>;
import <fstream>;
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

int getDbl(const std::string& prompt) {
	double input;
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
	Bank() {
		amount = 100.00;
	}
	void SaveInfo() {
		
	}
	void GetFileInfo() {

	}
	double CheckBalance() {
		return amount;
	}
	void Deposit() {
		double depositAmount;
		depositAmount = getDbl("What is the deposit amount? ");
		amount += depositAmount;
	}
	void WidthDraw() {
		double widthdrawAmount;
		widthdrawAmount = getDbl("What is the widthdraw amount");
		if (widthdrawAmount < 0) {
			std::cout << "Widthdraw amount can't be a negative" << std::endl;
		}
		else if (amount - widthdrawAmount < 0) {
			std::cout << "Can't widthdraw because it is to much." << std::endl;
		}
		else {
			amount -= widthdrawAmount;
		}
	}
private:
	double amount;
	std::ifstream filename = "account_balance.txt";
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
	int result;
	Bank userAccount;
	userAccount.GetFileInfo();
	std::cout << "Welcome to the bank" << std::endl;
	std::cout << "The amount is $" << userAccount.CheckBalance() << "..." << std::endl;
	while (true) {
		result = main();
		if (result == 1) {
			userAccount.CheckBalance();
		}
		else if (result == 2) {
			userAccount.Deposit();
		}
		else if (result == 3) {
			userAccount.WidthDraw();
		}
		else if (result == 4) {
			return 1;
		}
		else {
			std::cout << "Invalid Input" << std::endl;
		}

	}
}