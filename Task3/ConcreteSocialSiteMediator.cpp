#include "ConcreteSocialSiteMediator.h"
#include "SocialSiteUser.h"

ConcreteSocialSiteMediator::ConcreteSocialSiteMediator()
{
    numuser = 0;
    user = new User*[3];

}

ConcreteSocialSiteMediator::~ConcreteSocialSiteMediator()
{
    delete [] user;

    user = NULL;
}

bool ConcreteSocialSiteMediator::addUser(std::string username)
{
    bool temp = false;
    int x =0;
    if(numuser==0)
    {
        user[numuser] = new SocialSiteUser(this,username);
        ++numuser;
        cout<<numuser<<"- numuser";
            return true;
        }
        else
        {
            while(x<numuser)
            {
                if(user[x]->getName()==username)
                {   
                    cout<<"Username is already registered"<<endl;
                    return false;
                    break;
                }
                else
                {
                    user[numuser] = new SocialSiteUser(this,username);
                    numuser++;
                    cout<<numuser<<"- numuser";
                    x++;
                    return true;
                    break;
                }
            }
        }
}

void ConcreteSocialSiteMediator::notify(User* username,std::string message)
{
    for(int x =0;x<numuser;x++)
    {
        if(user[x]!=NULL && user[x]->getName()!=username->getName())
        {
            cout<<user[x]->getName()<<"";
            user[x]->receiveMessage(message);
            cout<<username->getName()<<" sent/changed her/his status to"<<": "<<message;
            cout<<endl;
        }
    }
}

User* ConcreteSocialSiteMediator::getUser(std::string  name)
{
    User* temp;
    cout<<numuser<<endl;
    int x =0;
    for(int x =0;x<numuser;x++)
    {
        if(user[x]->getName()==name)
        {
            temp = user[x];
            break;
        }
        else
        {
            temp = NULL;
        }
    }

    return temp;
}

int ConcreteSocialSiteMediator::getNum()
{
    return numuser;
}
