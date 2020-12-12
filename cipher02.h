/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
* 
*     PAUL PORTER
* 
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth() { return "Paul Porter"; }
   virtual std::string getCipherName() { return "Polybius Square Cipher"; }
   virtual std::string getEncryptAuth() { return "encrypt author"; }
   virtual std::string getDecryptAuth() { return "decrypt Kyle Josephson"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("Polybius Square Cipher. Web. Practical Cryptography.\n Available: http://practicalcryptography.com/ciphers/polybius-square-cipher/");
   }

   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // The encrypt pseudocode
      str = "generateSquareFromKey(key):\n"
"    defaultSquare = ['A', 'B', 'C', 'D', 'E',\n"
"                     'F', 'G', 'H', 'I', 'K',\n"
"                     'L', 'M', 'N', 'O', 'P',\n"
"                     'Q', 'R', 'S', 'T', 'U',\n"
"                     'V', 'W', 'X', 'Y', 'Z']\n"
"    key = convertJToI(key)\n"
"    key = convertToUppercase(key)\n"
"    avoidDuplicates = \"\"\n"
"    position = 0\n"
"    for char in key:\n"
"        flag = True\n"
"        for processedChar in avoidDuplicates:\n"
"            if (processedChar == char):\n"
"                flag = False\n"
"        if (flag):\n"
"            temp = defaultSquare[position]\n"
"            savedPosition = 0\n"
"            for matchChar in defaultSquare:\n"
"                if (matchChar == char):\n"
"                    break\n"
"                savedPosition += 1\n"
"            defaultSquare[position] = char\n"
"            defaultSquare[savedPosition] = temp\n"
"            avoidDuplicates += char\n"
"            position += 1\n"
"    return defaultSquare\n"
"                \n"
"convertJToI(plaintext):\n"
"    return plaintext.replace(\"J\", \"I\")\n"
"\n"
"convertToUppercase(plaintext):\n"
"    returnString = \"\"\n"
"    for char in plaintext:\n"
"        returnString += char.upper()\n"
"    return returnString\n"
"    \n"
"encrypt(plaintext, key):\n"
"    square = generateSquareFromKey(key)\n"
"    plaintext = convertToUppercase(plaintext)\n"
"    plaintext = convertJToI(plaintext)\n"
"    ciphertext = \"\"\n"
"    cipherArray = ['A', 'B', 'C', 'D', 'E']\n"
"    for char in plaintext:\n"
"        if (char == \" \"):\n"
"            ciphertext += \" \"\n"
"        else:\n"
"            position = 0\n"
"            for item in square:\n"
"                if (item == char):\n"
"                    break\n"
"                position += 1\n"
"            xPosition = position % 5 #modulus division (remainder)\n"
"            yPosition = position // 5 #floor division\n"
"            ciphertext += cipherArray[xPosition]+cipherArray[yPosition]\n"
"    return ciphertext\n\n";

      // The decrypt pseudocode
      str += "getValFromCipherArray(encoding, cipherArray):\n"
"    val = 0\n"
"    for char in cipherArray:\n"
"        if (encoding == char):\n"
"            return val\n"
"        val += 1\n"
"\n"
"decrypt(ciphertext, key):\n"
"    square = generateSquareFromKey(key)\n"
"    plaintext = \"\"\n"
"    position = 0\n"
"    cipherArray = ['A', 'B', 'C', 'D', 'E']\n"
"    while(position < len(ciphertext)):\n"
"        if (ciphertext[position] == \" \"):\n"
"            plaintext += \" \"\n"
"            position += 1\n"
"        else:\n"
"            xVal = ciphertext[position]\n"
"            position += 1\n"
"            yVal = ciphertext[position]\n"
"            position += 1\n"
"            xPosition = getValFromCipherArray(xVal, cipherArray)\n"
"            yPosition = getValFromCipherArray(yVal, cipherArray)\n"
"            arrayPosition = xPosition + (5 * yPosition)\n"
"            plaintext += square[arrayPosition]\n"
"    return plaintext";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/

    void generateSquareFromKey(std::string key, char* square)
    {
        char defaultSquare[25] = {'A','B','C','D','E',
                                  'F','G','H','I','K',
                                  'L','M','N','O','P',
                                  'Q','R','S','T','U',
                                  'V','W','X','Y','Z'};
        key = convertJToI(key);
        key = convertToUppercase(key);
        std::string avoidDuplicates = "";
        int position = 0;
        for (int i = 0; i < key.length(); i++)
        {
           bool flag = true;
           for (auto processedChar : avoidDuplicates)
           {
              if (processedChar == key[i])
                  flag = false;
           }
           if (flag)
           {
              char temp = defaultSquare[position];
              int savedPosition = 0;
              for (auto matchChar : defaultSquare)
              {
                  if (matchChar == key[i])
                      break;
                  savedPosition += 1;
              }
              defaultSquare[position] = key[i];
              defaultSquare[savedPosition] = temp;
              avoidDuplicates.push_back(key[i]);
              position += 1;
           }
        }
        //copy 'em all over
        for (int i = 0; i < 25; i++) {
          square[i] = defaultSquare[i];
        }
     }


   virtual std::string encrypt(const std::string& plainText,
      const std::string& password)
   {
      std::string cipherText = "";
      char square[25];
      generateSquareFromKey(password, square);
      return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: Kyle Josephson decrypt
    **********************************************************/
   virtual std::string decrypt(const std::string& cipherText,
      const std::string& password)
   {
      std::string plainText = "";
      char square[25];
      int position = 0;
      char xVal;
      char yVal;

      char cipherArray[5] = {'A', 'B', 'C', 'D', 'E'};
      generateSquareFromKey(password, square);
      while (position < cipherText.length())
      {
         if (cipherText[position] == ' ')
         {
             plainText.push_back(' ');
             position += 1;
         }
         else
         {
             xVal = cipherText[position];
             position += 1;
             yVal = cipherText[position];
             position += 1;
             int xPosition = getValFromCipherArray(xVal, cipherArray);
             int yPosition = getValFromCipherArray(yVal, cipherArray);
             int arrayPosition = xPosition + (5 * yPosition);
             plainText.push_back(square[arrayPosition]);
         }
      }
      return plainText;
   }
};

#endif // CIPHER02_H
