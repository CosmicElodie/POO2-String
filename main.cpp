/**
* Laboratoire   : 2 - Classe String
* Date          : jeudi 02 avril 2020
* Élèves        : Crüll Loris, Lagier Elodie
* Fichier       : main.cpp
*/

#include "String.h"

using namespace std;

int main() {
    const String cst1("const String cst1");
    const char* cst2("const char* cst2");
    const char* cst3 = nullptr;

    //-----------------------------------------------
    //TEST CONSTRUCTEURS
    //-----------------------------------------------

    cout    << "=== CONSTRUCTEURS ===" << endl;
    String s1; //String::String()
    cout << "s1 : " << s1 << endl;
    String s2("Je suis une string !"); //String::String(const char *value)
    cout << "s2 : " << s2 << endl;
    String s3(s2); //String::String(const String &copy)
    cout << "s3 : " << s3 << endl;
    String s4('H'); //String::String(char value)
    cout << "s4 : " << s4 << endl;
    String s5(1); //String::String(int value)
    cout << "s5 : " << s5 << endl;
    String s6(1234567890); //String::String(int value)
    cout << "s6 : " << s6 << endl;
    String s7(1.2); //String::String(double value)
    cout << "s7 : " << s7 << endl;
    String s8(1.234567890); //String::String(double value)
    cout << "s8 : " << s8 << endl;
    String s9(true); //String::String(bool value)
    cout << "s9 : " << s9 << endl << endl;

    cout    << "- constantes -" << endl;
    cout << "cst1 : " << cst1 << endl;
    cout << "cst2 : " << cst2 << endl;
    String s10(cst2); //String::String(const char *value)
    cout << "s10 : " << s10 << endl;
    try {
        String s11(cst3); //String::String(const char *value)
    }catch(exception& e)
    {
        cout << "s11 : " << e.what() << endl;
        cout << "Test nullptr passe !" << endl << endl;
    }

    //-----------------------------------------------
    //TEST OPERATEURS
    //-----------------------------------------------

    cout    << "=== ACCESSEURS ===" << endl;
    cout    << "- operator[] -" << endl;
    cout    << cst1[8] << " " << cst1[9] << " " << cst1[10] << " " << cst1[11]  << endl;
    cout    << cst2[0] << "" << cst2[1] << "" << cst2[4] << " "
            << cst2[0] << "" << cst2[1] << "" << cst2[4] << endl << endl;

    try {
        cout << "out of bound : " << cst1[50] << endl << endl;
    } catch(exception& e)
    {
        cout << "cst1[50] : " << e.what() << endl;
        cout << "Test out of range passe !" << endl << endl;
    }

    cout    << "=== EGALITE ===" << endl;
    String str1("Wesh");
    cout << "str1 : " << str1 << endl;
    String str2("Wesh");
    cout << "str2 : " << str2 << endl;
    String str3("Woush");
    cout << "str3 : " << str3 << endl;
    const char* c1("Wish");
    const char* c2("Wesh");

    cout << "str1 == str2 ? " << ((str1 == str2) ? "true" : "false") << endl;
    cout << "str1 == str3 ? " << ((str1 == str3) ? "true" : "false") << endl;
    cout << "str1 != str2 ? " << ((str1 != str2) ? "true" : "false") << endl;
    cout << "str1 != str3 ? " << ((str1 != str3) ? "true" : "false") << endl;
    cout << "str1 == c1 ? " << ((str1 == c1) ? "true" : "false") << endl;
    cout << "str2 == c2 ? " << ((str2 == c2) ? "true" : "false") << endl << endl;


    cout    << "=== AFFECTATION ===" << endl;
    cout << "cst1 : " << cst1 << endl;
    cout << "str1 : " << str1 << endl;
    cout << "str3 : " << str3 << endl;
    cout << "c1 : " << c1 << endl;
    cout << "str1 = str3 -> ";
    str1 = str3;
    cout << "str1 : " << str1 << endl;
    cout << "str1 = c1 -> ";
    str1 = c1;
    cout << "str1 : " << str1 << endl << endl;

    cout    << "=== CONCATENATION ===" << endl;
    String s12("HEIG");
    String s13("-VD");
    cout << "s12 + s13 : " << s12 + s13 << endl;
    cout << "s12 : " << s12 << " (inchange)" << endl;
    cout << "s13 : " << s13 << " (inchange)" << endl << endl;

    cout << "s12 += s13 : " << (s12 += s13) << endl;
    cout << "s12 : " << s12 << " (change)" << endl;
    cout << "s13 : " << s13 << " (inchange)" << endl << endl;

    cout    << "=== SUBSTRING ===" << endl;
    String s14("Star Wars is overrated.");
    cout << "s14 : " << s14 << endl;
    cout << "s14.substr(5,8) : " << s14.substr(5,8) << endl << endl;

    try{
        cout << "s14.substr(9,8) - front > end : ";
        cout << s14.substr(9,8);
    }catch(exception& e)
    {
        cout << e.what() << endl;
    }

    try{
        cout << "s14.substr(5,50) - end > size : ";
        cout << s14.substr(5,50);
    }catch(exception& e)
    {
        cout << e.what() << endl;
        cout << "Tests out of range passes !" << endl << endl;
    }


    cout    << "=== IO ===" << endl;
    String s15;
    cout << "Veuillez saisir une chaine : \n";
    cout << "str15 before : " << s15 << endl;
    cin >> s15;
    cout << "str15 after : " << s15 << endl << endl;

    return EXIT_SUCCESS;
}