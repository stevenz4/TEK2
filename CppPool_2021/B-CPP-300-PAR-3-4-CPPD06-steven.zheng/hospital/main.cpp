/*
** EPITECH PROJECT, 2021
** main function
** File description:
** Exercise 02 Main
*/

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"

using namespace std;

// int             main()
// {
//   KoalaNurse	KoalaNurse(194) ;
//   SickKoala	SickKoala("Koko");


//   KoalaNurse.giveDrug("Mars", &SickKoala);
//   KoalaNurse.readReport("Koko.report");
//   KoalaNurse.timeCheck();
//   return 0;
// }

int		main()
{
  KoalaNurse    KoalaNurse(194) ;
  SickKoala     SickKoala("Koko");
  KoalaDoctor	KoalaDoctor("House");

  KoalaDoctor.diagnose(&SickKoala);
  KoalaDoctor.timeCheck();
  return 0;
}