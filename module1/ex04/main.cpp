
#include "replace.hpp"

int main(int argc, char** argv) {
    if (argc != 4) return (1);
    if (!replaceFile(argv[1], argv[2], argv[3])) return (1);
    return (0);
}
