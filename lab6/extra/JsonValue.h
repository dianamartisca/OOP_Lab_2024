#include<ostream>

class JsonValue {
public:
    virtual ~JsonValue() = 0;
    virtual void print(std::ostream& out) = 0;
};

class NullValue :public JsonValue
{
private:
    char null;
public:
    NullValue();
    ~NullValue();
    void print(std::ostream& out);
};

class NumberValue :public JsonValue
{
private:
    int nr;
public:
    NumberValue(int x);
    ~NumberValue();
    void print(std::ostream& out);
};

class BoolValue :public JsonValue
{
private:
    bool b;
public:
    BoolValue(bool a);
    ~BoolValue();
    void print(std::ostream& out);
};

class StringValue :public JsonValue
{
private:
    char *s;
public:
    StringValue(const char* str);
    ~StringValue();
    void print(std::ostream& out);
};

class ArrayValue :public JsonValue
{
private:
    JsonValue** v;
    unsigned int elem;
public:
    ArrayValue();
    ~ArrayValue();
    void print(std::ostream& out);
    void add(JsonValue* x);
    operator unsigned();
};

class ObjectValue :public JsonValue
{
private:
    std::pair <char*, JsonValue*> *pair_array;
    unsigned int objs;
public:
    ObjectValue();
    ~ObjectValue();
    void print(std::ostream& out);
    void add(const char *str, JsonValue* x);
    operator unsigned();
};

