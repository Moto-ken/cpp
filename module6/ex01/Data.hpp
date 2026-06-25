
#ifndef DATA_HPP
#define DATA_HPP

class Data {
   private:
    int nb;

   public:
    Data();
    Data(const int nb);
    Data(const Data& other);
    Data& operator=(const Data& other);
    ~Data();
};

#endif
