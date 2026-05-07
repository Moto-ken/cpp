
#include <iostream>

int main(int argc, char **argv)
{
    int i = 1;
    int j;

    if (argc == 1){
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (1);
    }
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (97 <= argv[i][j] && argv[i][j] <= 122)
                argv[i][j] -= 32; 
            j++;
        }
        std::cout << argv[i];
        if (i < argc -1)
            std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return (0);
}
