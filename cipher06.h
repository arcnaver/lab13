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
#include <sstream> 
#include <iostream> 
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher06 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Dan Worwood"; }
   virtual std::string getCipherName() { return "Rail Fence Cipher"; }
   virtual std::string getEncryptAuth() { return "Brenton Trebilcock"; }
   virtual std::string getDecryptAuth() { return "Paul Porter"; }

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
	  str += "          IF row is 0 and row is key-1\n"; //should be or
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
	int key;
	std::stringstream passWordString(password);
	std::string cipherText;
	passWordString >> key;
	char rail[key][(plainText.length())];
	int row = 0;
	int col = 0;
	bool dir_down = false;
	for(int i = 0; i < key; i++)
	{
		for(int j = 0; j < plainText.length(); j++)
			rail[i][j] = '\n';
	}
	for(int i = 0; i < plainText.length(); i++)
	{
		if(row == 0 || row == (key - 1))
		{
			dir_down = !dir_down;
		}
		rail[row][col++] = plainText[i];
		dir_down ? row++ : row --;
	}
	for(int i = 0; i < key; i++)
	{
		for(int j = 0; j < plainText.length(); j++)
			if(rail[i][j] != '\n')
			{
				cipherText.push_back(rail[i][j]);
			}
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
      std::string plainText = "";
      int key;
      std::stringstream passWordString(password);
	    passWordString >> key;
      char rail[key][cipherText.size()];
      int row = 0;
      int col = 0;
      bool dirDown = false;
      for (int i = 0; i < key; i++) 
      {
         for (int j = 0; j < cipherText.size(); j++)
         {
            rail[i][j] = '\n';
         }
      }
      for (int i = 0; i < cipherText.size(); i++)
      {
         if (row == 0)
         {
            dirDown = true;
         }
         else if (row == (key - 1))
         {
            dirDown = false;
         }
         rail[row][col++] = '*';
         dirDown ? row++ : row--;
      }
      int index = 0;
      for (int i = 0; i < key; i++)
      {
         for (int j = 0; j < cipherText.size(); j++)
         {
            if (rail[i][j] == '*' && index < cipherText.size())
            {
               rail[i][j] = cipherText[index++];
            }
         }
      }
      row = 0;
      col = 0;
      for (int i = 0; i < cipherText.size(); i++)
      {
         if (row == 0)
         {
            dirDown = true;
         }
         else if (row == (key - 1))
         {
           dirDown = false;
         }
         if (rail[row][col] != '*')
         {
            plainText.push_back(rail[row][col++]);
         }
         dirDown ? row++ : row--;
      }
      return plainText;
   }
};

#endif // CIPHER06_H