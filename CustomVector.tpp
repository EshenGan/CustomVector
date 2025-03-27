#include "CustomVector.h"
#include <math.h>


template <typename T>
TCustomVector<T>::TCustomVector(const T& inX, const T& inY, const T& inZ)
    : X(inX), Y(inY), Z(inZ)
{
}

template <typename T>
TCustomVector<T>& TCustomVector<T>::operator=(const TCustomVector& rhs)
{
    X = rhs.X;
    Y = rhs.Y;
    Z = rhs.Z;

    return *this;
}

template <typename T>
TCustomVector<T> TCustomVector<T>::operator+(const TCustomVector& rhs)
{
    return TCustomVector<T>(X + rhs.X, Y + rhs.Y, Z + rhs.Z);
}

template <typename T>
TCustomVector<T> TCustomVector<T>::operator-(const TCustomVector& rhs)
{
    return TCustomVector<T>(X - rhs.X, Y - rhs.Y, Z - rhs.Z);
}

template <typename T>
TCustomVector<T> TCustomVector<T>::operator*(const T& rhs)
{
    // Named Return Value Optimization if I do it this way  - there is a chance that compiler would make a copy 
    // TCustomVector<T> customVec;
    //
    // customVec.X = this.X * rhs;
    // customVec.Y = this.Y * rhs;
    // customVec.Z = this.Z * rhs;
    //
    // return customVec;

    // Return Value Optimization if I do it this way - usually the better way - compiler wont make a copy
    return TCustomVector<T> (X * rhs, Y * rhs, Z * rhs);
}

template <typename T>
TCustomVector<T> TCustomVector<T>::operator/(const T& rhs)
{
    return  TCustomVector<T>(X / rhs, Y / rhs, Z / rhs);
}

template <typename T>
TCustomVector<T> TCustomVector<T>::CrossProduct(const TCustomVector& v1, const TCustomVector& v2)
{
    return TCustomVector<T>
    (
        v1.Y * v2.Z - v2.Y * v1.Z,
        (v1.X * v2.Z - v2.X * v1.Z),
        v1.X * v2.Y - v2.X * v1.Y
    );  
}

template <typename T>
TCustomVector<T> TCustomVector<T>::Cross(const TCustomVector& V)
{
    return CrossProduct(*this,V);
}


template <typename T>
T TCustomVector<T>::DotProduct(const TCustomVector& v1, const TCustomVector& v2)
{
    return v1.X * v2.X + v1.Y * v2.Y + v1.Z * v2.Z;
}

template <typename T>
T TCustomVector<T>::Dot(const TCustomVector& V)
{
    return DotProduct(*this, V);
}

template <typename T>
T TCustomVector<T>::Size()
{
    return static_cast<T>(sqrt(X * X + Y * Y + Z * Z));
}

template <typename T>
TCustomVector<T> TCustomVector<T>::Normalize()
{
    // pythagoras theorem
    const T squareSum = X * X + Y * Y + Z * Z;

    // is the square sum is 1 it means vector has already been normalized
    if (squareSum == 1.f)
    {
        return *this;
        
    }

    return TCustomVector<T> ( X / Size(), Y / Size(), Z / Size());
}

template <typename T>
bool TCustomVector<T>::operator!=(const TCustomVector& rhs)
{
    return (X != rhs.X) && (Y != rhs.Y) && (Z != rhs.Z);
}

template <typename T>
bool TCustomVector<T>::operator==(const TCustomVector& rhs)
{
    return (X == rhs.X) && (Y == rhs.Y) && (Z == rhs.Z);
}
