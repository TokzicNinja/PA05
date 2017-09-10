Mediator: ConcreteSocialSiteMediator.o SocialSiteUser.o User.o  
	g++ ConcreteSocialSiteMediator.o SocialSiteUser.o User.o test.cpp -o Mediator

# SocialSiteMediator.o: SocialSiteMediator.cpp SocialSiteMediator.h
# 	g++ -c SocialSiteMediator.cpp

ConcreteSocialSiteMediator.o: ConcreteSocialSiteMediator.cpp ConcreteSocialSiteMediator.h 
	g++ -c ConcreteSocialSiteMediator.cpp 

SocialSiteUser.o: SocialSiteUser.cpp SocialSiteUser.h
	g++ -c SocialSiteUser.cpp

User.o: User.cpp User.h SocialSiteMediator.h
	g++ -c User.cpp

