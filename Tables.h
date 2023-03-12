#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct VarTableElem {
   string _name;
   bool _value;
   VarTableElem(string name, string type, bool value) : _name(name), _value(value) {}
   VarTableElem() : _name(""), _value(0) {}
};

struct Place {
   int _i;
   int _j;
   Place(int i, int j) : _i(i), _j(j) {}
   Place() : _i(), _j() {}
};

struct Token {
   int _table;
   int _i;
   int _j;
   Token(int table, int i, int j) : _table(table), _i(i), _j(j) {}
};

class TableVar {
private:
   int getHash(string h);
public:
   vector <vector<VarTableElem>> _array;

   TableVar();
   ~TableVar();
   Place findElem(string name);
   void changeElem(Place pl, bool value);
   VarTableElem getElem(Place pl);
};

class TableInt {
private:
   int getHash(string h);
public:
   vector<vector<int>> _array;

   TableInt();
   ~TableInt();
   Place findElem(string value);
   void changeElem(Place pl, int value);
   int getElem(Place pl);
};

class ConstTable {
private:
   void readTable(string fileName);
public:
   vector<string> _array;

   ConstTable(string fileName);
   ~ConstTable();
   int findElem(string Name);
   string getElem(int index);
};

class Lexeme {
public:
   ConstTable *keyWords = new ConstTable("KeyWords.txt");
   ConstTable *operations = new ConstTable("Operation.txt");
   ConstTable *delimiters = new ConstTable("Delimiter.txt");
   TableInt *tableInt = new TableInt();
   TableVar *tableVar = new TableVar();

   string _str;
   int _value;
   VarTableElem _var;

   Lexeme() : _value(0), _str("") {}
   void getElemByToken(Token tmp);
};



