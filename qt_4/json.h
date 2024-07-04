#ifndef JSON_H
#define JSON_H
#include <string>
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QMessageBox>
#include "single_include/nlohmann/json.hpp"

nlohmann::json make_json(std::string&);

bool is_empty(std::string&);
bool is_correct_extension(std::string&);
bool is_correct_structure(nlohmann::json&);
#endif
