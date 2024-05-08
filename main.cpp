#include <iostream>
#include <fstream>

void readSection(std::ifstream& file, const std::string& sectionName) {
    int sectionLength;
    file.read(reinterpret_cast<char*>(&sectionLength), sizeof(sectionLength));
    std::cout << "======================\n";
    std::cout << "==  " << sectionName << " Data  ==\n";
    std::cout << "======================\n";
    std::cout << sectionName << " length: " << sectionLength << "\n";
}

int main() {
    const std::string filename = "all.grib"; // Використання std::string замість const char*
    std::ifstream file(filename, std::ios::binary);

    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    readSection(file, "Section 1");
    readSection(file, "Section 2");
    readSection(file, "Section 4");

    file.close();
    return 0;
}
