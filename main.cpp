// main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "UniversityRanking.h"

int main() {
    std::ifstream file("university_data.csv");
    std::string line;
    std::vector<UniversityRanking> rankings;
    int lineCount = 0, validCount = 0;

    if (!file.is_open()) {
        std::cerr << "Failed to open CSV file.\n";
        return 1;
    }

    std::getline(file, line); // Skip header

    while (std::getline(file, line)) {
        lineCount++;
        std::stringstream ss(line);
        std::string token;
        std::vector<std::string> tokens;

        bool inQuotes = false;
        std::string currentField;

        // Properly handle quotes and commas
        for (char ch : line) {
            if (ch == '"') {
                inQuotes = !inQuotes;
            } else if (ch == ',' && !inQuotes) {
                tokens.push_back(currentField);
                currentField.clear();
            } else {
                currentField += ch;
            }
        }
        tokens.push_back(currentField); // add last field

        try {
            if (tokens.size() < 14)
                throw std::runtime_error("Line has insufficient fields.");

            int worldRank = std::stoi(tokens[0]);
            std::string institution = tokens[1];
            std::string country = tokens[2];
            int nationalRank = std::stoi(tokens[3]);
            double score = std::stod(tokens[12]);
            int year = std::stoi(tokens[13]);

            UniversityRanking ur(worldRank, institution, country, nationalRank, score, year);
            rankings.push_back(ur);
            validCount++;
        } catch (const std::exception& e) {
            std::cerr << "Error parsing line " << lineCount + 1 << ": " << e.what() << "\n";
        }
    }

    std::cout << "Total lines read: " << lineCount << "\n";
    std::cout << "Valid records parsed: " << validCount << "\n";
    std::cout << "First 3 valid universities:\n";

    for (size_t i = 0; i < std::min(rankings.size(), size_t(3)); ++i) {
        std::cout << rankings[i].worldRank << ": " << rankings[i].institution << " (" << rankings[i].country
                  << ") - Score: " << rankings[i].score << ", Year: " << rankings[i].year << "\n";
    }

    return 0;
}
