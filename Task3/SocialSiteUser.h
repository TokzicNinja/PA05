#ifndef SOCIALSITEUSER_H
#define SOCIALSITEUSER_H

#include "User.h"

class SocialSiteUser:public User
{
private:
    std::string status;
    Inbox* myInbox;
    OldStatus* old;
public:
    SocialSiteUser(SocialSiteMediator* mediator,std::string name);
    void changeStatus(std::string newStatus);
    std::string viewStatus();
    virtual void receiveMessage(std::string message);
    void postMessage(std::string message);
    void saveMessage(std::string message);
    void viewInbox();
    void loadStatus();
    void saveStatus();
};

#endif 