/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
* 
*     DAN WORWOOD
* 
********************************************************************/
#ifndef CIPHER06_H
#define CIPHER06_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Dan Worwood"; }
   virtual std::string getCipherName() { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {

	   //Rail Fence Cipher
	   std::string str;
	   str += "Rail Fence Cipher. (2019, May 29).Retrieved December 10, 2020, from\n";
	   str += "https://www.geeksforgeeks.org/rail-fence-cipher-encryption-decryption/ \n";
	   str += "The Rail Fence Cipher. (2018, October 08).Retrieved December 10, 2020, from\n";
	   str += "https://www.101computing.net/the-rail-fence-cipher/ \n";
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
	  str = "Encryption Rail Fence Cipher\n";
	  str += "cipherMsg(string message, int key)\n";
	  str += "    char rail[key][length of message]\n";
	  str += "    int row is 0\n";
	  str += "    int col is 0\n";
	  str += "    bool dir_down is FALSE\n";
	  str += "       FOR number < key size \n";
	  str += "          FOR value < message length\n";
	  str += "             rail[number][value] is newline\n";
	  str += "       FOR value < message length \n";
	  str += "          IF row is 0 and row is key-1\n";
	  str += "             dir_down is !dir_down\n";
	  str += "          rail[row][col++] = text[value]\n";
	  str += "          dir_down?row++ : row--\n";
	  str += "       string result is empty\n";
	  str += "       FOR number < key size \n";
	  str += "          FOR value < message length\n";
	  str += "             IF rail[number][value] is not newline\n";
	  str += "                push value to result\n";
	  str += "    return result\n";
	  str += " \n";

      // The decrypt pseudocode
	  str += "Decryption Rail Fence Cipher\n";
	  str += "string decipherMsg(string cipher, int key) \n";
	  str += "    char rail[key][length of cipher]\n";
	  str += "    int row is 0\n";
	  str += "    int col is 0\n";
	  str += "    bool dir_down is FALSE\n";
	  str += "    FOR number < key size \n";
	  str += "          FOR value < cipher length\n";
	  str += "             rail[number][value] is newline\n";
	  str += "       FOR value < cipher length \n";
	  str += "          IF row is 0\n";
	  str += "             dir_down is TRUE\n";
	  str += "          IF row is key-1\n";
	  str += "             dir_down is FALSE\n";
	  str += "         rail[row][col++] is '*'\n";
	  str += "         dir_down?row++ : row--\n";
	  str += "    int index is 0\n";
	  str += "    FOR number < key size \n";
	  str += "          FOR value < cipher length\n";
	  str += "             IF rail[number][value] is '*'\n";
	  str += "             AND index is less than cipher length\n";
	  str += "                rail[number][value] is cipher[index++]\n";
	  str += "       string result is empty\n";
	  str += "       FOR value < cipher length\n";
	  str += "          IF row is 0\n";
	  str += "             dir_down is TRUE\n";
	  str += "          IF row is key-1\n";
	  str += "             dir_down is FALSE\n";
	  str += "          IF rail[row][col++] is not '*'\n";
	  str += "                push value to result\n";
	  str += "          dir_down?row++: row--\n";
	  str += "    return result\n";
	  str += " \n";

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

#endif // CIPHER06_H