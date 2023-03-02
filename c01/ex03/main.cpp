#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"

int main(){
        HumanA aHumanA("HumanA");
        aHumanA.attack();
        Weapon gun = Weapon("Gun");
        aHumanA.setWeapon(gun);
        aHumanA.attack();
        gun.setType("another type gun");
        aHumanA.attack();

        Weapon laser = Weapon("Laser");
        HumanA ai("AI", laser);
        ai.attack();
        ai.setWeapon(laser);
        ai.attack();
        laser.setType("another type laser");
        ai.attack();

		HumanB bob("Bob");
		Weapon drone = Weapon("Drone");;
		bob.attack();
        bob.setWeapon(drone);
		bob.attack();
		drone.setType("another type drone");
		bob.attack();
}