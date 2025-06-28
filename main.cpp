#include<iostream>
#include<fstream>
#include<string>
using namespace std;

/*--------- encrypting and decrypting the message -------*/
int main()
{
    fstream myFile;
    fstream encryptFile;
    fstream decryptFile;
    char c;
    int value;

    myFile.open("someMsg.txt", ios::in);
    if(myFile.is_open())
    {
        encryptFile.open("secret.txt", ios::out);
        if(encryptFile.is_open())
        {
            while(myFile.get(c)) /* takes each char and also the space */
            {
                encryptFile << (int)c <<" ";
            }
            encryptFile.close();
        }
        myFile.close();
    }

    encryptFile.open("secret.txt", ios::in);
    if(encryptFile.is_open())
    {
        decryptFile.open("retrieveMsg.txt", ios::out);
        if(decryptFile.is_open())
        {
            while(encryptFile >> value) /* >> operator to take complete int witout space */
            {
                decryptFile << (char)value;
            }
            decryptFile.close();
        }
        encryptFile.close();
    }
    return 0;
}
