/* This example is to glean literal concepts in c++
 * We will see how literal logic works which literals
 * are of which type by default and what shall be done
 * to change literal type while assigning them to some
 * variable 
 * 
 * Note: there is some suffix and prefix 
 * 
 * (character and string literal)
 * prefix       Meaning                 type
 * u            Unicode 16 character    char16_t
 * U            Unicode 32 character    char32_t
 * L            Wide character          wchar_t
 * u8           utf-8(string literal)   char
 * 
 * Integer literal
 * suffix           Minimum type
 * u or U           unsigned
 * l or L           long
 * ll or LL         long long
 * 
 * Floating point literal
 * suffix           Type
 * f or F           float
 * l or L           long double
 * 
 * pointer literals
 * nullptr (not same as NULL)
 * 
 * bool literals
 * 1. true
 * 2. fals
 * 
 * Note: for Integer Minumum Type concept exist
 * for floating point it doesn't, if range exceed it prints inf 
*/