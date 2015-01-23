#ifndef __XPFSerivce_Data_h__
#define __XPFSerivce_Data_h__

#include "XPFDefine.h"
#include <string>
#include <vector>
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

NS_XPF_BEGIN

class Data {
public:
    enum Mode {
        ARRAY,
        OBJECT
    };
    Data(const char * json, Mode mode = OBJECT);
    Data(Data && data) noexcept ;
    Data(std::vector<Data> && dataArray);
    Data(rapidjson::Value && value);
    
    //Object
    void set(const char * key, int value);
    void set(const char * key, std::size_t value);
    void set(const char * key, time_t value);
    void set(const char * key, bool value);
    void set(const char * key, const char * value);
    int getInt(const char * key) const ;
    bool getBool(const char * key) const ;
    std::size_t getSizeT(const char * key) const ;
    const char * getString(const char * key) const ;
    std::string getObjectJson(const char * key) const ;
    
    //Array
    void pushBack(Data && data);
    void popBack();
    
    std::string getObjectJson(int index) const;
    
    bool isEmpty() const;
    size_t getSize() const;
    
    std::string getJson();
    Mode getMode() const;
    
    Data & operator= (Data && data);
protected:
    rapidjson::Document _document;
private:
    Mode _mode;
};

NS_XPF_END

#endif