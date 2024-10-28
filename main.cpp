// Today we are making a new file encryption and decryption program.
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

using namespace std;

std::string xorEncryptDecrypt(const std::string& text, char key) {
    std::string result = text;
    for (size_t i = 0; i < text.size(); i++) {
        result[i] ^= key; 
    }
    return result;
}


int main() {

    std::cout << "========================================================" << std::endl;
    std::cout << "|                                                      |" << std::endl;
    std::cout << "|  E  N  C  R  Y  P  T    O  R    D  E  C  R  Y  P  T  |" << std::endl;
    std::cout << "|              (Y/N)                                   |" << std::endl;
    std::cout << "|                                                      |" << std::endl;
    std::cout << "========================================================" << std::endl;
    
    string ed;
    cin >> ed;
    if (ed == "Y" || ed == "y") {

            cout << "Hello Sir! Please provide us with the password." << "\n";
            string passwordpvd;
            cin >> passwordpvd;

            cout << "What key would you like? Just type any letter on your keyboard. (But remember it for decryption!)" << "\n";
            char keypvd;
            cin >> keypvd;
            cout << "Encrypting..." << "\n";
            //use the method.
            string password_encrypted = xorEncryptDecrypt(passwordpvd, keypvd);
            std::this_thread::sleep_for(chrono::seconds(3));
            cout << "Encrypted" << "\n";

            auto now = chrono::system_clock::now();
            auto now_time = chrono::system_clock::to_time_t(now);
            string file_name = "encrypted_" + to_string(now_time) + ".txt";

        
        ofstream file(file_name);

        if (file.is_open()) {
            file << password_encrypted; // Remove the endl to keep everything in one line
            file.close();
            cout << "Data written to file:" << " " << file_name << endl;
        } else {
            cerr << "Unable to open file. try launching again and retry." << endl;
        }


    } else {
        // Lets decrypt!

            char keypvd;
            cout << "Please provide the key that you used for decryption!" << "\n";
            cin >> keypvd;

            cout << "Please provide us with the file you would like to decrypt. (do not write .txt)" << "\n";
            string filenamegiven;
            cin >> filenamegiven;
            string properfilename = filenamegiven + ".txt";

            std::this_thread::sleep_for(chrono::seconds(2));
            cout << "Decrypted" << "\n";

            ifstream file(properfilename);

            
            if (!file.is_open()) {
                cout << "Unable to open file. try to open the file again." << endl;
                return 1; 
            }

            string decryptedpass;

            // Read file line by line
            getline(file, decryptedpass);
            string password_decrypted = xorEncryptDecrypt(decryptedpass, keypvd);

            cout << "Decrypted Password:" << " " << password_decrypted << "\n";
            cout << "Please type anything and enter to leave.....";
            string end;
            cin >> end;
            
            file.close();
            }


    return 0;
}

