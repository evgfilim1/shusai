// Copyright (c) 2017 Evgeniy Filimonov (evgfilim1@yandex.ru)
// Licensed under the GPLv3 license as published by Free Software Foundation.
// https://www.gnu.org/licenses/gpl-3.0-standalone.html

#pragma once

#include "CheckListTask.h"
#include <map>
#include <stdexcept>
#include <string>

class CheckList {
public:
    CheckList() = default;
    ~CheckList() = default;

    using ContainerType = std::map<int, CheckListTask>;
    using string = std::string;

    int index(const string caption, const bool checked) const;
    int index(const CheckListTask& task) const;

    std::size_t count() const { return this->m_data.size(); }

    CheckListTask& at(int idx) { return this->m_data.at(idx); }
    const CheckListTask& at(int idx) const { return this->m_data.at(idx); }

    void add(const int id, const CheckListTask& task);
    void add(const int id, const string& caption, const bool checked = false);

    // TODO: addReplace(int, CheckListTask)

    ContainerType& data() { return this->m_data; }
    const ContainerType& data() const { return this->m_data; }

    CheckListTask pop(int idx);

    void remove(int idx) { this->m_data.erase(idx); }

    CheckListTask& operator[](int idx) { return this->at(idx); }
    const CheckListTask& operator[](int idx) const { return this->at(idx); }

    // TODO: range-based `for`

private:
    ContainerType m_data;
};
