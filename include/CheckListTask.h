// Copyright (c) 2017 Evgeniy Filimonov (evgfilim1@yandex.ru)
// Licensed under the GPLv3 license as published by Free Software Foundation.
// https://www.gnu.org/licenses/gpl-3.0-standalone.html

#pragma once

#include <string>

class CheckListTask {
public:
    using string = std::string;

    // Using `string` below by copy constructor is for accepting both variables and string literals
    CheckListTask(const string caption = "", const bool checked = false) :
        m_checked(checked), m_caption(caption) {}
    ~CheckListTask() = default;

    bool checked() const { return bool(*this); }

    const string& caption() const { return this->m_caption; }

    void setChecked(const bool checked) { this->m_checked = checked; }

    void setCaption(const string caption) { this->m_caption = caption; }

    // TODO: `setAttr(string, bool)`, `getAttr(string&, bool&)`

    operator bool() const { return this->m_checked; }

    inline bool operator==(const CheckListTask& rhs) const {
        return (this->caption() == rhs.caption() && this->checked() == rhs.checked());
    }

    inline bool operator!=(const CheckListTask& rhs) const {
        return !(*this == rhs);
    }

private:
    bool m_checked;
    string m_caption;
    // TODO: due date
};
