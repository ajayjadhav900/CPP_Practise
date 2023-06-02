/*
 Vehicle company - > Tata / Mahindra -> Car and truck
*/

class Icar
{
    public:
    void virtual GetCar() = 0;
};
class Itruck
{
    public:
    void virtual GetTruck() = 0;
};

class TataCar:public Icar
{
    public:
    void GetCar();
};
class TataTruck : public Itruck
{
    public:
    void GetTruck();
};

class MahindraCar :public Icar
{
    public:
    void GetCar();
};

class MahindraTruck:public Itruck
{
    public:
    void GetTruck();
};

class IVehicleCompany
{
    public:
     virtual Icar* GetCar() = 0;
      virtual Itruck* GetTruck() = 0;
};

class tata:public IVehicleCompany
{
    public:
    Icar*  GetCar();
    Itruck* GetTruck();
};

class Mahindra:public IVehicleCompany
{
    public:
    Icar*  GetCar();
    Itruck* GetTruck();
};

