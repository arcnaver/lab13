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
#include <map> 

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Adam Tipton"; }
   virtual std::string getCipherName() { return "Keyword Cipher"; }
   virtual std::string getEncryptAuth() { return "Kyle Josephson"; }
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
    * TODO: Kyle Josphson
    **********************************************************/
   virtual std::string encrypt(const std::string& plainText,
      const std::string& password)
   {
      std::string cipherText;
      std::string encoding = " ";
      encoding = encode(password);
      int pos = 0;

      
      for (int i = 0; i < plainText.length(); i++)
      {
         if (plainText[i] > 'a' && plainText[i] < 'z')
         {
            pos = plainText[i] - 97;
            cipherText += encoding[pos];
         }            
         else if (plainText[i] > 'A' && plainText[i] < 'Z')
         {
            pos = plainText[i] - 65;
            cipherText += encoding[pos];
         }
         else
         {
            cipherText += plainText[i];
         }
         
            

      }


      
      return cipherText;
   }

   /**********************************************************
	* ENCODE
	* TODO: DAN - This will Encode the needed string
	**********************************************************/
   std::string encode(const std::string& password)
   {
	   std::string encoded = " ";
	   bool alphaArr[26] = { 0 };
	   for (int i = 0; i < password.size(); i++)
	   {
		   if (password[i] >= 'A' && password[i] <= 'Z')
		   {
			   if (alphaArr[password[i] - 65] == 0)
			   {
				   encoded += password[i];
				   alphaArr[password[i] - 65] = 1;
			   }
		   }
		   else if (password[i] >= 'a' && password[i] <= 'z')
		   {
			   if (alphaArr[password[i] - 97] == 0)
			   {
				   encoded += password[i] - 32;
				   alphaArr[password[i] - 97] = 1;
			   }
		   }
	   }

	   for (int i = 0; i < 26; i++)
	   {
		   if (alphaArr[i] == 0)
		   {
			   alphaArr[i] = 1;
			   encoded += char(i + 65);
		   }
	   }

	   return encoded;
   };

   /**********************************************************
    * DECRYPT
    * TODO: DAN - This will decrypt the keyword encryption
    **********************************************************/
   std::string plaintext = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   virtual std::string decrypt(const std::string& cipherText,
      const std::string& password)
   {
	   std::string encoded = "";
	   encoded = encode(password);
	
	   std::map <char, int> enc;
	   for (int i = 0; i < encoded.size(); i++)
	   {
		   enc[encoded[i]] = i;
	   }

	   std::string decipher = ""; 
	   for (int i = 0; i < cipherText.size(); i++)
	   {
		   if (cipherText[i] >= 'a' && cipherText[i] <= 'z')
		   {
			   int pos = enc[cipherText[i] - 32];
			   decipher += plaintext[pos];
		   }
		   else if (cipherText[i] >= 'A' && cipherText[i] <= 'Z')
		   {
			   int pos = enc[cipherText[i]];
			   decipher += plaintext[pos];
		   }
		   else
		   {
			   decipher += cipherText[i];
		   }
	   }
	   return decipher;
   }
};



#endif // CIPHER01_H
