#include "Catalog.hpp"

Catalog::Catalog()
{
}

void Catalog::AddProductsInCatalog(Product *product)
{
    ProductNames[product->GetProductName()].push_back(*product);
}

std::list<Product> &Catalog::SearchTheProductsByName(std::string pr)
{
    auto itr = ProductNames.find(pr);

    if (itr != ProductNames.end() && !itr->second.empty())
    {
        return ProductNames[pr];
    }

    static std::list<Product> emptyList;
    return emptyList;
}
