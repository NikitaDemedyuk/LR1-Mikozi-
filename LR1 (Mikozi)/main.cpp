#include <clocale>
#include <iostream>
#include <string>
#include <fstream>

std::string encryptTextAffine(std::string myWord, int a, int b, bool flagEncrypt) {
	
	std::string alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
	std::string codeWord = "";
	std::string decipheredWord = "";
	
	switch (flagEncrypt) {
		case true: {
			for (int i = 0; i < myWord.size(); ++i) {
				codeWord += alphabet[(a * alphabet.find(myWord[i]) + b) % alphabet.size()];
			}

			return codeWord;
			break;
		}
		
		case false: {
			for (int i = 0; i < myWord.size(); ++i) {
				decipheredWord += alphabet[(17 * (alphabet.find(myWord[i]) - b + alphabet.size()) % alphabet.size())];
			}
			return decipheredWord;
			break;
		}
	}	
}

std::string  encryptTextVizhiner(std::string myWord, std::string keyWord, bool flagEncrypt) {
	std::string alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏĞÑÒÓÔÕÖ×ØÙÚÛÜİŞß";
	std::string codeWord = "";
	std::string decipheredWord = "";


	switch (flagEncrypt) {
		case true: {
			std::string keyWordLong = "";

			while (keyWordLong.size() < myWord.size()) {
				keyWordLong += keyWord;
			}

			for (int i = 0; i < myWord.size(); ++i) {
				codeWord += alphabet[(alphabet.find(myWord[i]) + alphabet.find(keyWordLong[i]) /* + alphabet.size()*/) % alphabet.size()];
			}

			return codeWord;
			break;
		}

		case false: {
		
			std::string keyWordLong = "";

			while (keyWordLong.size() < myWord.size()) {
				keyWordLong += keyWord;
			}

			for (int i = 0; i < myWord.size(); ++i) {
				decipheredWord += alphabet[(alphabet.find(myWord[i]) - alphabet.find(keyWordLong[i]) + alphabet.size()) % alphabet.size()];
			}
			return decipheredWord;
			break;
		}
	}
}

void printToFile(std::ofstream &fout, std::string value, std::string typeCipher) {
	fout.open("C:\\Users\\work-group\\Documents\\Visual Studio 2017\\LR1 (Mikozi)\\result.txt", std::ios_base::app);
	if (fout.is_open()) {
		fout << "------------------------" << typeCipher << "---------------------------------" << std::endl;
		fout << "Result: " << value << std::endl;
		fout << "-------------------------------------------------------------------------" << std::endl;
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	std::ofstream foutForAffine;
	std::ofstream foutForVizhiner;

	std::cout << "----------------------- Affine cipher ---------------------------" << "\n";

	std::cout << "Enter the type of operation:\n1 - to encrypt the word\n2 - to decipher the word\nPlease, enter number: ";
	int value1 { 0 };

	int a = 2;
	int b = 14;

	std::cin >> value1;
	
	switch (value1) {
		case 1: {
			std::string myWord = "ÌÀÒÅÌÀÒÈÊÀ";
			std::string codeWord = encryptTextAffine(myWord, a, b, true);
			std::cout << "Result: " << codeWord << "\n\n";
			printToFile(foutForAffine, codeWord, "Affine cipher");
			break;
		}
		
		case 2: {
			std::string myWord = "ÆÍÒ×ÆÍÒßÃÍ";
			std::string codeWord = encryptTextAffine(myWord, a, b, false);
			std::cout << "Result: " << codeWord << "\n\n";
			printToFile(foutForAffine, codeWord, "Affine cipher");
			break;
		}
	}

	std::cout << "---------------------- Viziner cipher ----------------------------------" << "\n";

	std::cout << "Enter the type of operation:\n1 - to encrypt the word\n2 - to decipher the word\nPlease, enter number: ";
	int value2 { 0 };

	std::cin >> value2;

	switch (value2) {
		case 1: {
			std::string myWord = "ÌÀÍÄÀĞÈÍ";
			std::string codeWord = encryptTextVizhiner(myWord, "ÙÄĞ", true);
			std::cout << "Result: " << codeWord << "\n\n";
			printToFile(foutForVizhiner, codeWord, "Vizhiner cipher");
			break;
		}

		case 2: {
			std::string myWord = "¨ÄŞİÄÁÂÑ";
			std::string codeWord = encryptTextVizhiner(myWord, "ÙÄĞ", false);
			std::cout << "Result: " << codeWord << "\n\n";
			printToFile(foutForVizhiner, codeWord, "Vizhiner cipher");
			break;
		}
	}
	system("pause");
	return 0;

}




