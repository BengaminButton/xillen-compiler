#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string author = "t.me/Bengamin_Button t.me/XillenAdapter";

class SimpleCompiler {
public:
    std::string compile(const std::string& code) {
        std::stringstream output;
        output << "// Скомпилированный код\n";
        output << "// Автор: " << author << "\n";
        output << "#include <iostream>\n";
        output << "int main() {\n";
        output << "    std::cout << \"" << code << "\" << std::endl;\n";
        output << "    return 0;\n";
        output << "}\n";
        return output.str();
    }
    void saveToFile(const std::string& filename, const std::string& content) {
        std::ofstream file(filename);
        file << content;
        file.close();
    }
};

int main(int argc, char* argv[]) {
    std::cout << author << std::endl;
    if (argc < 2) {
        std::cout << "Использование: " << argv[0] << " <код>" << std::endl;
        return 1;
    }
    SimpleCompiler compiler;
    std::string code = argv[1];
    std::string compiled = compiler.compile(code);
    compiler.saveToFile("output.cpp", compiled);
    std::cout << "Код скомпилирован в output.cpp" << std::endl;
    return 0;
}

