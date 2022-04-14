#include "profile.h"    
#include <iostream>
#include <string>

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
    std::string getUsername()
    {
        return username;
    }
    // Return name in the format: "displayname (@username)"
    std::string getFullName()
    {
        std::string output = "@" + username;
        return output
    }
    // Change display name
    void setDisplayName(std::string dspn)
    {
        displayname = dspn;
    }