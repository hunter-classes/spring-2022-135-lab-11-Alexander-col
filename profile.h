#pragma once
#include <iostream>

class Profile {
private:
    std::string username;
    std::string displayname;
public:
    // Profile constructor for a user (initializing 
    // private variables username=usrn, displayname=dspn)
    Profile::Profile(std::string usrn, std::string dspn);
    // Default Profile constructor (username="", displayname="")
    Profile::Profile();
    // Return username
    std::string getUsername();
    // Return name in the format: "displayname (@username)"
    std::string getFullName();
    // Change display name
    void setDisplayName(std::string dspn);
};
