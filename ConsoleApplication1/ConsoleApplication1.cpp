#include <iostream>
//Karolis Mikelionis

class kompleksinis_skaičius {

    private:
        double realioji;
        double menamoji;
    public:
        kompleksinis_skaičius();
        kompleksinis_skaičius(double realioji, double menamoji);

    double getRealioji() const;
    double getMenamoji() const;
    void setRealioji(double realioji);
    void setMenamoji(double menamoji);

    // input/output operators
    friend std::ostream& operator<<(std::ostream& os, const kompleksinis_skaičius& other) {
        os << other.realioji << "r + " << other.menamoji << "i";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, kompleksinis_skaičius& other) {
        std::cout << "Enter the real part: ";
        is >> other.realioji;
        std::cout << "Enter the imaginary part: ";
        is >> other.menamoji;
        return is;
    }
   

    //Realizuokite papildomus metodus iki galimybės atlikti visus matematinius veiksmus su kompleksiniais skaičiais
    kompleksinis_skaičius operator+(const kompleksinis_skaičius& other) const;
    kompleksinis_skaičius operator-(const kompleksinis_skaičius& other) const;
    kompleksinis_skaičius operator*(const kompleksinis_skaičius& other);
    kompleksinis_skaičius& operator+=(const kompleksinis_skaičius& other);
    kompleksinis_skaičius& operator-=(const kompleksinis_skaičius& other);
    kompleksinis_skaičius& operator*=(const kompleksinis_skaičius& other);
    kompleksinis_skaičius& operator++(int);
    kompleksinis_skaičius& operator--(int);

};

    kompleksinis_skaičius::kompleksinis_skaičius() : realioji(0), menamoji(0) {};//konstruktorius_pagal_nutylėjimą;

    kompleksinis_skaičius::kompleksinis_skaičius(double realioji, double menamoji) : realioji(realioji), menamoji(menamoji) {};//parametrizuotas_konstruktorius;

    double kompleksinis_skaičius::getRealioji() const {
        return realioji;
    }

    double kompleksinis_skaičius::getMenamoji() const {
        return menamoji;
    }

    void kompleksinis_skaičius::setRealioji(double realioji) {
        this->realioji = realioji;
    }

    void kompleksinis_skaičius::setMenamoji(double menamoji) {
        this->menamoji = menamoji;
    }

    //Realizuokite papildomus metodus iki galimybės atlikti visus matematinius veiksmus su kompleksiniais skaičiais

    kompleksinis_skaičius kompleksinis_skaičius::operator+(const kompleksinis_skaičius & other) const {
        return { realioji + other.realioji, menamoji + other.menamoji };
    }

    kompleksinis_skaičius kompleksinis_skaičius::operator-(const kompleksinis_skaičius & other) const {
        return { realioji - other.realioji, menamoji - other.menamoji };
    }

    kompleksinis_skaičius kompleksinis_skaičius::operator*(const kompleksinis_skaičius & other) {
        realioji = realioji * other.realioji;
        menamoji = menamoji * other.menamoji;
        return *this;
    }

    kompleksinis_skaičius& kompleksinis_skaičius::operator+=(const kompleksinis_skaičius & other) {
        realioji += other.realioji;
        menamoji += other.menamoji;
        return *this;
    }

    kompleksinis_skaičius& kompleksinis_skaičius::operator-=(const kompleksinis_skaičius & other) {
        realioji -= other.realioji;
        menamoji -= other.menamoji;
        return *this;
    }

    kompleksinis_skaičius& kompleksinis_skaičius::operator*=(const kompleksinis_skaičius & other) {
        realioji *= other.realioji;
        menamoji *= other.menamoji;
        return *this;
    }
    kompleksinis_skaičius& kompleksinis_skaičius::operator++(int) {
        realioji++;
        menamoji++;
        return *this;
    }
    kompleksinis_skaičius& kompleksinis_skaičius::operator--(int) {
        realioji--;
        menamoji--;
        return *this;
    }

//-----------------------------------------------------

    int main()
    {
        // demonstration of usage
        kompleksinis_skaičius x(3, 4);
        kompleksinis_skaičius y(1, 2);
        std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "First Part" << std::endl;

        auto sum1 = x + y;
        std::cout << "x + y = " << sum1 << std::endl;

        auto difference1 = x - y;
        std::cout << "x - y = " << difference1 << std::endl;

        auto product1 = x * y;

        std::cout << "x * y = " << product1 << std::endl;

        std::cout << "Second Part"<< std::endl;

        std::cout<<"Enter X Values: "<<std::endl;
        std::cin >> x;
        x += y;
        std::cout << "x += y: " << x << std::endl;
        std::cout << "Enter X Values: " << std::endl;
        std::cin >> x;
        x -= y;
        std::cout << "x -= y: " << x << std::endl;
        std::cout << "Enter X Values: " << std::endl;
        std::cin >> x;
        x *= y;
        std::cout << "x *= y: " << x << std::endl;

        std::cout << "Third Part" << std::endl;

        std::cout << "Enter X Values: " << std::endl;
        std::cin >> x;
        std::cout << "x = " << x << std::endl;

        auto incremented = x++;
        std::cout << "++x: " << incremented << std::endl;

        auto decremented = x--;
        std::cout << "--x: " << decremented << std::endl;

        return 0;
    }