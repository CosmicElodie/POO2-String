/**
* Laboratoire   : 2 - Classe String
* Date          : jeudi 02 avril 2020
* Élèves        : Crüll Loris, Lagier Elodie
* Fichier       : main.cpp
*/

#include "String.h"

using namespace std;

int main() {

    //TEST CONSTRUCTEURS

    String s1;
    cout << "s1 : " << s1 << endl;
    String s2("Je suis la string s2 !");
    cout << "s2 : " << s2 << endl;
    String s3(s2);
    cout << "s3 : " << s3 << endl;
    String s4('H');
    cout << "s4 : " << s4 << endl;
    String s5(1);
    cout << "s5 : " << s5 << endl;
    String s6(1234567890);
    cout << "s6 : " << s6 << endl;
    String s7(1.2);
    cout << "s7 : " << s7 << endl;
    String s8(1.234567890);
    cout << "s8 : " << s8 << endl;
    String s9(true);
    cout << "s9 : " << s9 << endl << endl;

    //CONCATENATION
    String a("lol");
    String b("lul");
    cout << "a + b : " << a + b << endl;
    cout << "a : " << a << endl;
    cout << "b : " << b << endl << endl;

    //EGALITE
    String str1("Wesh");
    String str2("Wesh");
    String str3("Woush");
    cout << "str1/str2 : " << str1.equals(str2) << endl;
    cout << "str1/str3 : " << str1.equals(str3) << endl << endl;

    //IO
    String str;
    cout << "Veuillez saisir une chaine : \n";
    cout << "str before : " << str << endl;
    cin >> str;
    cout << "str after : " << str << endl;



    return EXIT_SUCCESS;
}
