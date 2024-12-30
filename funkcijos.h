#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <vector>
#include <string>
#include <map>
#include <set>

void countWordsAndLines(const std::string& filename, std::map<std::string, int>& wordCounts, std::map<std::string, std::set<int>>& wordLines, std::map<std::string, std::string>& originalWords);
void writeWordCounts(const std::string& outputFilename, const std::map<std::string, int>& wordCounts, const std::map<std::string, std::string>& originalWords);
void writeCrossReference(const std::string& outputFilename, const std::map<std::string, std::set<int>>& wordLines, const std::map<std::string, int>& wordCounts, const std::map<std::string, std::string>& originalWords);
void findURLs(const std::string& filename, std::set<std::string>& urls);
void showMenu();

#endif
