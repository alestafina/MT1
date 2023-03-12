#include "Tables.h"

void ConstTable::readTable(string fileName)
{
   string tmp;
   fstream in(fileName);
   while (!(in.eof())) {
      in >> tmp;
      _array.push_back(tmp);
   }
   in.close();
}

ConstTable::ConstTable(string fileName)
{
   readTable(fileName);
}

ConstTable::~ConstTable()
{
   _array.~vector();
}

int ConstTable::findElem(string Name)
{
   auto res = find(_array.begin(), _array.end(), Name);
   if (res == _array.end())
      return -1;
   else
      return res - _array.begin();
}

string ConstTable::getElem(int index) {
   return _array[index];
}

int TableVar::getHash(string h) {
   char len = ' ';
   if (h[0] >= 'A' && h[0] <= 'Z')
      len = h[0] - 'A';
   if (h[0] >= 'a' && h[0] <= 'z')
      len = h[0] - 'a' + 26;
   return (int)len;
}

TableVar::TableVar()
{
   _array.resize(52);
};

TableVar::~TableVar()
{
   _array.~vector();
}

Place TableVar::findElem(string name)
{
   Place pl;
   auto hash = getHash(name);
   pl._i = hash;
   if (_array[hash].size()) {
      auto res = find_if(_array[hash].begin(), _array[hash].end(), [&](const VarTableElem &s)-> bool {return s._name == name; });
      if (res == _array[hash].end())
      {
         _array[hash].push_back(VarTableElem(name, "", 0));
         pl._j = _array[hash].size() - 1;
      }
      else pl._j = res - _array[hash].begin();
   }
   else {
      _array[hash].push_back(VarTableElem(name, "", 0));
      pl._j = 0;
   }
   return pl;
}

void TableVar::changeElem(Place pl, bool value) {
   _array[pl._i][pl._j]._value = value;
}

VarTableElem TableVar::getElem(Place pl) {
   return _array[pl._i][pl._j];
}

int TableInt::getHash(string h) {
   int len;
   if (h[0] == '-')
      len = (int)h[1] - '0' + 9;
   else len = (int)h[0] - '0';
   return len;
}

TableInt::TableInt()
{
   _array.resize(19);
};

TableInt::~TableInt() {
   _array.~vector();
}

Place TableInt::findElem(string value)
{
   int tmp = stoi(value);
   Place pl;
   auto hash = getHash(value);
   pl._i = hash;
   if (_array[hash].size()) {
      auto res = find(_array[hash].begin(), _array[hash].end(), tmp);
      if (res == _array[hash].end())
      {
         _array[hash].push_back(tmp);
         pl._j = _array[hash].size() - 1;
      }
      else pl._j = res - _array[hash].begin();
   }
   else {
      _array[hash].push_back(tmp);
      pl._j = 0;
   }
   return pl;
}

void TableInt::changeElem(Place pl, int value) {
   _array[pl._i][pl._j] = value;
}

int TableInt::getElem(Place pl) {
   return _array[pl._i][pl._j];
}

void Lexeme::getElemByToken(Token tmp) {
   switch (tmp._table) {
   case 0: _str = keyWords->getElem(tmp._i); break;
   case 1: _str = operations->getElem(tmp._i); break;
   case 2: _str = delimiters->getElem(tmp._i); break;
   case 3: _value = tableInt->getElem(Place(tmp._i, tmp._j)); break;
   case 4: _var = tableVar->getElem(Place(tmp._i, tmp._j)); break;
   }
}