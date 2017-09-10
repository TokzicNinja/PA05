#include "User.h"

User::User(SocialSiteMediator* _mediator,std::string name)
{
    this->mediator = _mediator;
    this->username = name;
}

User::~User()
{}

void User::changed(std::string message)
{
    mediator->notify(this,message);
}

void User::setName(std::string username)
{
    this->username = username;
}

std::string User::getName()
{
    return username;
}

Inbox::Inbox(int _MaxMessages)
{
    this->MaxMessages = _MaxMessages;
    numMessage = 0;
    message = new std::string[MaxMessages]; 
}

Inbox::~Inbox()
{
    delete [] message;
}

void Inbox::save(std::string message)
{
    if(numMessage!=MaxMessages)
    {
        this->message[numMessage] = message;
        numMessage++;
    }
    else 
    {
        cout<<"Cannot store any messages, inbox is full\n";
    }
}

std::string Inbox::load(int index)
{
    return message[index];
}

int Inbox::getNumMessage()
{
    return numMessage;
}

OldStatus::OldStatus(int _MaxStatus)
{
    numStatus=0;
    MaxStatus=_MaxStatus;
    status=new std::string[MaxStatus];
    status[numStatus] ="I am using SocialSite";
}

OldStatus::~OldStatus()
{
    delete [] status;
}

void OldStatus::save(std::string _status)
{
    if(numStatus!=MaxStatus)
    {
        numStatus++;
        status[numStatus] = _status;
    }
    else 
    {
        cout<<"Cannot store any statuses, inbox is full\n";
    }
}

std::string OldStatus::load(int index)
{
    return status[index];
}

int  OldStatus::getNumStatus()
{
    return numStatus;
}