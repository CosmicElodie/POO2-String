/**
* Laboratoire   : 2 - Classe String
* Date          : jeudi 02 avril 2020
* Élèves        : Crüll Loris, Lagier Elodie
* Fichier       : String.cpp
*/

#include "String.h"
#include <ostream>

using namespace std;

//--------------------------------------------------------
// CONSTRUCTEURS ET LEUR(S) MÉTHODE(S) DE CONSTRUCTION
//--------------------------------------------------------
String::String() : String("") {}

String::String(const char *value) {
    if (value == nullptr) {
        throw std::invalid_argument("Argument invalide !");
    }

    allocate(strlen(value));
    strcpy(charTab, value);
}

String::String(const String &copy) : String(copy.charTab) {}

String::String(char value) {
    allocate(1);
    charTab[0] = value;
    charTab[1] = '\0';
}

String::String(int value) {
    buildNumericString("%d", value);
}

String::String(double value) {
    buildNumericString("%g", value);
}

template<typename T>
void String::buildNumericString(const char *format, T value) {
    size = snprintf(NULL, 0, format, value);
    charTab = static_cast<char *>(new char[size]);
    size = snprintf(charTab, size + 1, format, value);
}

String::String(bool value) : String(value ? "true" : "false") {
}

String::~String() {
    free();
}

//--------------------------------------------------------
// MÉTHODES DIVERSES
//--------------------------------------------------------
size_t String::stringLength() const noexcept {
    return size;
}

const char *String::c_c_String() {
    return charTab;
}

void String::free() noexcept {
    delete[] charTab;
}

void String::allocate(size_t newSize) {
    size = newSize;
    charTab = new char[size + 1];
}

//--------------------------------------------------------
// OPÉRATEURS ET LEUR(S) MÉTHODE(S) DE CONSTRUCTION
//--------------------------------------------------------
char &String::operator[](size_t i) {
    return at(i);
}

char String::operator[](size_t i) const {
    return at(i);
}

char &String::at(size_t i) {
    if (size <= i) {
        throw out_of_range("index out of range");
    }
    return charTab[i];
}

char String::at(size_t i) const {
    if (size <= i) {
        throw out_of_range("index out of range");
    }
    return charTab[i];
}

bool String::operator==(const String &value) const {
    return equals(value);
}

bool String::operator==(const char *value) const {
    return equals(value);
}

bool String::equals(const String &value) const {
    return strcmp(charTab, value.charTab) == 0;
}

bool String::equals(const char *value) const {
    return strcmp(charTab, value) == 0;
}

bool String::operator!=(const String &value) const {
    return !(equals(value));
}

bool String::operator!=(const char *value) const {
    return !(equals(value));
}

String &String::operator=(const String &value) {
    return *this = value.charTab;
}

String &String::operator=(const char *value) {
    if (charTab != value) {
        free();
        if (value != nullptr) {
            strcpy(charTab, value);
            size = strlen(value);
        }
    }
    return *this;
}

void String::assign(const String &value) {
    *this = value;
}

void String::assign(const char *value) {
    *this = value;
}

String String::operator+(const String &value) const {
    return concat(value);
}

String String::operator+(const char *value) const {
    return concat(value);
}

String String::concat(const String &value) const {
    return String(*this).append(value);
}

String String::concat(const char *value) const {
    return String(*this).append(value);
}

String &String::operator+=(const String &value) {
    return append(value);
}

String &String::operator+=(const char *value) {
    return append(value);
}

String &String::append(const String &value) {
    return append(value.charTab);
}

String &String::append(const char *value) {
    char *tmp = new char[size + 1];
    strcpy(tmp, charTab);
    free();

    // Créer la nouvelle chaine
    allocate(size + strlen(value));
    strcpy(charTab, tmp);
    strcat(charTab, value);

    // Suppression de la valeur temporaire
    delete[]tmp;

    return *this;
}

String String::substr(size_t frontIndex, size_t endIndex) const {
    if ((frontIndex <= endIndex) && (endIndex < size)) {
        size_t tempSize = endIndex - frontIndex;
        char *temp = new char[tempSize];
        temp[tempSize + 1] = EOL;
        size_t index = frontIndex;

        while (index <= endIndex) {
            temp[index - frontIndex] = charTab[index];
            ++index;
        }

        String substrRes(temp);
        delete[] temp;

        return substrRes;

    } else {
        throw invalid_argument("les bornes renseignees sont incorrectes.");
    }
}

ostream &operator<<(ostream &os, const String &string) {
    return os << string.charTab;
}

istream &operator>>(istream &is, String &string) {
     size_t MAX_SIZE_BUFFER = 256;
    if(string.charTab) {
        delete[] string.charTab;
        string = new char[MAX_SIZE_BUFFER];
    }

    size_t index = 0;
    char temp; //permet d'accueillir la lettre lue

    do{
        //on lit lettre par lettre
        is.get(temp);
        //on met ça dans notre string
        string.charTab[index] = temp;
        ++index;
        //on continue tant qu'on ne trouve pas d'espace ou de retour à la ligne
    }while (temp != '\n' && temp != ' ');

    //on finit par concaténer le symbole de fin.
    string.charTab[index-1] = String::EOL;

    return is;
}