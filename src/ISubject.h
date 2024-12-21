#ifndef ISUBJECT_H
#define ISUBJECT_H


class ISubject {
public:
    virtual ~ISubject() = default;

    virtual void addObserver(IObserver* observer) = 0;
    virtual void removeObserver(IObserver* observer) = 0;
    virtual void notifyObservers(const std::string& operation, const Item& item) = 0;
};

#endif // ISUBJECT_H
