
#include "twostrings.h"

void TwoStrings::setString1(string s)
{
    m_string1 = s;
}

void TwoStrings::setString2(string s)
{
    m_string2 = s;
}

string TwoStrings::getString1(void)
{
    return (m_string1);
}

string TwoStrings::getString2(void)
{
    return (m_string2);
}

string TwoStrings::getConnectedString()
{
    return (m_string1 + m_string2);
    // string str;

    // str.append(m_string1);
    // str.append(m_string2);
    // return (str);
}

int TwoStrings::getConnectedLength()
{
    string str = getConnectedString();
    return (str.length());
}
