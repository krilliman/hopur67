#include "alegg.h"



alegg::alegg()
{
    name =  " ";
    priceLarge = " ";
    priceMiddle = " ";
    priceLittle = " ";
}

string alegg::getName()
{
    return this->name;
}

string alegg::getPriceSmall()
{
    return this->priceLittle;
}
string alegg::getPriceMedium()
{
    return this->priceMiddle;
}
string alegg::getPriceLarge()
{
    return this->priceLarge;
}

void alegg::setName(string name)
{
    this->name = name;
}
void alegg::setPriceSmall(string priceLittle)
{
    this->priceLittle = priceLittle;
}
void alegg::setPriceMiddle(string priceMiddle)
{
    this->priceMiddle = priceMiddle;
}
void alegg::setPriceLarge(string priceLarge)
{
    this->priceLarge = priceLarge;
}
void alegg::writeAlegg(ofstream &fout)
{


    int aleggNameLength = name.length()+1;
    int aleggPriceLittleLength = priceLittle.length()+1;
    int aleggPriceMiddleLength = priceMiddle.length()+1;
    int aleggPriceLargeLength = priceLarge.length()+1;

    fout.write((char*)(&aleggNameLength), sizeof(aleggNameLength));
    fout.write(name.c_str(),aleggNameLength);

    fout.write((char*)(&aleggPriceLittleLength), sizeof(aleggPriceLittleLength));
    fout.write(priceLittle.c_str(),aleggPriceLittleLength);

    fout.write((char*)(&aleggPriceMiddleLength), sizeof(aleggPriceMiddleLength));
    fout.write(priceMiddle.c_str(),aleggPriceMiddleLength);

    fout.write((char*)(&aleggPriceLargeLength), sizeof(aleggPriceLargeLength));
    fout.write(priceLarge.c_str(),aleggPriceLargeLength);
}
void alegg::readAlegg(istream &fin)
{
        int aleggNameLength;
        fin.read((char*)(&aleggNameLength), sizeof(aleggNameLength));
        char *str11 = new char[aleggNameLength];
        fin.read(str11,aleggNameLength);

        string aleggName = str11;
        setName(aleggName);


        int aleggPriceLittleLength;
        fin.read((char*)(&aleggPriceLittleLength), sizeof(aleggPriceLittleLength));
        char *str22 = new char[aleggPriceLittleLength];
        fin.read(str22,aleggPriceLittleLength);

        string aleggPriceLittle = str22;
        setPriceSmall(aleggPriceLittle);


        int aleggPriceMiddleLength;
        fin.read((char*)(&aleggPriceMiddleLength), sizeof(aleggPriceMiddleLength));
        char *str33 = new char[aleggPriceMiddleLength];
        fin.read(str33,aleggPriceMiddleLength);

        string aleggPriceMiddle = str33;
        setPriceMiddle(aleggPriceMiddle);


        int aleggPriceLargeLength;
        fin.read((char*)(&aleggPriceLargeLength), sizeof(aleggPriceLargeLength));
        char *str44 = new char[aleggPriceLargeLength];
        fin.read(str44,aleggPriceLargeLength);

        string aleggPriceLarge = str44;
        setPriceLarge(aleggPriceLarge);
}


istream& operator >> (istream& in, alegg& nyttalegg)
{

    cout << "Name Of Topping: ";
    in >> ws;
    getline(in,nyttalegg.name);

    cout << "Price Little: ";
    in >> nyttalegg.priceLittle;

    cout << "Price Middle: ";
    in >> nyttalegg.priceMiddle;

    cout << "Price Big: ";
    in >> nyttalegg.priceLarge;

    return in;

}
ostream& operator << (ostream& out, const alegg skrifalegg)
{

    cout << "Topping name: ";
    out << skrifalegg.name << endl;

    cout << "Price Little: ";
    out << skrifalegg.priceLittle << endl;

    cout << "Price Middle : ";
    out << skrifalegg.priceMiddle << endl;


    cout << "Price Big: ";
    out << skrifalegg.priceLarge << endl;


    return out;
}
