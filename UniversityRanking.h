// UniversityRanking.h
#pragma once
#include <string>

class UniversityRanking {
public:
    int worldRank;
    std::string institution;
    std::string country;
    int nationalRank;
    double score;
    int year;

    UniversityRanking(int wr, const std::string& inst, const std::string& ctry, int nr, double scr, int yr)
        : worldRank(wr), institution(inst), country(ctry), nationalRank(nr), score(scr), year(yr) {}
};
