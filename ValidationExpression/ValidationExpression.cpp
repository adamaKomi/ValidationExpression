// ValidationExpression.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#pragma once
#include <iostream>
#include "Stack.h"

int main()
{
    std::string menu = "1-Verifier une expression\n0-Quitter";
    int choix;
    std::string exp;

    do
    {
        std::cout << std::endl;
        std::cout << menu << std::endl;
        std::cout <<">>";
        std::cin >> choix;
        std::cout << std::endl;

        if (choix == 1)
        {
            Stack<char> stack;
            std::cout << "Entrez une expression : ";
            std::cin >> exp;
            std::cout << std::endl;

            try
            {
                // a+b-c : valide
                // (a+b)+z : valide
                // (a+b))+z : invalide
                // ((a+b)+z : invalide
                // (a+)+z : invalide
                // a-b+ : invalide
                // (*x)+y : invalide
                // x+(y*z) : valide
                // +*a-b : invalide
                // */(x+y) : invalide
                //a + & b : invalide

                stack.validerExpresion(exp);
            }
            catch (const std::exception& e)
            {
                std::cout << "Erreur : " << e.what() << std::endl;
            }
        }
    } while (choix != 0);


    return 0;
}
