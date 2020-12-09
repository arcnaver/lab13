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
   virtual std::string getCipherName() { return "cipher name"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      //AFINE CIPHER CITATION
      std::string str;
      str += "Bifid Cipher in Cryptography. (2019, November 06).";
      str += " Retrieved December 09, 2020, from\n";
      str += "https://www.geeksforgeeks.org/bifid-cipher-in-cryptography/";
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
      str = "Encryption Bifid Cipher\n";
      str += "Initialize char grid[5][5]\n";
      str += "Initialize string rowStr, colStr, tmpRowStr, finalStr = “ ” \n";      
      str += "For every value in message \n";
      str += "    For every value in grid \n";
      str += "       If message = “ ”\n";
      str += "          rowStr and colStr += “ ”\n";
      str += "       If message = grid \n";
      str += "          rowStr <- += grid[index][] \n";
      str += "          colStr <- += grid[][index] \n\n";
      str += "For every value in rowStr and colStr \n";
      str += "    If value is not “ ” \n";
      str += "       tmpRow <- rowStr value\n";
      str += "       tmpCol <- colStr value \n";
      str += "    If value is “ “ \n";
      str += "       finalStr <- tmpRow and colStr and “ “ \n";
      str += "       clear tmpRow and tmpCol\n\n";
      str += "For every value in finalStr \n";
      str += "    If value is “ ” \n";
      str += "       Print “ “ \n";
      str += "       Increment index 1 \n";
      str += "    Else \n";
      str += "       Print grid[value[inex]][value[index+1]] \n";
      str += "       Increment index 2 \n";

      // The decrypt pseudocode
      str += "Decryption Bifid Cipher\n";

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

#endif // CIPHER01_H
