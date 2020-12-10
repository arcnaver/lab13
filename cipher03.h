/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
* 
*     BRENTON TREBILCOCK
*     Affine Cipher
********************************************************************/
#ifndef CIPHER03_H
#define CIPHER03_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Brenton Trebilcock"; }
   virtual std::string getCipherName() { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string str = "“Implementation of Affine Cipher.”";
       str += "GeeksforGeeks, 29 May 2019, ";
       str += "www.geeksforgeeks.org/implementation-affine-cipher/. \n";
      return str;
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;
      // The encrypt pseudocode
      str = "Encryption pseudocode: \n";
      str += "encrypt(plaintext, password) \n";
      str += ""; //NEED TO figure out what to use password for?
      str += "";
      str += "";
      str += "RETURN cipherText";
      // The decrypt pseudocode
      str += "Decryption pseudocode: \n";
      str += "";
      str += "";
      str += "";
      str += "";
      str += "";
      str += "RETURN plainText";

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

#endif // CIPHER03_H
