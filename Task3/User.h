#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include "SocialSiteMediator.h"

class SocialSiteMediator;
using namespace std;

class User
{
protected:
    SocialSiteMediator* mediator;
    std::string username;
public:
    User(SocialSiteMediator* _mediator,std::string name);
   virtual ~User();
    void changed(std::string message);
    std::string getName();
    virtual void setName(std::string username);
    virtual void receiveMessage(std::string)=0;
};


class Inbox
{
private:
    int numMessage;
    int MaxMessages;
    std::string* message;
public:
    Inbox(int _MaxMessages);
    ~Inbox();
    void save(std::string message);
    std::string load(int index);
    int getNumMessage();
};

class OldStatus
{
private:
    int numStatus;
    int MaxStatus;
    std::string* status;
public:
    OldStatus(int _MaxStatus);
    ~OldStatus();
    void save(std::string _status);
    std::string load(int index);
    int getNumStatus();
};


#endif