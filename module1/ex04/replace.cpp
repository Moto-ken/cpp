
#include "replace.hpp"

std::string readFile(const char* filename) {
    std::ifstream infile(filename);

    if (!infile) throw std::runtime_error("Error opening file");
    std::string str((std::istreambuf_iterator<char>(infile)),
                    std::istreambuf_iterator<char>());
    return (str);
}

std::string replaceString(const std::string& str, const std::string& s1,
                          const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t found = 0;

    while ((found = str.find(s1, pos)) != std::string::npos) {
        result += str.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += str.substr(pos);
    return (result);
}

bool replaceFile(const std::string& filename, const std::string& s1,
                 const std::string& s2) {
    if (s1.empty()) {
        std::cerr << "s1 is empty" << std::endl;
        return (false);
    }

    std::string str;
    try {
        str = readFile(filename.c_str());
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (false);
    }

    std::string result = replaceString(str, s1, s2);

    std::string outFilename = filename + ".replace";
    std::ofstream outfile(outFilename.c_str());
    if (!outfile) {
        std::cerr << "Error creating output file" << std::endl;
        return (false);
    }
    outfile << result;
    return (true);
}
