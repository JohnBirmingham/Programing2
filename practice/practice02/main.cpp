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
//change
class Bank {
public:
	Bank() {
		amount = 100.00;
	}
	void SaveInfo() {
		std::ofstream file(filename); // Replace "example.txt" with your file name
		file << amount;
		file.close();
	}
	int GetFileInfo() {
		std::ifstream file(filename); // Replace "example.txt" with your file name
		double fileAmount;
		if (file.is_open()) {
			file >> fileAmount;
			file.close();
			return 0;
		}
		else {
			std::cout << "Unable to open file." << std::endl;
			return 1;
		}
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
	double amount;
	Bank userAccount;
	result = userAccount.GetFileInfo();
	std::cout << "Welcome to the bank" << std::endl;
	if (result == 1) {
		std::cout << "The amount is $" << userAccount.CheckBalance() << "..." << std::endl;
	}
	else if (result == 0) {
		std::cout << "Your current balance is $" << userAccount.CheckBalance() << "." << std::endl;
	}
	while (true) {
		result = main();
		if (result == 1) {
			std::cout << "Your current balance is " << userAccount.CheckBalance() << "." << std::endl;
		}
		else if (result == 2) {
			userAccount.Deposit();
		}
		else if (result == 3) {
			userAccount.WidthDraw();
		}
		else if (result == 4) {
			break;
		}
		else {
			std::cout << "Invalid Input" << std::endl;
		}
	}
	userAccount.SaveInfo();

}