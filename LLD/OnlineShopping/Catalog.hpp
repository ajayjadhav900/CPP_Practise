#include <map>
#include <string>
#include <list>

#include "Product.hpp"
class Catalog
{
    std::map<const std::string, std::list<Product>> ProductNames;

public:
    Catalog();
    void AddProductsInCatalog(Product *);
    std::list<Product> &SearchTheProductsByName(std::string pr);
};