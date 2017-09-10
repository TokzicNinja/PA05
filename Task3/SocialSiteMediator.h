#ifndef SOCIALSITEMEDIATOR_H
#define SOCIALSITEMEDIATOR_H

#include <string>
#include "User.h"

class User;
//MEDIATOR
class SocialSiteMediator
{
public:
    virtual bool addUser(std::string username)=0;
    virtual void notify(User* username,std::string message)=0;
};

#endif