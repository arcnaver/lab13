/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
* 
*     JAKE SCHWANTES
* 
********************************************************************/
#ifndef CIPHER05_H
#define CIPHER05_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher05 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Jake Schwantes"; }
   virtual std::string getCipherName() { return "Route Cypher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt author"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://crypto.interactive-maths.com/route-cipher.html#encrypt");
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      // Traditionally the 'password' is the route that the program
      // can follow to output the right string.
      // Also it's late at night so I'm not trying to make this really
      // performant; don't judge :P

      // A lot of these numbers are arbitrary. The start location for
      // example could be whatever we want but I just decided on
      // making it whatever the character % of 9 is.
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str =  "string cypherText[idk_like_lengthOfText_or_something][];\n";
      str += "int x = password[0] % 9\n";
      str += "int y = password[1] % 9\n";
      str += "// Draw the route inside our array\n";
      str += "foreach letter in password.slice(2)\n";
      str += "   cypherText[x][y] = letter";
      str += "   if letter % 4 == 0\n";
      str += "      x++, continue\n";
      str += "   else if letter % 4 == 1\n";
      str += "      y++, continue\n";
      str += "   else if letter % 4 == 2\n";
      str += "      x--, continue\n";
      str += "   else if letter % 4 == 3\n";
      str += "      y--, continue\n";
      str += "// Now that we have our message complete,\n";
      str += "// fill in the rest of the array with garbage,\n";
      str += "foreach xrow in password[0]\n";
      str += "   foreach y in xrow\n";
      str += "      if cypherText[x][y] = null\n";
      str += "         cyphertext[x][y] = randomLetter()\n";
      str += "return cypherText\n";
      str += "\n";

      // The decrypt pseudocode
      str =  "string text = \"\"\n";
      str += "//These numbers are arbitrary, just as\n";
      str += "//long as they match the encryption method\n";
      str += "int x = cypherText[0] % 9\n";
      str += "int y = cypherText[1] % 9\n";
      str += "foreach letter in password.slice(2)\n";
      str += "   text = cypherText[x][y]\n";
      str += "   if letter % 4 == 0\n";
      str += "      x++, continue\n";
      str += "   else if letter % 4 == 1\n";
      str += "      y++, continue\n";
      str += "   else if letter % 4 == 2\n";
      str += "      x--, continue\n";
      str += "   else if letter % 4 == 3\n";
      str += "      y--, continue\n";
      str += "return text\n";
      str += "\n";

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

#endif // CIPHER05_H
