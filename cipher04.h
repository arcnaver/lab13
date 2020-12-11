/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
* 
*     KYLE JOSEPHSON
*  
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Kyle Josephson"; }
   virtual std::string getCipherName() { return "Vigenere Cipher"; }
   virtual std::string getEncryptAuth() { return "Adam Tipton"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string cite;
      cite += "Tutorialspoint (n.d.). ";
      cite += "Traditional Ciphers,\n\tRetrieved: December 9, 2020\n";
      cite += "\thttps://www.tutorialspoint.com/cryptography/traditional_ciphers.htm\n\n";
      cite += "Rembert, L. (2020, November 23). ";
      cite += "Vigenere Cipher.\n\tPrivacy Canada.net.  Retrieved: December 9, 2020\n";
      cite += "\thttps://privacycanada.net/classical-encryption/vigenere-cipher/\n\n";
      return cite;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      //The Encrypt Pseudocode
       str =  "encrypt(plainText, password)\n";
       str += "   IF (passwordLength > textLength)\n";
       str += "      RETURN error\n";
       str += "   FOR (passwordLength)\n";
       str += "      tempArray <- numeric value of each charater in password\n";
       str += "   FOR (textLength)\n";
       str += "      keyArray <- tempArray % passwordLength\n";
       str += "   FOR (textLength)\n";
       str += "      plainTextArray <- numric value of each charater in plainText\n";
       str += "   FOR (textLength)\n";
       str += "      cipherArray <- ((plainTextArray + keyArray) % 94) + 32\n";
       str += "   FOR (textLength)\n";
       str += "      cipherText <- covert to characters from values in cipherArray\n";
       str += "   RETURN cipherText\n\n";

      // The Decrypt Pseudocode
      str += "decrypt(cipherText, password)\n";
      str += "   FOR (passwordLength)\n";
      str += "      tempArray <- numric value of each charater in password\n";
      str += "   FOR (cipherLength)\n";
      str += "      keyArray <- tempArray % passwordLength\n";
      str += "   FOR (cipherLength)\n";
      str += "      cipherArray <- numric value of each character in cipherText\n";
      str += "   FOR (cipherLength)\n";
      str += "      plainTextArray <- decryptValue(cipherArray value, keyArray value)\n";
      str += "   FOR (cipherLength)\n";
      str += "      plainText <- convert to characters from values in plainTextArray\n";
      str += "   RETURN plainText\n";



      str += "decryptValue(cipherArray value, keyArray value)\n";
      str += "   answer <- ((cipherArray value - 32) + 94) - keyArray value\n";
      str += "   IF (answer < 32)\n";
      str += "      RETURN answer + 94\n";
      str += "   ELSE\n";
      str += "      RETURN answer\n\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string& plainText,
      const std::string& password)
   {
      std::string cipherText = "";
      int pwSize = password.length();
      int ptSize = plainText.length();
      int tempArray[128] = {};
      int keyArray[256] = {};
      int plainTextArray[256] = {};
      int cipherArray[256] = {};

      //Check length
      if (password.length() > plainText.length())
      {
         assert(password.length() < plainText.length());
         return "Error";
      }

      for (int i = 0; i < password.length(); i++)
      {
         tempArray[i] = (int)password[i];
         std::cout << tempArray[i] << " ";
      }
      
      for (int i = 0; i < plainText.length(); i++)
      {
         int repeatValue = i % pwSize;
         keyArray[i] = tempArray[repeatValue];
         std::cout << keyArray[i] << " ";
      }
      
      for (int i = 0; i < plainText.length(); i++)
      {
         plainTextArray[i] = (int)plainText[i];
         std::cout << plainTextArray[i] << " ";
      }
      
      for (int i = 0; i < plainText.length(); i++)
      {
         cipherArray[i] = ((plainTextArray[i] + keyArray[i]) % 94 + 32);
         std::cout << cipherArray[i] << " ";
      }
      
      for (int i = 0; i < plainText.length(); i++)
      {          
         cipherText += (char)cipherArray[i];
         std::cout << cipherText << " ";
      }
      std::cout << std::endl;
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string& cipherText,
      const std::string& password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER04_H
