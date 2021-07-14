#include "Character.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"
#include "Hunter.hpp"

int  main()
{
    Hunter h("Steven", 58);

    std::cout << h.Range << std::endl;
    h.Range = Character::RANGE;
    std::cout << h.Range << std::endl;
    return 0;
}