#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

class FileEncryptor {
private:
    std::string filename;
    int encryptionKey;
    std::string encryptionMethod; 

    char caesarEncryptChar(char ch, int key) {
        if (std::isalpha(ch)) {
            char base = std::islower(ch) ? 'a' : 'A';
            return static_cast<char>((ch - base + key) % 26 + base);
        }
        return ch;
    }

    char caesarDecryptChar(char ch, int key) {
        if (std::isalpha(ch)) {
            char base = std::islower(ch) ? 'a' : 'A';
            return static_cast<char>((ch - base - key + 26) % 26 + base);
        }
        return ch;
    }

    char xorChar(char ch, int key) {
        return ch ^ key;
    }

public:
    FileEncryptor(const std::string& fname, int key, const std::string& method)
        : filename(fname), encryptionKey(key), encryptionMethod(method) {}

    void encryptAndWrite(const std::string& message) {
        std::ofstream outFile(filename, std::ios::binary);
        if (!outFile) {
            std::cerr << "Error: Cannot open file for writing.\n";
            return;
        }

        for (char ch : message) {
            char encryptedChar;
            if (encryptionMethod == "caesar") {
                encryptedChar = caesarEncryptChar(ch, encryptionKey);
            } else if (encryptionMethod == "xor") {
                encryptedChar = xorChar(ch, encryptionKey);
            } else {
                std::cerr << "Error: Unknown encryption method.\n";
                outFile.close();
                return;
            }
            outFile.put(encryptedChar);
        }

        outFile.close();
        std::cout << "Message successfully encrypted and stored in " << filename << "\n";
    }

    std::string readAndDecrypt() {
        std::ifstream inFile(filename, std::ios::binary);
        if (!inFile) {
            std::cerr << "Error: Cannot open file for reading.\n";
            return "";
        }

        std::string decryptedMessage;
        char ch;
        while (inFile.get(ch)) {
            char decryptedChar;
            if (encryptionMethod == "caesar") {
                decryptedChar = caesarDecryptChar(ch, encryptionKey);
            } else if (encryptionMethod == "xor") {
                decryptedChar = xorChar(ch, encryptionKey);
            } else {
                std::cerr << "Error: Unknown encryption method.\n";
                inFile.close();
                return "";
            }
            decryptedMessage += decryptedChar;
        }

        inFile.close();
        return decryptedMessage;
    }

    void displayFileContents() {
        std::string decryptedContent = readAndDecrypt();
        if (!decryptedContent.empty()) {
            std::cout << "Decrypted Message: " << decryptedContent << "\n";
        }
    }
};

int main() {
    std::string message;
    std::cout << "Enter a message to encrypt: ";
    std::getline(std::cin, message);

    std::string method = "caesar"; 
    int key = 3; 

    FileEncryptor encryptor("data.txt", key, method);
    encryptor.encryptAndWrite(message);

    std::cout << "Reading and decrypting file...\n";
    encryptor.displayFileContents();

    return 0;
}