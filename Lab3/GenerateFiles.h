//
// Created by Andrew on 10/28/2018.
//

#ifndef LAB3_GENERATEFILES_H
#define LAB3_GENERATEFILES_H

#include <iostream>
#include <fstream>

class GenerateFiles {
public:
    GenerateFiles() = default;
    GenerateFiles(const std::string& output, int nodeNum);

    ~GenerateFiles() = default;
};

#endif //LAB3_GENERATEFILES_H
