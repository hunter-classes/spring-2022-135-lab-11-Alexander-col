#include "network.h"
#include "profile.h"
#include <iostream>


  // Returns user ID (index in the 'profiles' array) by their username
  // (or -1 if username is not found)
int Network::findID(std::string user) 
{ 
    for(int i = 0; i < numUsers; i++) 
    { 
        if(profiles[i].getUsername() == user) 
        { 
            return i; 
        }
    }

    return -1;
}

  // Constructor, makes an empty network (numUsers = 0)
  Network::Network()
  {
    numUsers = 0; 
  }


  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false

bool Network::addUser(std::string usrn, std::string dspn) 
{ 
    if(numUsers == MAX_USERS) 
    { 
        return false; 
    } 
    else if(findID(usrn) != -1) 
    { 
        return false; 
    }

    for(int i = 0; i < usrn.size(); i++) 
    {

        if(!isalnum(usrn.at(i))) 
        { 
            return false; 
        }
    }

    profiles[numUsers] = { usrn, dspn };

    numUsers++;

    return true;
}

bool Network::follow(std::string user, std::string target) 
{ 
    // Makes user follow target 
    if(findID(user) == -1 || findID(target) == -1) 
    {

        return false;
    }

    following[findID(user)][findID(target)] = true;
    return true; 
}

void Network::printDot() { 
/*
digraph {
    "@mario"
    "@luigi"
    "@yoshi"
    "@mario" -> "@luigi"
    "@luigi" -> "@mario"
    "@luigi" -> "@yoshi"
    "@yoshi" -> "@mario"
}   
*/

    std::cout << "digraph {" << std::endl;
    for(int i = 0; i < numUsers; i++) 
    { 
        std::cout << "  \"@" << profiles[i].getUsername() << "\"" << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < MAX_USERS; i++) 
    { 
        for(int j = 0; j < MAX_USERS; j++) 
        { 
            if(following[i][j] == true) 
            { 
                std::cout << "  \"@" << profiles[i].getUsername() << "\" -> \"" << 
                             "@" << profiles[j].getUsername() << "\"" << std::endl;
            }
        }
    }

    std::cout << "}" << std::endl;
}
