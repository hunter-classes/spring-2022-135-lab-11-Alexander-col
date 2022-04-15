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
