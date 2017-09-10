#include "SocialSiteUser.h"

SocialSiteUser::SocialSiteUser(SocialSiteMediator* mediator,std::string name):User(mediator,name)
{
    status="I am using SocialSite";
    myInbox = new Inbox(5);
    old = new OldStatus(5);
}

void SocialSiteUser::changeStatus(std::string newStatus)
{
    status = newStatus;
    // changed(status);
}

std::string SocialSiteUser::viewStatus()
{
    return status;
}

void SocialSiteUser::receiveMessage(std::string message)
{
    cout<<" received: ";
    saveMessage(message);
}

void SocialSiteUser::postMessage(std::string message)
{
    mediator->notify(this,message);
}

void SocialSiteUser::saveMessage(std::string message)
{
    myInbox->save(message);
}

void SocialSiteUser::viewInbox()
{
    if(myInbox->getNumMessage()==0)
    {
        cout<<"Inbox Empty"<<endl;
    }
    else
    {
        for(int x=0;x<myInbox->getNumMessage();x++)
        {
             cout<<myInbox->load(x)<<endl;
        }      
    }
}

void SocialSiteUser::loadStatus()
{
        int input;
        if(old->getNumStatus()==0)
        {
            cout<<"No previous statuses"<<endl;
        }
        else
        {
            cout<<"Choose status[0 - "<<old->getNumStatus()<<"]\n";
            cin>>input;
            status=old->load(input);
            User::changed(status);
        }
}

void SocialSiteUser::saveStatus()
{
    User::changed(status);   
    old->save(status);
}//CHECK VIEW INBOX