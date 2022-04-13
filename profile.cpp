#pragma once
#include "profile.h"


    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    std::Profile(std::string usrn, std::string dspn)
    {
        username = usrn;
        displayname = dspn;
        return Profile;
    }
    // Default Profile constructor (username="", displayname="")
    std::Profile();
    // Return username
    std::string getUsername();
    // Return name in the format: "displayname (@username)"
    std::string getFullName();
    // Change display name
    void setDisplayName(std::string dspn);