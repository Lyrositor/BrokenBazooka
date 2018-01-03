#ifndef PROJECT_H
#define PROJECT_H

#include <string>

class Project {
public:
    Project(std::string const &projectPath);

    Project(std::string const &romPath, std::string const &projectPath);

    virtual ~Project();
};

#endif // PROJECT_H
