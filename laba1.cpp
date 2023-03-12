#include "Tables.h"

int main()
{
   auto lexeme = new Lexeme();
   int index;

   for (int i = 0; i < lexeme->keyWords->_array.size(); i++)
      cout << lexeme->keyWords->_array[i] << endl;
   index = lexeme->keyWords->findElem("void");
   cout << "place = " << index << endl << endl;
   
   for (int i = 0; i < lexeme->delimiters->_array.size(); i++)
      cout << lexeme->delimiters->_array[i] << endl;
   index = lexeme->delimiters->findElem("|");
   cout << "place = " << index << endl << endl;
   
   for (int i = 0; i < lexeme->operations->_array.size(); i++)
      cout << lexeme->operations->_array[i] << endl;
   index = lexeme->operations->findElem("==");
   cout << "place = " << index << endl << endl;
   cout << "-----------------------------------------" << endl;
   
   Place pl;
   pl = lexeme->tableInt->findElem("5");
   pl = lexeme->tableInt->findElem("103");
   pl = lexeme->tableInt->findElem("10");
   pl = lexeme->tableInt->findElem("17");
   cout << "place = " << pl._i<<" "<<pl._j << endl << endl;
   for (int i = 0; i < lexeme->tableInt->_array.size(); i++) {
      cout << i << ": ";
      for (int j = 0; j < lexeme->tableInt->_array[i].size(); j++)
        cout << j << ": " << lexeme->tableInt->_array[i][j] << " ";
      cout << endl;
   }
   cout << "-----------------------------------------" << endl;

   pl = lexeme->tableVar->findElem("a");
   pl = lexeme->tableVar->findElem("b");
   pl = lexeme->tableVar->findElem("zsh");
   pl = lexeme->tableVar->findElem("zs");
   pl = lexeme->tableVar->findElem("oooo");
   pl = lexeme->tableVar->findElem("word");
   pl = lexeme->tableVar->findElem("winter is commig");
   pl = lexeme->tableVar->findElem("zs");
   cout << "place = " << pl._i << " " << pl._j << endl << endl;
   for (int i = 0; i < lexeme->tableVar->_array.size(); i++) {
      cout << i << ": ";
      for (int j = 0; j < lexeme->tableVar->_array[i].size(); j++) {
         cout << j << ":" << "(" << lexeme->tableVar->_array[i][j]._name << " " << lexeme->tableVar->_array[i][j]._value << ") ";
      }
      cout << endl;
   }

   Token a = Token(4, 51, 1);
   lexeme->getElemByToken(a);
   cout << "name = " << lexeme->_var._name << " is_value = " << lexeme->_var._value << endl;
   
   Token b = Token(1, 2, -1);
   lexeme->getElemByToken(b);
   cout << lexeme->_str << endl;

   Token c = Token(3, 1, 1);
   lexeme->getElemByToken(c);
   cout << "value = " << lexeme->_value << endl;
   system("pause");
   return 0;
}