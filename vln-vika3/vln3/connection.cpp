#include "connection.h"

Connection::Connection()
{
    _scientistId = 0;
    _computerId  = 0;
}

Connection::Connection(int scientistId, int computerId)
{
    _scientistId = scientistId;
    _computerId  = computerId;
}

int Connection::getScientistId() const
{
    return _scientistId;
}

int Connection::getComputerId() const
{
    return _computerId;
}
