#pragma once

#include <string>
#include <map>
#include <stdexcept>

class CheckListTask;

namespace CheckListTypes {

using IDType = int;
using dataType = std::map<IDType, CheckListTask>;
using string = std::string;

} // namespace CheckListTypes

class CheckListTask {
public:
    // Using `std::string` below by copy constructor is for accepting both variables and string literals
    CheckListTask(const CheckListTypes::string caption = "", const bool checked = false) :
        m_checked(checked), m_caption(caption) {}
    ~CheckListTask() = default;

    bool checked() const { return bool(*this); }

    const CheckListTypes::string& caption() const { return this->m_caption; }

    void setChecked(const bool checked) { this->m_checked = checked; }

    void setCaption(const CheckListTypes::string caption) { this->m_caption = caption; }

    // TODO: `setAttr(string, bool)`, `getAttr(string&, bool&)`

    operator bool() const { return this->m_checked; }

    inline bool operator==(const CheckListTask& rhs) const {
        return (this->caption() == rhs.caption() && this->checked() == rhs.checked());
    }

private:
    bool m_checked;
    CheckListTypes::string m_caption;
    // TODO: due date
};

class CheckList {
public:
    CheckList() = default;
    ~CheckList() = default;

    CheckListTypes::IDType index(const CheckListTypes::string caption, const bool checked) const;
    CheckListTypes::IDType index(const CheckListTask& task) const;

    std::size_t count() const { return this->m_data.size(); }

    CheckListTask& at(CheckListTypes::IDType idx) { return this->m_data.at(idx); }
    const CheckListTask& at(CheckListTypes::IDType idx) const { return this->m_data.at(idx); }

    void add(const CheckListTypes::IDType id, const CheckListTask& task) { this->m_data[id] = task; }
    void add(const CheckListTypes::IDType id, const CheckListTypes::string& caption, const bool checked = false);

    CheckListTypes::dataType& data() { return this->m_data; }
    const CheckListTypes::dataType& data() const { return this->m_data; }

    CheckListTask pop(CheckListTypes::IDType idx);

    void remove(CheckListTypes::IDType idx) { this->m_data.erase(idx); }

    CheckListTask& operator[](CheckListTypes::IDType idx) { return this->at(idx); }
    const CheckListTask& operator[](CheckListTypes::IDType idx) const { return this->at(idx); }

    // TODO: range-based `for`

private:
    CheckListTypes::dataType m_data;
};
