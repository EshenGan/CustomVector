#pragma once

template <typename T>
struct TCustomVector
{
    T X;
    T Y;
    T Z;

    TCustomVector(const T& inX,const T& inY, const T& inZ);
    TCustomVector& operator=(const TCustomVector& rhs);
    TCustomVector operator+(const TCustomVector& rhs);
    TCustomVector operator-(const TCustomVector& rhs);
    TCustomVector operator*(const T& rhs);
    TCustomVector operator/(const T& rhs);
    
    static TCustomVector CrossProduct(const TCustomVector& v1, const TCustomVector& v2);
    static T DotProduct(const TCustomVector& v1, const TCustomVector& v2);
    TCustomVector Cross(const TCustomVector& V);
    T Dot(const TCustomVector& V);
    TCustomVector Normalize();
    T Size();
    
    bool operator!=(const TCustomVector& rhs);
    bool operator==(const TCustomVector& rhs);
    
};





