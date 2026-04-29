
#ifndef OBJECT_H
# define OBJECT_H

class Object{
    private:
        static int m_objectNum;
    public:
        Object();
        ~Object();
        static int getObjectNum();
};

#endif
