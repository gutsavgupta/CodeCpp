#include <MySaleData.h>
#include <MyExecption.h>
#include <iostream>
#include <string>

auto saleData::read(std::istream& inp) -> decltype(inp)
{
    inp >> _book._isbn;
    if (!inp) throw SALE_INP_ERROR;
    inp >> _book._price;
    if (!inp) throw SALE_INP_ERROR;
    inp >> _book._amount;
    if (!inp) throw SALE_INP_ERROR;
    return inp;
}

auto saleData::dump(std::ostream& out) -> decltype(out)
{
    out << "ISBN:\t" << _book._isbn
        << "\nPRICE:\t" << _book._price
        << "\nVOLUME:\t" << _book.amount << std::endl;
    if (!out) throw SALE_OUT_ERROR;
    return out;
}

auto saleData::setIsbn(const std::string& isbn) -> bool
{
    // @isbn check
    _book._isbn = isbn;
    return true;
}

auto saleData::setPrice(const double price) -> bool
{
    // @price check
    if (price > 0.0)
    {
        _book._price = price;
        return true;
    }
    return false;
}

auto saleData::setVolume(const long volume) -> bool
{
    //@ volume check
    if (volume > 0)
    {
        _book._amount = volume;
        return true;
    }
    return false;
}

auto saleData::combine(const saleData& obj) -> bool
{
    if (getIsbn() == obj.getIsbn())
    {
        _book._price    = (_book._price*_book._amount)+(obj.getPrice()*obj.getVolume());
        _book._amount   += obj.getVolume();

        if (_book._amount == 0) throw SALE_ART_ERROR;
        else _book._price /= _book._amount;
        return true;
    }
    return false;
}
