#ifndef MGAOBJECT_H
#define MGAOBJECT_H

template<typename T>
class MGAObject
{
public:
    MGAObject(T obj)
    {
        _object = obj;
    }

    T GetObject()
    {
        return _object;
    }
private:
    T _object;
};


#endif // MGAOBJECT_H
