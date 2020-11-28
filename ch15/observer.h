//
// Created by 刘时明 on 2020/11/27.
//

#pragma once

#include <set>

class Observer
{
public:
    int value;

    Observer() = default;

    virtual ~Observer() = default;

    // 被观察对象发生变化时
    virtual void update(void *obj) = 0;
};

class ObserverAble
{
public:
    ObserverAble()
    {
        this->observer_set = new std::set<Observer *>;
    };

    virtual ~ObserverAble()
    {
        auto pos = this->observer_set->begin();
        for (; pos != this->observer_set->end(); ++pos)
        {
            delete (*pos);
        }
        this->observer_set->clear();
        delete observer_set;
    };

    void attach(Observer *observer)
    {
        observer_set->insert(observer);
    }

    void notify(void *args)
    {
        auto pos = this->observer_set->begin();
        for (; pos != this->observer_set->end(); pos++)
        {
            (*pos)->update(args);
        }
    }

private:
    std::set<Observer *> *observer_set;
};
