#ifndef ITERATOR_H
#define ITERATOR_H


class iterator
{
    virtual void first()=0;
    virtual void next()=0;
    virtual bool hasNext()=0;
    virtual int current()=0;

};
#endif