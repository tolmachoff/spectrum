#pragma once


class RW {};

class RO {};


template <typename Mode, typename T>
class Property;


template <typename T>
class Property<RO, T>
{
public:
    Property(const T& val) : m_val(val) {}

    const T& get() const
    {
        return m_val;
    }

private:
    T m_val;
};


template <typename T>
class Property<RW, T>
{
public:
    Property(const T& val) : m_val(val) {}

    const T& get() const
    {
        return m_val;
    }

    void set(const T& val)
    {
        m_val = val;
    }
    
private:
    T m_val;
};
