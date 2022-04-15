#include "profile.h"    
#include <string>
#include <iostream>

    // Default Profile constructor (username="", displayname="")
    Profile::Profile()
    {
        username = "";
        displayname = "";
    }

    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile::Profile(std::string usrn, std::string dspn)
    {
        username = usrn;
        displayname = dspn;
    }

    // Return username
    std::string Profile::getUsername()
    {
        return username;
    }

    // Return name in the format: "displayname (@username)"
    std::string Profile::getFullName()
    {
        std::string output = displayname  + " (@" + username + ")";
        return output;
    }
    
    // Change display name
    void Profile::setDisplayName(std::string dspn)
    {
        displayname = dspn;
    }