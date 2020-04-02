/**
* Laboratoire   : 2 - Classe String
* Date          : jeudi 26 mars 2020
* Élèves        : Crüll Loris, Lagier Elodie
* Fichier       : String.h
*/

#ifndef POO2_CLASSSTRING_STRING_H
#define POO2_CLASSSTRING_STRING_H

#include <cstring>
#include <iostream>

/**
 * Classe String permettant de manipuler les chaînes de caractères de manière plus conviviale
 * qu'en C. :)
 */
class String {
private :
    //représente la fin d'une chaine de caractère
    static const char EOL = '\0';

    //représente la chaine de caractères de la String
    char *charTab;

    //représente la taille de la String
    size_t size;

    /**
     * Alloue la mémoire selon une chaine de caractères donnée.
     * @param newSize : la taille de la chaine de caractères
     */
    void allocate(size_t newSize);

    /**
     * Désalloue la mémoire
     */
    void free() noexcept;

    /**
     * Permet de construire un String selon une valeur numérique
     * @tparam T : le type de la valeur
     * @param format : le format d'affichage de la valeur (%d ou %g ici)
     * @param value : la valeur numérique
     */
    template<typename T>
    void buildNumericString(const char *format, T value);

    /**
     * Opérateur de flux de sortie
     * @throw invalid_argument si les bornes renseignées sont fausses.
     */
    friend std::ostream &operator<<(std::ostream &os, const String &string);

    /**
     * Opérateur de flux d'entrée
     * @param is : le flux
     * @param string : la string
     * @return une référence sur le flux
     */
    friend std::istream &operator>>(std::istream &is, String &str);

public :

    /**
     * Constructeur
     * Représente une chaine de caractères vide.
     */
    explicit String();

    /**
     * Constructeur
     * Permet de créer une String à partir d'une chaine de caractères.
     * @throw invalid_argument si l'argument mène à nullptr.
     * @param value
     */
    explicit String(const char *value);

    /**
     * Constructeur
     * Permet de créer une String à partir d'un caractère.
     * @param value
     */
    explicit String(char value);

    /**
     * Constructeur de copie
     * Permet de créer une String à partir d'une autre String
     * @param copy : la string à copier
     */
    String(const String &copy);

    /**
     * Constructeur avec paramètre
     * Permet de créer une String à partir d'un entier
     * source : https://stackoverflow.com/questions/5242524/converting-int-to-string-in-c
     * @param value : l'entier
     */
    explicit String(int value);

    /**
     * Constructeur
     * Permet de créer une String à partir d'une réel
     * source : https://stackoverflow.com/questions/5242524/converting-int-to-string-in-c
     * @param value : le réel
     */
    explicit String(double value);

    /**
     * Constructeur
     * Permet de créer une String à partir d'un booléen
     * @param value : le booléen
     */
    explicit String(bool value);

    /**
     * Destructeur
     */
    ~String();

    /**
     * @return la longueur de la String
     */
    size_t stringLength() const noexcept;

    /**
     * Permet de représenter la String sous forme de const char*
     * @return la String représentée sous forme de const char*
     */
    const char *c_c_String();

    /**
     * @param i : la place du caractère dans la chaine
     * @return une référence sur le i-ème charactère
     */
    char &operator[](size_t i);

    /**
     * @param i : la place du caractère dans la chaine
     * @return le i-ème caractère
     */
    char operator[](size_t i) const;

    /**
     * @param i : la place du caractère dans la chaine
     * @throw out_of_range si l'index est hors-bornes
     * @return une référence sur le i-ème caractère
     */
    char &at(size_t i);

    /**
     * @param i : la place du caractère dans la chaine
     * @throw out_of_range si l'index est hors-bornes
     * @return le i-ème caractère
     */
    char at(size_t i) const;

    /**
     * @param value : la valeur de la 2nd String à tester
     * @return true si elles sont inégales, false sinon
     */
    bool operator==(const String &value) const;

    /**
     * @param value : la valeur de la 2nd chaine à tester
     * @return true si elles sont inégales, false sinon
     */
    bool operator==(const char *value) const;

    /**
     * @param value : la valeur de la 2nd String à tester
     * @return true si elles sont inégales, false sinon
     */
    bool equals(const String &value) const;

    /**
     * @param value : la valeur de la 2nd chaine à tester
     * @return true si elles sont inégales, false sinon
     */
    bool equals(const char *value) const;

    /**
     * Permet de tester l'inégalité de deux Strings
     * @param value : la valeur de la 2nd String à tester
     * @return true si elles sont inégales, false sinon
     */
    bool operator!=(const String &value) const;

    /**
     * Permet de tester l'inégalité de deux chaines de caractères
     * @param value : la valeur de la 2nd chaine à tester
     * @return true si elles sont inégales, false sinon
     */
    bool operator!=(const char *value) const;

    /**
     * Opérateur d'affectation
     * Modification de son état à partir d'une autre instance de la classe String
     * @param value : la valeur de l'instance à affecter à notre String
     */
    String &operator=(const String &value);

    /**
     * Opérateur d'affectation
     * Modification de son état à partir d'une chaine de caractères
     * @param value : la valeur de l'instance à affecter à notre String
     */
    String &operator=(const char *value);

    /**
     * Modification de son état à partir d'une autre instance de la classe String
     * @param value : la valeur de l'instance à affecter à notre String
     */
    void assign(const String &value);

    /**
     * Modification de son état à partir d'une chaine de caractères
     * @param value : la valeur de l'instance à affecter à notre String
     */
    void assign(const char *value);

    /**
     * Permet de concaténer avec une instance de la classe
     * @param value : la String à concaténer
     * @return une nouvelle instance de la classe avec les valeurs concaténées
     */
    String operator+(const String &value) const;

    /**
     * Permet de concaténer avec une chaine de caractère
     * @param value : la chaine à concaténer
     * @return une nouvelle instance de la classe avec les valeurs concaténées
     */
    String operator+(const char *value) const;

    /**
     * Permet de concaténer avec une instance de la classe
     * @param value : la String à concaténer
     * @return une nouvelle instance de la classe avec les valeurs concaténées
     */
    String concat(const String &value) const;

    /**
     * Permet de concaténer avec une chaine de caractère
     * @param value : la chaine à concaténer
     * @return une nouvelle instance de la classe avec les valeurs concaténées
     */
    String concat(const char *value) const;

    /**
     * Permet de concaténer avec une instance de la classe
     * @param value : la String à concaténer
     * @return l'instance de la classe avec les valeurs concaténées
     */
    String &operator+=(const String &value);

    /**
     * Permet de concaténer avec une chaine de caractère
     * @param value : la chaine à concaténer
     * @return L'instance de la classe avec les valeurs concaténées
     */
    String &operator+=(const char *value);

    /**
     * Permet de concaténer avec une instance de la classe
     * @param value : la String à concaténer
     * @return l'instance de la classe avec les valeurs concaténées
     */
    String &append(const String &value);

    /**
     * Permet de concaténer avec une chaine de caractère
     * @param value : la chaine à concaténer
     * @return L'instance de la classe avec les valeurs concaténées
     */
    String &append(const char *value);

    /**
     * Permet d'extraite une sous-chaine entre deux indices donnés
     * @param frontIndex : l'index du début de la chaine
     * @param endIndex : l'index de la fin de la chaine
     * @return Une nouvelle instance de la classe
     */
    String substr(size_t frontIndex, size_t endIndex) const;
};

#endif //POO2_CLASSSTRING_STRING_H
