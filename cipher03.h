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
#include <algorithm> // for gcd
#include <iostream>
#include <cmath>
#include <vector>


/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher03 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Brenton Trebilcock"; }
   virtual std::string getCipherName() { return "Affine Cipher"; }
   virtual std::string getEncryptAuth() { return "Dan Worwood"; }
   virtual std::string getDecryptAuth() { return "Adam Tipton"; }

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
      str += " cipherText += alphabetArray[cipherTextArray[v]]\n";           
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
      str += " plainText += alphabetArray[plainTextArray[v]]\n";         
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
			   (char)((((key1 * (toupper(plainText[i]) - 'A')) + key2) % 26) + 'A');
		   else
			   //else simply append space character 
			   cipherText += toupper(plainText[i]);
	   }
      return cipherText;
   }

 /*************************************************
 * GCD : Recursive function to find the greatest
 * common denominator. Source:
 * https://www.geeksforgeeks.org/c-program-find-gcd-hcf-two-numbers/
 *************************************************/
   int greatestCommonDenominator(int key1, int alphabetSize)
   {
      //If a is 0 then its b
      if (key1 == 0)
      {
         return alphabetSize;
      }
      //If b is zero then its a
      if (alphabetSize == 0)
      {
         return key1;
      }

      //Create the base case
      //If a equals be then their the same
      if (key1 == alphabetSize)
      {
         return key1;
      }
      //Start the recursion check
      if (key1 > alphabetSize)
      {
         return greatestCommonDenominator(key1 - alphabetSize, alphabetSize);
      }
      return greatestCommonDenominator(key1, alphabetSize - key1);
   }


   /**********************************************************
    * DECRYPT
    * TODO: Takes in the cipherText and password, and decrypts
    * the message back into plaintext. 
    **********************************************************/
   virtual std::string decrypt(const std::string& cipherText,
      const std::string& password)
   {
      std::string plainText = cipherText;

      //For consistency, use same variables as encrypt()
      std::string char1 = password.substr(0, 3);
      std::string char2 = password.substr(3);
      int key1;
      int key2;
      int alphabetSize = 26;      
      std::stringstream ss1;
      ss1 << char1;
      ss1 >> key1;
      std::stringstream ss2;
      ss2 << char2;
      ss2 >> key2;
      
      //Check for nan (isnan(key1) threw compile errors)
      if (key1 != key1 || key2 != key2)
      {
         return "nan error";
      }
      
      //Check for coprime
      if (greatestCommonDenominator(key1, alphabetSize) != 1)
      {
         return "coprime error";
      }

      //Check bounds of key2
      if (key2 > alphabetSize || key2 < 0)
      {
         return "key2 (2nd half of password) out of bounds error";
      }
      //Getting the multiplicactive inverse of key1
      int flag = 0;
      int inv = 0;
      for (int i = 0; i < 26; i++)
      {
         flag = (key1 * i) % 26;
         if (flag == 1)
         {
            inv = i;
         }
      }
      //Populate plain text
      for (int i = 0; i < cipherText.length(); i++)
      {
         if (cipherText[i] != ' ')
         {
            
            plainText = plainText + (char)(((inv * ((cipherText[i] + 'A' - key2)) % 26)) + 'A');
            
         }
         else
         {
            plainText += cipherText[i];
         }
      }
      //plaintext will also have ciphertext, lets cut that bit out.
      std::string cleanPlainText = plainText.substr(cipherText.length());
      return cleanPlainText;     

   
   }


};

#endif // CIPHER03_H
