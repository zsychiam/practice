#include "forjson.h"

nlohmann::json make_json(std::string& filename)
{
    if(!is_empty(filename))
    {
        if(is_correct_extension(filename))
        {
            std::ifstream in(filename);
            if(in.is_open())
            {
                nlohmann::json file = nlohmann::json::parse(in);
                in.close();
                if(is_correct_structure(file))
                    return file;
                else
                    QMessageBox::information(nullptr, "error", "Problem with structure!");
            }
            else
                QMessageBox::information(nullptr, "error", "Cannot open .json file!");
        }
        else
            QMessageBox::information(nullptr, "error", "Wrong extension!");
    }
    else
        QMessageBox::information(nullptr, "error", "Empty file name!");
    nlohmann::json Empty;
    return Empty;
}

bool is_empty(std::string& filename)
{
    return filename.empty();
}

bool is_correct_extension(std::string &filename)
{
    int dot = filename.find_last_of(".");
    return filename.substr(dot+1) == "json";
}

bool is_correct_structure(nlohmann::json& file)
{
    if(file.is_array())
    {
        if(!file.empty())
            for (nlohmann::json::iterator it = file.begin(); it != file.end(); ++it)
                if(!it->is_number_integer())
                {
                    QMessageBox::information(nullptr, "error", "File has not only .int elements!");
                    return false;
                }
        else
        {
            QMessageBox::information(nullptr, "error", "File is empty!");
            return false;
        }
    }
    else
    {
        QMessageBox::information(nullptr, "error", "File is not an array!");
        return false;
    }
    return true;
}