#ifndef INTERACTION_H
#define INTERACTION_H
#include <string>

using namespace std;

class Interaction
{
public:
    Interaction();

    const string &getDateinteraction() const;
    void setDateinteraction(const string &newDateinteraction);

private:
    Date dateinteraction;
};

#endif // INTERACTION_H
