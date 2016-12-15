#ifndef CONNECTION_H
#define CONNECTION_H


class Connection
{
public:
    Connection();
    Connection(int scientistId, int computerId);
    int getScientistId() const;
    int getComputerId() const;

private:
    int _scientistId;
    int _computerId;
};

#endif // CONNECTION_H
