/*************************************************************************
 * Copyright (c) 2013 eProsima. All rights reserved.
 *
 * This generated file is licensed to you under the terms described in the
 * _LICENSE file included in this  distribution.
 *
 *************************************************************************
 * 
 * @file Simple.h
 * This header file contains the declaration of the described types in the IDL file.
 *
 * This file was generated by the tool gen.
 */

#ifndef _Simple_H_
#define _Simple_H_

// TODO Poner en el contexto.

#include <stdint.h>
#include <array>
#include <string>
#include <vector>

#if defined(_WIN32)
#if defined(EPROSIMA_USER_DLL_EXPORT)
#define eProsima_user_DllExport __declspec( dllexport )
#else
#define eProsima_user_DllExport
#endif
#else
#define eProsima_user_DllExport
#endif

namespace eprosima
{
    namespace fastcdr
    {
        class Cdr;
    }
}


/*!
 * @brief This class represents the structure SimpleStruct defined by the user in the IDL file.
 * @ingroup SIMPLE
 */
class eProsima_user_DllExport SimpleStruct
{
public:

    /*!
     * @brief Default constructor.
     */
    SimpleStruct();
    
    /*!
     * @brief Default destructor.
     */
    ~SimpleStruct();
    
    /*!
     * @brief Copy constructor.
     * @param x Reference to the object SimpleStruct that will be copied.
     */
    SimpleStruct(const SimpleStruct &x);
    
    /*!
     * @brief Move constructor.
     * @param x Reference to the object SimpleStruct that will be copied.
     */
    SimpleStruct(SimpleStruct &&x);
    
    /*!
     * @brief Copy assignment.
     * @param x Reference to the object SimpleStruct that will be copied.
     */
    SimpleStruct& operator=(const SimpleStruct &x);
    
    /*!
     * @brief Move assignment.
     * @param x Reference to the object SimpleStruct that will be copied.
     */
    SimpleStruct& operator=(SimpleStruct &&x);
    
    /*!
     * @brief This function sets a value in member myString
     * @param _myString New value for member myString
     */
    inline void myString(std::string _myString)
    {
        m_myString = _myString;
    }

    /*!
     * @brief This function returns the value of member myString
     * @return Value of member myString
     */
    inline std::string myString() const
    {
        return m_myString;
    }

    /*!
     * @brief This function returns a reference to member myString
     * @return Reference to member myString
     */
    inline std::string& myString()
    {
        return m_myString;
    }
    
    /*!
     * @brief This function returns the maximum serialized size of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    static size_t getMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function returns the maximum serialized size of the Key of an object
     * depending on the buffer alignment.
     * @param current_alignment Buffer alignment.
     * @return Maximum serialized size.
     */
    static size_t getKeyMaxCdrSerializedSize(size_t current_alignment = 0);

    /*!
     * @brief This function tells you if the Key has beedn defined for this type
     */
    static bool isKeyDefined();

    /*!
     * @brief This function serializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void serialize(eprosima::fastcdr::Cdr &cdr) const;

    /*!
     * @brief This function deserializes an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void deserialize(eprosima::fastcdr::Cdr &cdr);

    /*!
     * @brief This function serializes the key memebers of an object using CDR serialization.
     * @param cdr CDR serialization object.
     */
    void serializeKey(eprosima::fastcdr::Cdr &cdr) const;

    
private:
    std::string m_myString;
};

#endif // _Simple_H_