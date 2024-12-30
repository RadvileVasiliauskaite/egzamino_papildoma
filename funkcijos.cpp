#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <regex>
#include <stdexcept>
#include <iomanip>
#include <algorithm>
#include <cctype>

std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) { return std::tolower(c); });
    return lowerStr;
}

void countWordsAndLines(const std::string& filename,
    std::map<std::string, int>& wordCounts,
    std::map<std::string, std::set<int>>& wordLines,
    std::map<std::string, std::string>& originalWords) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 0;
    std::regex wordRegex(R"([a-zA-Z0-9_]+)");

    while (std::getline(file, line)) {
        ++lineNumber;
        std::sregex_iterator begin(line.begin(), line.end(), wordRegex), end;
        for (auto it = begin; it != end; ++it) {
            std::string word = it->str();
            std::string lowerWord = toLowerCase(word);

            if (originalWords.find(lowerWord) == originalWords.end()) {
                originalWords[lowerWord] = word;
            }

            ++wordCounts[lowerWord];
            wordLines[lowerWord].insert(lineNumber);
        }
    }

    file.close();
}

void writeWordCounts(const std::string& outputFilename,
    const std::map<std::string, int>& wordCounts,
    const std::map<std::string, std::string>& originalWords) {
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << outputFilename << std::endl;
        return;
    }

    outputFile << "Zodziai ir ju pasikartojimu skaicius:\n";
    outputFile << "-----------------------------\n";

    for (const auto& it : wordCounts) {
        if (it.second > 1) {
            outputFile << std::left << std::setw(20)
                << originalWords.at(it.first)
                << it.second << " pasikartojimu\n";
        }
    }

    outputFile.close();
}

void writeCrossReference(const std::string& outputFilename,
    const std::map<std::string, std::set<int>>& wordLines,
    const std::map<std::string, int>& wordCounts,
    const std::map<std::string, std::string>& originalWords) {
    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << outputFilename << std::endl;
        return;
    }

    outputFile << "Zodziai ir eilutes, kuriose jie pasikartoja:\n";
    outputFile << "-------------------------------------------\n";

    for (const auto& it : wordLines) {
        if (wordCounts.at(it.first) > 1) {
            outputFile << std::left << std::setw(20)
                << originalWords.at(it.first) << "| ";
            for (const auto& line : it.second) {
                outputFile << line << " ";
            }
            outputFile << "\n";
        }
    }

    outputFile.close();
}

void findURLs(const std::string& filename, std::set<std::string>& urls) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Nepavyko atidaryti failo: " << filename << std::endl;
        return;
    }

    std::string line;
    std::regex urlRegex(R"((https?://[\w\.-]+|www\.[\w\.-]+|\b[a-zA-Z0-9-]+\.[a-z]{2,}\b))");

    while (std::getline(file, line)) {
        std::sregex_iterator begin(line.begin(), line.end(), urlRegex), end;
        for (auto it = begin; it != end; ++it) {
            urls.insert(it->str());
        }
    }

    file.close();
}

void showMenu() {
    std::cout << "Pasirinkite uzduoti:\n";
    std::cout << "1. Suskaiciuoti, kiek kartu kiekvienas skirtingas zodis pasikartoja\n";
    std::cout << "2. Cross reference lentele\n";
    std::cout << "3. Rasti URL adresus tekste\n";
    std::cout << "0. Iseiti\n";
}
