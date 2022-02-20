#pragma once

#include <functional>

template <typename T>
class Property
{
public:
    Property() : m_val()
    {}

    Property(const T& val) : m_val(val)
    {}

    const T& get() const
    {
        return m_val;
    }

    void set(const T& val)
    {
        m_val = val;
        if (m_set_clbk)
        {
            m_set_clbk();
        }
    }

    void set_set_clbk(std::function<void()> clbk)
    {
        m_set_clbk = clbk;
    }

private:
    T m_val;

    std::function<void()> m_set_clbk;
};
