#include "UserStorage.h"
#include<vector>

UserStorage::UserStorage() {}

UserStorage::~UserStorage() 
{
    for (int i = 0; i < users.size(); i++)
    {
        delete users[i];
    }
}

bool UserStorage::registerUser(const std::string& login, const std::string& password, const std::string& name) // ������� ������������ // ���� ����� �� true ���� ��� �� false
{
    users.push_back(new User(login, password, name));

    for (int i = 0; i < users.size()-1; i++)
    {
        if (users[i] == users[users.size() - 1])
        {
            users.pop_back();
            return false;
        }
    }

    return true;
}

int UserStorage::get_number(const std::string& login, const std::string& password)
{
    for (int i = 0; i < users.size(); i++) 
    {
        if (users[i]->get_login() == login && users[i]->get_password() == password)
        {
            return i; // ���� ������� �� ���������� ����� user'� �� �������
        }
    }
    return -1; // ���������� ��� ������
}

int UserStorage::get_number(const std::string&& login, const std::string&& password)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i]->get_login() == login && users[i]->get_password() == password)
        {
            return i; // ���� ������� �� ���������� ����� user'� �� �������
        }
    }
    return -1; // ���������� ��� ������
}

const User* UserStorage::operator[](int& i) // ���������� ������, �� ��� ��� ������� �� nullptr
{
    if (i < users.size())
        return users[i];
    return nullptr;
}
const User* UserStorage::operator[](int&& i) // ���������� ������, �� ��� ��� ������� �� nullptr
{
    if (i < users.size())
        return users[i];
    return nullptr;
}
