#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() {}
    ~IllegalBalanceException() {}

    virtual const char* what() const noexcept { return "Illegal balance exception"; }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
