
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
#include <string>

    Profile p1("marco", "Marco");    
    Profile p2("Mang", "Mang");    
   

    

TEST_CASE("TASK A") 
{
    SUBCASE("getUsername()") 
    { 
        CHECK(p1.getUsername() == "marco");
        CHECK(p2.getUsername() == "Mang");

    }

    SUBCASE("getFullName()") 
    { 
        CHECK(p1.getFullName() == "Marco (@marco)");
        CHECK(p2.getFullName() == "Mang (@Mang)");

    }
}

TEST_CASE("TASK B") {
    Network nw; 
    SUBCASE("addUser()") 
    { 
        CHECK(nw.addUser("mario", "Mario") == true); 
        CHECK(nw.addUser("mario", "Mario") == false); 

    }
}

TEST_CASE("TASK C") { 
    Network nw;

    SUBCASE("addUser(user1, user2)") 
    { 
        CHECK(nw.addUser("mario", "Mario") == true);
        CHECK(nw.addUser("luigi", "Luigi") == true);

        nw.addUser("mario", "Mario");
        nw.addUser("luigi", "Luigi");
        for(int i = 2; i < 20; i++) 
        {
            nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i));
        }

        CHECK(nw.addUser("user", "user") == false); 
    }

    SUBCASE("follow(user1, user2)") 
    { 
        nw.addUser("mario", "Mario");
        nw.addUser("luigi", "Luigi");
        for(int i = 2; i < 20; i++) 
        {
            nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i));
        }

        CHECK(nw.follow("mario", "luigi") == true);
        CHECK(nw.follow("mario-", "mario") == false);

    }
}