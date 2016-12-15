#ifndef CONNECTION_H
#define CONNECTION_H


class Connection
{
public:
    Connection();
    Connection(int scientistId, int computerId);
    int getScientistId() const;            //Gets private member variables for Scientist Id
    int getComputerId() const;             //Gets private member variables for Computer Id

private:
    int _scientistId;                     //Private member variables
    int _computerId;
};

#endif // CONNECTION_H
