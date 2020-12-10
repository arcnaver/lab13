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
#include <sstream>


/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Brenton Trebilcock"; }
   virtual std::string getCipherName() { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Dan Worwood"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      std::string str = "“Implementation of Affine Cipher.” ";  //source 1
       str += "GeeksforGeeks, 29 May 2019, ";
       str += "www.geeksforgeeks.org/implementation-affine-cipher/. \n\n";

       str += "Borodzhieva, A. N., & Manoilov, P. K. (2014)."; //source 2
       str += "Training module with graphical user interface for encryption \n";
       str += "and decryption using affine ciphers applied in cryptosystems. ";
       str +=  "2014 IEEE 20th International Symposium for \n";
       str += "Design and Technology in Electronic Packaging (SIITME), ";
       str += "Design and Technology in Electronic Packaging\n";
       str += "(SIITME), 2014 IEEE 20th International Symposium For, 281–286.\n";
       str += "https://doi.org/10.1109/SIITME.2014.6967045\n";
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
      str += "encrypt(plainText, password) \n"; //the password needs to contain 2 keys separated by a space
      str += "key1 <- password.substring(0,3)\n"; 
      str += "key2 <- password.substring(3)\n";
      str += "IF key1 or key2 are not numbers\n";
      str += " RETURN error\n";   
      str += "IF key1 is not a coprime of alphabetSize\n";
      str += " RETURN error\n";
      str += "IF key2 is greater than alphabetSize or key2 is less than zero\n";
      str += " RETURN error\n";
      str += "FOR v in alphabetSize\n";
      str += " alphabetArray[v] <- character of the alphabet at value\n";
      str += "FOR v in length of plainText\n";
      str += " plainTextArray[v] <- the corresponding integer value for the character\n";
      str += "FOR v in size of plainTextArray\n";
      str += " cipherTextArray <- (key1*plainTextArray[v]+key2) % alphabetSize\n";
      str += "FOR v in size of cipherTextArray\n";
      str += " cipherText += alphabetArray[cipherTextArray[v]]";           
      str += "RETURN cipherText\n\n";
      
      // The decrypt pseudocode
      str += "Decryption pseudocode: \n";
      str += "decrypt(cipherText, password)\n";
      str += "key1 <- password.substring(0,3)\n"; 
      str += "key2 <- password.substring(3)\n";
      str += "IF key1 or key2 are not numbers\n";
      str += " RETURN error\n";   
      str += "IF key1 is not a coprime of alphabetSize\n";
      str += " RETURN error\n";
      str += "IF key2 is greater than alphabetSize or key2 is less than zero\n";
      str += " RETURN error\n";
      str += "FOR v in alphabetSize\n";
      str += " alphabetArray[v] <- character of the alphabet at value\n";
      str += "FOR v in length of cipherText\n";
      str += " cipherTextArray[v] <- the corresponding integer value for the character\n";
      str += "FOR v in size of cipherTextArray\n";
      str += " plainTextArray <- key1^-1 * (cipherTextArray[v]-key2) % alphabetSize\n";    
      str += "FOR v in size of plainTextArray\n";
      str += " plainText += alphabetArray[plainTextArray[v]]";         
      str += "RETURN plainText\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: DAN - This will encrypt the Affine Cipher
    **********************************************************/
   virtual std::string encrypt(const std::string& plainText,
      const std::string& password)
   {
      std::string cipherText = "";
	  std::string char1 = password.substr(0, 3);
	  std::string char2 = password.substr(3);
	  int key1;
	  int key2;
	  int alphabetSize = 26;
	  char alphabetArray[] = "abcdefghijklmnopqrstuvwxyz";

	  std::stringstream ss1;
	  ss1 << char1;
	  ss1 >> key1;
	  std::stringstream ss2;
	  ss2 << char2;
	  ss2 >> key2;

	  //find if numbers are coprime of 26()alphabet
	  bool isCoprime = true;
	  int hcf = 0;
	  for (int i = 1; i <= key1; i++)
	  {
		  if (key1 % i == 0 && alphabetSize % i == 0)
			  hcf = i;
	  }
	  if (hcf != 1) {
		  std::cout << "First number is not coprime with 26\n";
	  }
	  
	  if (key2 > alphabetSize || key2 < 0) {
		  std::cout << "Second number must be greater than 0 and less than 26\n";
	  }

	  for (int i = 0; i < plainText.length(); i++)
	  {
		  if (plainText[i] != ' ')
			  cipherText = cipherText +
			  (char)((((key1 * (plainText[i] - 'A')) + key2) % 26) + 'A');
		  else
			  //else simply append space character 
			  cipherText += plainText[i];
	  }
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
