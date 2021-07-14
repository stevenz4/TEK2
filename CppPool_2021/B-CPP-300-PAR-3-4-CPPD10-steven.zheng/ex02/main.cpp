/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "Squad.hpp"
#include "ISpaceMarine.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include <vector>
#include <memory>

int main ()
{
    std :: unique_ptr <ISquad> vlc (new Squad ) ;
    vlc -> push (new TacticalMarine ) ;
    vlc -> push (new AssaultTerminator ) ;
    for (int i = 0; i < vlc -> getCount () ; ++ i ) {
    const auto cur = vlc -> getUnit ( i ) ;
    cur -> battleCry () ;
    cur -> rangedAttack () ;
    cur -> meleeAttack () ;
    }
    return 0;
}