#ifndef CONCRETESOCIALSITEMEDIATOR_H
#define CONCRETESOCIALSITEMEDIATOR_H

#include "SocialSiteMediator.h"

class ConcreteSocialSiteMediator:public SocialSiteMediator
{
private:
    User** user;
    int numuser;
public:
    ConcreteSocialSiteMediator();
    ~ConcreteSocialSiteMediator();
    virtual bool addUser(std::string username);
    virtual void notify(User* username,std::string message);
    User* getUser(std::string  name);
    int getNum();
};

#endif 