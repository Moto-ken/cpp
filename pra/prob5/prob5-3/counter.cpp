
#include "counter.h"

int Counter::total_count = 0;

Counter::Counter() : m_count(0)
{
}

Counter::~Counter()
{
}

void Counter::reset()
{
    total_count = total_count - m_count;
    m_count = 0;
}

void Counter::count()
{
    m_count++;
    total_count++;
}

int Counter::getcount()
{
    return (m_count);
}

int Counter::getTotalCount()
{
    return (total_count);
}
