/*
 * @Description:    SaleData class
 * @functionality:
 *
 * @Utility function
 *  >   const std::string&  isbin(void)
 *  >   std::istream&       read(std::istream& input)
 *  >   std::ostream&       dump(std::ostream& output)
 *
 * @Constructor function
 *  >   saleData()                      @ default constructor
 *  >   saleData(const saleData& obj)   @ copy constructor
 */

#ifndef _SALEDATA_
#define _SALEDATA_

#include <MyExecption.h>
#include <iostream>
#include <string>

namespace sale{

class saleData
{

public:
    
    // @public interface
    // @virtual interface
    virtual std::istream& read(std::istream& inp);
    virtual std::ostream& dump(std::ostream& out);

    // @get interface
    virtual const std::string&  getIsbn(void)   const {return _book._isbn;}
    virtual const double        getPrice(void)  const {return _book._price;}
    virtual const long          getVolume(void) const {return _book._amount;}

    // @set interface
    virtual bool setIsbn(const std::string& isbn);
    virtual bool setPrice(const double price);
    virtual bool setVolume(const long volume);
    
    // @utility function
    bool combine(const saleData& obj);

    // @class constructors
    saleData()
        :   _book(){}
    saleData(std::string isbn,
             double      price,
             long        amount)
        :   _book(isbn, price, amount){}
    saleData(const saleData& obj)
        :   _book(obj._book){}

private:
    // @execption structs
    // @throw should pick one of them
    static const exception SALE_INP_ERROR;
    static const exception SALE_OUT_ERROR;
    static const exception SALE_ART_ERROR;
    
    // @implicit data-struct
    struct book
    {
        std::string _isbn;
        double      _price;
        long        _amount;
        
        // @construct functions
        book(): _isbn(""), _price(0.0), _amount(0){}
        book(std::string& isbn, double price, long amount)
            :   _isbn(isbn),
                _price(price),
                _amount(amount){}
        book(const book& obj)
            :   _isbn(obj._isbn),
                _price(obj._price),
                _amount(obj._amount){}
    };
    
    // @main book object
    book _book;
};

} // namepsace sale

#endif
