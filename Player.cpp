
 #include "Player.h"
 #include <iostream>
 #include <iostream>
 #include <ostream>
 #include <stdexcept>   


	#include <iostream>
std::ostream& operator <<(std::ostream& out, const Player& p) {
        return std::cout << p.name;
    }

