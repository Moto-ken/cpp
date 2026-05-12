
#include "replace.hpp"

std::string readFile(const char* filename) {
    std::ifstream infile(filename);
    std::string content;
    std::string line;

    if (!infile) throw std::runtime_error("Error opening file");
    while (std::getline(infile, line)) {
        content += line;
        if (!infile.eof()) content += '\n';
    }
    return (content);
}

std::string replaceString(const std::string& content, const std::string& s1,
                          const std::string& s2) {
    std::string result;
    size_t pos = 0;
    size_t found = 0;

    while ((found = content.find(s1, pos)) != std::string::npos) {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    return (result);
}

bool replaceFile(const std::string& filename, const std::string& s1,
                 const std::string& s2) {
    if (s1.empty()) {
        std::cerr << "s1 is empty" << std::endl;
        return (false);
    }

    std::string content;
    try {
        content = readFile(filename.c_str());
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return (false);
    }

    std::string result = replaceString(content, s1, s2);

    std::string outFilename = filename + ".replace";
    std::ofstream outfile(outFilename.c_str());
    if (!outfile) {
        std::cerr << "Error creating output file" << std::endl;
        return (false);
    }
    outfile << result;
    outfile.close();
    return (true);
}
