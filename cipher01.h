/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
* 
* 
*  ADAM TIPTON
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Adam Tipton"; }
   virtual std::string getCipherName() { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "Dan Worwood"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      //Keyword Cipher
      
      std::string str;
      str += "Keyword Cipher. (2019, May 29).Retrieved December 10, 2020, from\n";
      str += "https://www.geeksforgeeks.org/keyword-cipher/";
      return str;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str = "Encryption Keyword Cipher\n";
      str += "cipherMsg(string message, string encoded)";
      str += "    string cipher = space \n";
      str += "       for every value in message \n";
      str += "          if value is between a and z \n";
      str += "             int pos <- value - 97 \n";
      str += "             cipher += encoded[pos] \n";
      str += "          else if value is between A and Z \n";
      str += "             int pos <= value - 65 \n";
      str += "             cipher += encoded[pos] \n";
      str += "          else \n";
      str += "             cipher += value \n";
      str += "    return cipher\n";
      str += " \n";

      // The decrypt pseudocode
      str += "Decryption Keyword Cipher\n";
      str += "string plaintext = ABCDEFGHIJKLMNOPQRSTUVWXYZ \n";
      str += "string decipherMsg(string message, string encoded) \n";
      str += "    map<char, int> enc;\n";
      str += "    for encoded size\n";
      str += "       enc[encoded[index]] <- index\n";
      str += "    String decipher = space\n";
      str += "    for all values in message\n";
      str += "       if values is between a and z \n";
      str += "       int pos <- enc[value - 32] \n";
      str += "       decipher += plaintext[pos] \n";
      str += "    else if values is between A and Z \n";
      str += "       int pos <- enc[value] \n";
      str += "       decipher += plaintext[pos] \n";
      str += "    else \n";
      str += "       Decipher += value \n";
      str += "    return decipher \n";


      // The helper function
      str += "Helper function Keyword Cipher";
      str += "string encoder(string password) \n";
      str += "    string encoded = space \n";
      str += "    bool alphaArr[26] = {0} \n";
      str += "    for every value in password \n";
      str += "       if value is between A and Z \n";
      str += "          if alphaArr[value - 65] is 0 \n";
      str += "             encoded += value \n";
      str += "             alphaArr[value - 65] <- 1 \n";
      str += "       else if value is between a and z \n";
      str += "          if alphaArr[value - 97] is 0 \n";
      str += "             encoded += value - 32 \n";
      str += "             alphaArr[value - 97] <- 1 \n";
      str += "    for i less than 26 \n";
      str += "       if alphaArr[i] is 0 \n";
      str += "          alphaArr[i] <- 1 \n";
      str += "          encoded += char(i + 65) \n";
      str += "    return encoded \n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string& plainText,
      const std::string& password)
   {
      std::string cipherText = plainText;
      // TODO - Add your code here
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: DAN - This will decrypt the keyword encryption
    **********************************************************/
   virtual std::string decrypt(const std::string& cipherText,
      const std::string& password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER01_H
