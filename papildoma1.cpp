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

using namespace std;

int main() {
    const std::string inputFilename = "input.txt";
    const std::string wordCountFile = "zodziu_skaicius.txt";
    const std::string crossReferenceFile = "cross_reference_lentele.txt";
    int choice;

    std::map<std::string, int> wordCounts;
    std::map<std::string, std::set<int>> wordLines;
    std::map<std::string, std::string> originalWords;
    std::set<std::string> urls;

    do {
        showMenu();
        std::cout << "Iveskite pasirinkima (0-3): ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            countWordsAndLines(inputFilename, wordCounts, wordLines, originalWords);
            writeWordCounts(wordCountFile, wordCounts, originalWords);
            std::cout << "Zodziai ir ju pasikartojimai isvesti i faila " << wordCountFile << std::endl;
            break;

        case 2:
            if (wordLines.empty()) {
                std::cout << "Atliekama failo analize...\n";
                countWordsAndLines(inputFilename, wordCounts, wordLines, originalWords);
            }
            writeCrossReference(crossReferenceFile, wordLines, wordCounts, originalWords);
            std::cout << "Zodziai ir ju eilutes isvesti i faila " << crossReferenceFile << std::endl;
            break;

        case 3:
            findURLs(inputFilename, urls);
            std::cout << "Rasti URL'ai:\n";
            for (const auto& url : urls) {
                std::cout << url << "\n";
            }
            break;

        case 0:
            std::cout << "Programa baigia darba." << std::endl;
            break;

        default:
            std::cout << "Neteisingas pasirinkimas, bandykite dar karta." << std::endl;
            break;
        }
    } while (choice != 0);

    return 0;
}

