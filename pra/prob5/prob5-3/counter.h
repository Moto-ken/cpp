
#ifndef COUNTER_H
# define COUNTER_H

class Counter{
    private:
        int         m_count;
        static int  total_count;
    public:
        Counter();
        ~Counter();
        void        reset();
        void        count();
        int         getcount();
        static int  getTotalCount();
};

#endif
